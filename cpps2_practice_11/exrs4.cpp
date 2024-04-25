#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder {
private:
    string itemName;
    double unitPrice;
    int quantity;

public:
    ShopItemOrder(string name, double price, int qty) {
        itemName = name;
        unitPrice = price;
        quantity = qty;
    }

    string getItemName() {
        return itemName;
    }

    void setItemName(string name) {
        itemName = name;
    }

    double getUnitPrice() {
        return unitPrice;
    }

    void setUnitPrice(double price) {
        unitPrice = price;
    }

    int getQuantity() {
        return quantity;
    }

    void setQuantity(int qty) {
        quantity = qty;
    }

    double getTotalPrice() {
        return unitPrice * quantity;
    }

    void printOrder() {
        cout << "Item: " << itemName << endl;
        cout << "Unit Price: $" << unitPrice << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: $" << getTotalPrice() << endl;
    }
};

int main() {
    ShopItemOrder order("Phone", 599.99, 2);

    order.printOrder();

    return 0;
}
