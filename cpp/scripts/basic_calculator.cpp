#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  while (true) {
    double num1, num2;
    string operation;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    while (true) {
      // TODO: Try and code this with case switches.

      cout << "Enter operation (+,-,*,/): ";
      cin >> operation;
      if (operation == "+") {
        double sum = num1 + num2;
        cout << "Sum\t: " << sum << endl;
        break;
      } else if (operation == "-") {
        double diff = num1 - num2;
        cout << "Difference\t: " << diff << endl;
        break;
      } else if (operation == "*") {
        double prod = num1 * num2;
        cout << "Difference\t: " << prod << endl;
        break;
      } else if (operation == "/") {
        double quot = num1 / num2;
        cout << "Quotient\t: " << quot << endl;
        break;
      } else {
        cout << "You entered an invalid operation.\n";
        continue;
      }
    }

    // This breaks the while loop for the end user.
    // TODO: There's a error when typing in nothing. It just hangs.
    char repeatApp = 'Y';
    cout << "Again? (Y/n) ";
    cin >> repeatApp;
    if (repeatApp != 'y' && repeatApp != 'Y') {
      break;
    }
  }

  return 0;
}
