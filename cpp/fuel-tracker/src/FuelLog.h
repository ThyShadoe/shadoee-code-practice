#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

// TODO: Add comments to better explain things
// TODO: Test if AddFuelEntry is functional
// TODO: Add function for RemoveFuelEntry()
// TODO: Add function for GenerateReport()
// TODO: Add function for CalculateEfficiency()

using namespace std;

enum class FuelType { GASOLINE, DIESEL, ELECTRIC, HYBRID };

class FuelEntry {
public:
  // Constructor
  FuelEntry(const string &entryDate, double odometer, double amount,
            double price, FuelType type)
      : date(entryDate), odometerReading(odometer), fuelAmount(amount),
        fuelPrice(price), fuelType(type) {}

  // Getters
  string getDate() const { return date; }
  double getOdometerReading() const { return odometerReading; }
  double getFuelAmount() const { return fuelAmount; }
  double getFuelPrice() const { return fuelPrice; }
  FuelType getFuelType() const { return fuelType; }

  // Function to return a string for fuel type
  string getFuelTypeString() const {
    switch (fuelType) {
    case FuelType::GASOLINE:
      return "Gasoline";
    case FuelType::DIESEL:
      return "Diesel";
    case FuelType::ELECTRIC:
      return "Electric";
    case FuelType::HYBRID:
      return "Hybrid";
    }
  }

  void displayEntry() {
    // Set decimal precision to 2
    cout << fixed << setprecision(2);
    cout << "+---------------------------------+\n"
         << "| [ DATE        ]\t" << date << endl
         << "| [ ODOMETER    ]\t" << odometerReading << endl
         << "| [ FUEL AMOUNT ]\t" << fuelAmount << endl
         << "| [ FUEL PRICE  ]\t" << fuelPrice << endl
         << "| [ FUEL TYPE   ]\t" << getFuelTypeString() << endl
         << "+---------------------------------+\n";
  }

private:
  string date;
  double odometerReading;
  double fuelAmount;
  double fuelPrice;
  FuelType fuelType;
};

class FuelEntryManager {
public:
  bool isValidDate(const string &date) {
    // Check overall format (YYYY-MM-DD)
    if (date.length() != 10)
      return false;

    // Check separator positions
    if (date[4] != '-' || date[7] != '-')
      return false;

    // Check if all other characters are digits
    for (int i : {0, 1, 2, 3, 5, 6, 8, 9}) {
      if (!isdigit(date[i]))
        return false;
    }

    // Parse year, month, day
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    // Validate month range
    if (month < 1 || month > 12)
      return false;

    // Days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leap year calculation
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      // Adjust February for leap year
      daysInMonth[2] = 29;
    }

    // Validate day range
    if (day < 1 || day > daysInMonth[month])
      return false;

    return true;
  }

  void AddFuelEntry() {
    string date;
    double odometerReading, fuelAmount, fuelPrice;
    int choice, fuelTypeChoice;

    do {
      cout << "+---------------------------------+\n"
           << "| ADD NEW FUEL ENTRY?             |\n"
           << "|---------------------------------|\n"
           << "| [1] Continue                    |\n"
           << "| [0] Go Back                     |\n"
           << "+---------------------------------+\n";
      cout << "Enter Menu Option: ";
      cin >> choice;
      cin.ignore();

      if (choice == 0) {
        return;
      } else if (choice == 1) {

        while (true) {
          cout << "Enter date (YYYY-MM-DD): ";
          getline(cin, date);
          if (isValidDate(date))
            break;
          cout << "Invalid date format: Try again.\n";
        }

        cout << "Enter odometer reading (km): ";
        cin >> odometerReading;

        cout << "Enter fuel amount (liters) : ";
        cin >> fuelAmount;

        cout << "Enter fuel price ($/liter) : ";
        cin >> fuelPrice;

        cout << "Select Fuel Type:\n"
             << "1. Gasoline\n"
             << "2. Diesel\n"
             << "3. Electric\n"
             << "4. Hybrid\n"
             << "Enter choice (1-4): ";
        cin >> fuelTypeChoice;
        cin.ignore();

        FuelType fuelType;
        switch (fuelTypeChoice) {
        case 1:
          fuelType = FuelType::GASOLINE;
          break;
        case 2:
          fuelType = FuelType::DIESEL;
          break;
        case 3:
          fuelType = FuelType::ELECTRIC;
          break;
        case 4:
          fuelType = FuelType::HYBRID;
          break;
        default:
          cout << "Invalid option: Defaulting to Gasoline.\n";
          fuelType = FuelType::GASOLINE;
          break;
        }

        entries.emplace_back(date, odometerReading, fuelAmount, fuelPrice,
                             fuelType);
        cout << "Fuel Entry was added successfully!\n";
      }
    } while (choice != 0);
  }
  void RemoveFuelEntry() {}
  void GenerateReport() {}
  void CalculateEfficiency() {}

private:
  vector<FuelEntry> entries;
};
