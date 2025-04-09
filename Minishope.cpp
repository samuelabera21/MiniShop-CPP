#include <iostream>
#include <vector>
#include <iomanip> // for setw
using namespace std;

// Structure to represent a product
struct Product {
    int id;
    string name;
    double price;
};

// Structure for a cart item
struct CartItem {
    Product product;
    int quantity;
};

// Global product list and cart
vector<Product> products;
vector<CartItem> cart;

// Initialize product data (C++98 style)
void initializeProducts() {
    Product p1 = {1, "Laptop", 35000};
    Product p2 = {2, "Headphones", 1500};
    Product p3 = {3, "Smartphone", 20000};
    Product p4 = {4, "USB Cable", 300};

    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);
}

// Function to display available products
void showProducts() {
    cout << "\n?? Available Products:\n";
    cout << left << setw(5) << "ID" << setw(20) << "Product" << setw(10) << "Price (ETB)\n";
    cout << "--------------------------------------\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << left << setw(5) << products[i].id
             << setw(20) << products[i].name
             << setw(10) << products[i].price << "\n";
    }
}

// Function to add a product to the cart
void addToCart(int productId, int quantity) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].id == productId) {
            CartItem item;
            item.product = products[i];
            item.quantity = quantity;
            cart.push_back(item);
            cout << "? Added " << quantity << " x " << products[i].name << " to your cart.\n";
            return;
        }
    }
    cout << "?? Invalid product ID.\n";
}

// Function to view cart contents
void viewCart() {
    if (cart.empty()) {
        cout << "\n?? Your cart is empty.\n";
        return;
    }

    double total = 0;
    cout << "\n?? Your Cart:\n";
    cout << left << setw(20) << "Product" << setw(10) << "Qty" << setw(15) << "Subtotal (ETB)\n";
    cout << "---------------------------------------------\n";

    for (size_t i = 0; i < cart.size(); ++i) {
        double subtotal = cart[i].product.price * cart[i].quantity;
        total += subtotal;
        cout << left << setw(20) << cart[i].product.name
             << setw(10) << cart[i].quantity
             << setw(15) << subtotal << "\n";
    }

    cout << "---------------------------------------------\n";
    cout << "?? Total: " << total << " ETB\n";
}

// Function to simulate checkout
void checkout() {
    if (cart.empty()) {
        cout << "?? Your cart is empty. Add some products first.\n";
        return;
    }

    viewCart();
    cout << "\n?? Checkout complete! Thank you for shopping with MiniShop++!\n";
    cart.clear(); // Empty the cart
}

// Main program menu
int main() {
    initializeProducts(); // Load initial product data

    int choice, productId, quantity;

    while (true) {
        cout << "\n===== ??? MiniShop++ Menu =====\n";
        cout << "1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                showProducts();
                break;
            case 2:
                cout << "Enter Product ID: ";
                cin >> productId;
                cout << "Enter Quantity: ";
                cin >> quantity;
                addToCart(productId, quantity);
                break;
            case 3:
                viewCart();
                break;
            case 4:
                checkout();
                break;
            case 5:
                cout << "?? Goodbye! Visit MiniShop++ again.\n";
                return 0;
            default:
                cout << "?? Invalid choice. Please select a number between 1 and 5.\n";
        }
    }

    return 0;
}
