#include "FuelLog.h"

class MainMenu {
public:
  void displayMenu() {
    cout << endl;
    cout << "+---------------------------------+\n"
         << "| VEHICLE FUEL EFFICIENCY TRACKER |\n"
         << "|---------------------------------|\n"
         << "| [1] Enter Fuel Entry            |\n"
         << "| [2] Remove Fuel Entry           |\n"
         << "| [3] Generate Expense Report     |\n"
         << "| [4] Calculate Fuel Efficiency   |\n"
         << "|---------------------------------|\n"
         << "| [0] Exit Program                |\n"
         << "+---------------------------------+\n";
  }

  void run() {
    int choice;
    do {
      displayMenu();
      cout << "Enter Menu Option (0-4): ";
      cin >> choice;
      cin.ignore();

      switch (choice) {
      case 0:
        cout << "Exiting program.";
        break;
      case 1:
        system("clear");
        fuelEntryManager.AddFuelEntry();
        break;
      case 2:
        system("clear");
        fuelEntryManager.RemoveFuelEntry();
        break;
      case 3:
        system("clear");
        fuelEntryManager.GenerateReport();
        break;
      case 4:
        system("clear");
        fuelEntryManager.CalculateEfficiency();
        break;
      }
    } while (choice != 0);
  }

private:
  FuelEntryManager fuelEntryManager;
};

int main(int argc, char *argv[]) {

  system("clear");
  MainMenu menu;
  menu.run();

  return 0;
}
