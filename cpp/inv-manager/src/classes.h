#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
  Product(const string &name, const string &expiryDate, const string &stock)
      : name(name), expiryDate(expiryDate), stock(stock) {}
  // Getters
  string getName() const { return name; }
  string getExpiryDate() const { return expiryDate; }
  string getStock() const { return stock; }

  // Setters
  void setName(const string &name) { this->name = name; }
  void setExpiryDate(const string &expiryDate) {
    this->expiryDate = expiryDate;
  }
  void setStock(const string &stock) { this->stock = stock; }
  void displayProduct() const {
    cout << "Product Name:\t" << name << endl;
    cout << "Expiration Date:\t" << expiryDate << endl;
    cout << "Remaining Stock:\t" << stock << endl;
  }

private:
  string name;
  string expiryDate;
  string stock;
};

class InvManager {
public:
  void displayMenu() {
    cout << "\n==========================\n";
    cout << "INVENTORY MANAGER\n";
    cout << "==========================\n";
    cout << "[1] Add a Product\n";
    cout << "[2] Remove a Product\n";
    cout << "[3] Display All Products\n";
    cout << "[4] Update Existing Product\n";
    cout << "[5] Exit\n";
    cout << "==========================\n";
  }

  void addProduct() {
    string name, expiryDate, stock;

    cout << "Enter product name: ";
    cin.ignore();

    getline(cin, name);
    cout << "Enter expiration date (YYYY-MM-DD): ";
    getline(cin, expiryDate);
    cout << "Enter stock amount: ";
    getline(cin, stock);

    products.emplace_back(name, expiryDate, stock);
    cout << "Product was added successfully!\n";
  }

  void removeProduct() {
    int productNum;
    if (products.empty()) {
      cout << "There are no products to remove!\n";
      return;
    }
    cout << "Products: \n";
    for (int i = 0; i < products.size(); i++) {
      cout << i + 1 << ". " << products[i].getName() << endl;
    }
    cout << "Enter the Product number to remove: ";
    cin >> productNum;
    if (productNum >= 1 && productNum <= products.size()) {
      products.erase(products.begin() + productNum - 1);
      cout << "Product has been removed successfully!\n";
    } else {
      cout << "Invalid Product number!\n";
    }
  }

  void displayProducts() {
    if (products.empty()) {
      cout << "There are no products to display!\n";
      return;
    }
    cout << "Products: \n";
    for (int i = 0; i < products.size(); i++) {
      cout << i + 1 << ". ";
      products[i].displayProduct();
      cout << endl;
    }
  }

  void updateProduct() {
    // TODO: do some more research abt this
    int productNum;
    string name, expiryDate, stock;
    if (products.empty()) {
      cout << "There are no products to update!\n";
      return;
    }
    cout << "Products: \n";
    for (int i = 0; i < products.size(); i++) {
      cout << i + 1 << ". " << products[i].getName() << endl;
    }
    cout << "Enter the product number to update: ";
    cin >> productNum;
    if (productNum >= 1 && productNum <= products.size()) {
      Product &product = products[productNum - 1];
      cout << "Enter new product name: (current: " << product.getName()
           << ") : ";
      cin.ignore();
      getline(cin, name);
      cout << "Enter new product description (current: "
           << product.getExpiryDate() << ") : ";
      getline(cin, expiryDate);
      cout << "Enter new stock amount (current: " << product.getStock()
           << ") : ";
      getline(cin, stock);

      product.setName(name);
      product.setExpiryDate(expiryDate);
      product.setStock(stock);
      cout << "Product was updated successfully!\n";
    } else {
      cout << "Invalid product number!\n";
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
        addProduct();
        break;
      case 2:
        removeProduct();
        break;
      case 3:
        displayProducts();
        break;
      case 4:
        updateProduct();
        break;
      case 5:
        cout << "Exiting.\n";
        break;
      default:
        cout << "Not a menu choice!\n";
      }
    } while (choice != 5);
  }

private:
  vector<Product> products;
};
