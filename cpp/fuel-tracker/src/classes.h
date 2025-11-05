#include <iostream>
#include <vector>
using namespace std;

class FuelLog {
public:
private:
};

class FuelTracker {
public:
  void displayMenu() {
    cout << endl;
    cout << "+----------------------+\n"
         << "|     FUEL TRACKER     |\n"
         << "|----------------------|\n"
         << "| [1] Enter Fuel Log   |\n"
         << "| [2] Calculate MPG    |\n"
         << "| [3] See All Logs     |\n"
         << "| [4] Configure Logs   |\n"
         << "|----------------------|\n"
         << "| [0] Exit Program     |\n"
         << "+----------------------+\n";
  }

  void AddFuelLog() {
    int choice;
    do {
      cout << endl;
      cout << "+----------------------+\n"
           << "| Enter New Fuel Log?  |\n"
           << "|----------------------|\n"
           << "| [1] Yes              |\n"
           << "| [0] Go Back          |\n"
           << "+----------------------+\n";
      cout << "Select Menu Option: ";
      cin >> choice;
      switch (choice) {
      case 1:
        system("clear");
        cout << "New Fuel Log added successfully!";
        break;
      case 0:
        system("clear");
        break;
      default:
        cout << "Invalid menu option.";
      }
    } while (choice != 0);
  }

  void run() {
    int choice;
    do {
      displayMenu();
      cout << "Select Menu Option: ";
      cin >> choice;

      switch (choice) {
      case 1:
        system("clear");
        AddFuelLog();
        break;
      case 2:
        system("clear");
        break;
      case 3:
        system("clear");
        break;
      case 4:
        system("clear");
        break;
      case 0:
        break;
      default:
        cout << "Invalid menu option.";
      }
    } while (choice != 0);
  }

private:
  vector<FuelLog> fuelLog;
};
