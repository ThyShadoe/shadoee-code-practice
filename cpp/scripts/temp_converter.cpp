#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

double isCelsius(double temp) {
  double f, k;
  f = temp * 1.8 + 32;
  k = temp + 273.15;
  cout << "\n";
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
  cout << "\n";
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
  cout << "\n";
  cout << "Converted to:\n";
  cout << fixed << setprecision(2);
  cout << "Celsius: " << c << endl;
  cout << "Fahrenheit: " << f << endl;

  return 0;
}

int main(int argc, char *argv[]) {
  // Declare variables
  double temp;
  string scale;
  scale = scale[0];

  while (true) {

    cout << "Enter the temperature: ";
    cin >> temp;
    cout << "Enter the scale (celsius, fahrenheit, kelvin): ";
    cin >> scale;

    char char_scale = scale[0];
    char_scale = tolower(char_scale);

    switch (char_scale) {
    case 'c':
      isCelsius(temp);
      break;
    case 'f':
      isFahrenheit(temp);
      break;
    case 'k':
      isKelvin(temp);
      break;
    default:
      cout << "Invalid temperature scale: Enter a valid scale.";
    }

    string repeatProgram;

    cout << "\n";
    cout << "Enter a new value? (y/n): ";
    cin >> repeatProgram;

    char char_repeatProgram = repeatProgram[0];
    char_repeatProgram = tolower(char_repeatProgram);

    if (char_repeatProgram != 'y') {
      break;
    }
  }

  return 0;
}
