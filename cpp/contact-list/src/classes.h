#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Contact {
public:
  Contact(const string &lastName, const string &firstName,
          const string &emailAddress, const string &phoneNumber)
      : lastName(lastName), firstName(firstName), emailAddress(emailAddress),
        phoneNumber(phoneNumber) {}
  // Getters
  string getLastName() const { return lastName; }
  string getFirstName() const { return firstName; }
  string getEmailAddress() const { return emailAddress; }
  string getPhoneNumber() const { return phoneNumber; }
  // Setters
  void setLastName(const string &lastName) { this->lastName = lastName; }
  void setFirstName(const string &firstName) { this->firstName = firstName; }
  void setEmailAddress(const string &emailAddress) {
    this->emailAddress = emailAddress;
  }
  void setPhoneNumber(const string &phoneNumber) {
    this->phoneNumber = phoneNumber;
  }
  void displayContact() {
    cout << "Full Name\t:\t" << firstName << " " << lastName << endl;
    cout << "Email Address\t:\t" << emailAddress << endl;
    cout << "Phone Number\t:\t" << phoneNumber << endl;
  }

  // File Thingies
  string toFileString() const {
    return lastName + "," + firstName + "," + emailAddress + "," + phoneNumber;
  }

  static Contact fromFileString(const string &line) {
    stringstream ss(line);
    string lastName, firstName, emailAddress, phoneNumber;

    getline(ss, lastName, ',');
    getline(ss, firstName, ',');
    getline(ss, emailAddress, ',');
    getline(ss, phoneNumber);

    return Contact(lastName, firstName, emailAddress, phoneNumber);
  }

private:
  string lastName;
  string firstName;
  string emailAddress;
  string phoneNumber;
};

class ContactList {
public:
  void displayMenu() {
    cout << "\n==========================\n";
    cout << "--------------------------\n";
    cout << "CONTACT MANAGER\n";
    cout << "--------------------------\n";
    cout << "1. Add a new contact\n";
    cout << "2. Delete a contact\n";
    cout << "3. Update existing contact\n";
    cout << "4. Show all contacts\n";
    cout << "--------------------------\n";
    cout << "5. Exit\n";
    cout << "--------------------------\n"
         << "==========================\n";
  }

  ContactList() { loadContactsFromFile(); }

  ~ContactList() { saveContactsToFile(); }

  void saveContactsToFile() {
    ofstream file("contacts.txt");
    if (!file.is_open()) {
      cerr << "Unable to open file for writing\n";
      return;
    }
    for (const auto &contact : contacts) {
      file << contact.toFileString() << endl;
    }
    file.close();
  }

  void loadContactsFromFile() {
    ifstream file("contacts.txt");
    if (!file.is_open()) {
      return;
    }

    contacts.clear();
    string line;
    while (getline(file, line)) {
      if (!line.empty()) {
        contacts.push_back(Contact::fromFileString(line));
      }
    }
    file.close();
  }

  void addContact() {
    string lastName, firstName, emailAddress, phoneNumber;

    cout << "Enter first name: ";
    cin.ignore();
    getline(cin, firstName);
    cout << "Enter last name: ";
    getline(cin, lastName);
    cout << "Enter email address: ";
    getline(cin, emailAddress);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);

    contacts.emplace_back(lastName, firstName, emailAddress, phoneNumber);
    saveContactsToFile();
    cout << firstName << " was added to contacts!\n";
  }

  void removeContact() {
    int contactNum;
    if (contacts.empty()) {
      cout << "You have no contacts to remove!\n";
      return;
    }

    cout << "Your Contacts: \n";
    for (int i = 0; i < contacts.size(); i++) {
      cout << i + 1 << ". " << contacts[i].getFirstName() << " "
           << contacts[i].getLastName() << endl;
    }
    cout << "Enter the number you would like to remove: ";
    cin >> contactNum;
    if (contactNum >= 1 && contactNum <= contacts.size()) {
      contacts.erase(contacts.begin() + contactNum - 1);
      saveContactsToFile();
      cout << "Contact removed.\n";
    } else {
      cout << "Invalid number!\n";
    }
  }

  // TODO: Add a way to do the thingy where its only that thingy
  void showContacts() {
    if (contacts.empty()) {
      cout << "You have no contacts to show!\n";
      return;
    }
    cout << "Contact List: \n";
    for (int i = 0; i < contacts.size(); i++) {
      cout << i + 1 << ". ";
      contacts[i].displayContact();
      cout << endl;
    }
  }

  void updateContact() {
    int contactNum;
    string lastName, firstName, emailAddress, phoneNumber;
    if (contacts.empty()) {
      cout << "You have to contacts to update!\n";
      return;
    }
    cout << "Your Contacts: \n";
    for (int i = 0; i < contacts.size(); i++) {
      cout << i + 1 << ". " << contacts[i].getFirstName() << " "
           << contacts[i].getLastName() << endl;
    }
    cout << "Enter the number you would like to update: ";
    cin >> contactNum;
    if (contactNum >= 1 && contactNum <= contacts.size()) {
      Contact &contact = contacts[contactNum - 1];
      cout << "Enter first name: (current: " << contact.getFirstName()
           << ") : ";
      cin.ignore();
      getline(cin, firstName);
      cout << "Enter last name: (current: " << contact.getLastName() << ") : ";
      getline(cin, lastName);
      cout << "Enter email address: (current: " << contact.getEmailAddress()
           << ") : ";
      getline(cin, emailAddress);
      cout << "Enter phone number: (current: " << contact.getPhoneNumber()
           << ") : ";
      getline(cin, phoneNumber);

      contact.setLastName(lastName);
      contact.setFirstName(firstName);
      contact.setEmailAddress(emailAddress);
      contact.setPhoneNumber(phoneNumber);
      saveContactsToFile();
      cout << firstName << " was updated successfully!\n";
    } else {
      cout << "Invalid number!\n";
    }
  }

  void run() {
    int choice;
    do {
      displayMenu();
      cout << "Where would you like to go? ";
      cin >> choice;
      switch (choice) {
      case 1:
        system("clear");
        addContact();
        break;
      case 2:
        system("clear");
        removeContact();
        break;
      case 3:
        system("clear");
        updateContact();
        break;
      case 4:
        system("clear");
        showContacts();
        break;
      case 5:
        cout << "Exiting.\n";
        break;
      default:
        cout << "Invalid number!";
      }
    } while (choice != 5);
  }

private:
  vector<Contact> contacts;
};
