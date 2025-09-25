#include <cctype>
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

    char char_operation = operation[0];
    char_operation = tolower(char_operation);

    while (true) {
      // TODO: fix smth abt symbols.

      cout << "Enter operation (+,-,*,/): ";
      cin >> operation;

      double sum = num1 + num2;
      double diff = num1 - num2;
      double prod = num1 * num2;
      double quot = num1 / num2;

      switch (char_operation) {
      case '+':
        cout << "Sum\t: " << sum << endl;
        break;
      case '-':
        cout << "Difference\t: " << diff << endl;
        break;
      case '*':
        cout << "Product\t: " << prod << endl;
        break;
      case '/':
        cout << "Quotient\t: " << quot << endl;
        break;
      default:
        cout << "You entered an invalid operation.\n";
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
