#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  double kWh, finalBill;
  double kWh100, kWh200, kWh300, kWh300P;

  cout << "Enter the total kWh consumption: ";
  cin >> kWh;

  cout << fixed << setprecision(2);

  if (kWh >= 0 && kWh <= 100) {
    kWh100 = kWh * 11.50;
    finalBill = kWh100;
    cout << "Your total bill is: ₱" << finalBill << endl;
  } else if (kWh >= 101 && kWh <= 200) {
    kWh100 = 100 * 11.50;
    kWh200 = (kWh - 100) * 12.50;
    finalBill = kWh100 + kWh200;
    cout << "Your total bill is: ₱" << finalBill << endl;
  } else if (kWh >= 201 && kWh <= 300) {
    kWh100 = 100 * 11.50;
    kWh200 = 100 * 12.50;
    kWh300 = (kWh - 200) * 13.50;
    finalBill = kWh100 + kWh200 + kWh300;
    cout << "Your total bill is: ₱" << finalBill << endl;
  } else if (kWh > 300) {
    kWh100 = 100 * 11.50;
    kWh200 = 100 * 12.50;
    kWh300 = 100 * 13.50;
    kWh300P = (kWh - 300) * 14.50;
    finalBill = kWh100 + kWh200 + kWh300 + kWh300P;
    cout << "Your total bill is: ₱" << finalBill << endl;
  } else {
    cout << "Invalid input! Consumption cannot be negative.";
  }

  return 0;
}
