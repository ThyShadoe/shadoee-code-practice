#include <iomanip>
#include <iostream>
using namespace std;

double isCelsius(double temp) {
  double f, k;
  f = temp * 1.8 + 32;
  k = temp + 273.15;
  cout << "Converted to:\n";
  cout << fixed << setprecision(2);
  cout << "Fahrenheit: " << f << endl;
  cout << "Kelvin: " << k << endl;
  return 0;
}
double isFahrenheit(double temp) {
  double c, k;
  c = (temp - 32) / 1.8;
  k = c + 273.15;
  cout << "Converted to\n";
  cout << fixed << setprecision(2);
  cout << "Celsius: " << c << endl;
  cout << "Kelvin: " << k << endl;

  return 0;
}
double isKelvin(double temp) {
  double c, f;
  c = temp - 273.15;
  f = c * 1.8 + 32;
  cout << "Converted to:\n";
  cout << fixed << setprecision(2);
  cout << "Celsius: " << c << endl;
  cout << "Fahrenheit: " << f << endl;

  return 0;
}

int main(int argc, char *argv[]) {
  // Declare variables
  double temp;
  string tempScale;
  tempScale = tempScale[0];

  cout << "Enter the temperature: ";
  cin >> temp;
  cout << "Enter the temperature scale: (C/F/K) ";
  cin >> tempScale;

  if (tempScale == "C" || tempScale == "c") {
    isCelsius(temp);
  } else if (tempScale == "F" || tempScale == "f") {
    isFahrenheit(temp);
  } else {
    isKelvin(temp);
  }

  return 0;
}
