#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  const double PRICE_100 = 11.50, PRICE_200 = 12.50, PRICE_300 = 13.50,
               PRICE_300P = 14.50;
  double totalkWh, totalBill;
  double kWh100, kWh200, kWh300, kWh300P;
  string currency = "₱";

  cout << "Enter the total kWh consumption: ";
  cin >> totalkWh;

  cout << fixed << setprecision(2);

  if (totalkWh < 0) {
    cout << "Invalid input! Consumption cannot be negative.";
  } else {

    if (totalkWh >= 0 && totalkWh <= 100) {
      kWh100 = totalkWh * PRICE_100;
      totalBill = kWh100;
      cout << "Your total bill is: " << currency << totalBill << endl;

    } else if (totalkWh > 100 && totalkWh <= 200) {
      kWh100 = 100 * PRICE_100;
      kWh200 = (totalkWh - 100) * PRICE_200;
      totalBill = kWh100 + kWh200;
      cout << "Your total bill is: " << currency << totalBill << endl;

    } else if (totalkWh > 200 && totalkWh <= 300) {
      kWh100 = 100 * PRICE_100;
      kWh200 = 100 * PRICE_200;
      kWh300 = (totalkWh - 200) * PRICE_300;
      totalBill = kWh100 + kWh200 + kWh300;
      cout << "Your total bill is: " << currency << totalBill << endl;

    } else if (totalkWh > 300) {
      kWh100 = 100 * PRICE_100;
      kWh200 = 100 * PRICE_200;
      kWh300 = 100 * PRICE_300;
      kWh300P = (totalkWh - 300) * PRICE_300P;
      totalBill = kWh100 + kWh200 + kWh300 + kWh300P;
      cout << "Your total bill is: " << currency << totalBill << endl;

    } else {
      cout << "Invalid input! Enter a valid number.";
    }
  }

  return 0;
}
