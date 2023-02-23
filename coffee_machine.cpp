#include <iostream>
#include <iomanip>
using namespace std;




void display_menu() {
    cout << "Welcome to the Coffee Machine!" << endl;
    cout << "==============================" << endl;
    cout << "1. Coffee: " << fixed << setprecision(2) << coffee_price << " euros" << endl;
    cout << "2. Coffee with Milk: " << fixed << setprecision(2) << coffee_milk_price << " euros" << endl;
    cout << "3. Chocolate: " << fixed << setprecision(2) << chocolate_price << " euros" << endl;
    cout << "4. Chocolate with Milk: " << fixed << setprecision(2) << chocolate_milk_price << " euros" << endl;
    cout << "5. Refill Supplies" << endl;
    cout << "-1. Exit" << endl;
}

bool check_supplies(int choice) {
    bool enough = true;
    switch(choice) {
        case 1: // Coffee
            if (coffee_qty < 1) enough = false;
            break;
        case 2: // Coffee with Milk
            if (coffee_qty < 1 || milk_qty < 1) enough = false;
            break;
        case 3: // Chocolate
            if (chocolate_qty < 1) enough = false;
            break;
        case 4: // Chocolate with Milk
            if (chocolate_qty < 1 || milk_qty < 1) enough = false;
            break;
        default:
            break;
    }
    return enough;
}

void make_drink(int choice) {
    switch(choice) {
        case 1: // Coffee
            coffee_qty--;
            break;
        case 2: // Coffee with Milk
            coffee_qty--;
            milk_qty--;
            break;
        case 3: // Chocolate
            chocolate_qty--;
            break;
        case 4: // Chocolate with Milk
            chocolate_qty--;
            milk_qty--;
            break;
        default:
            break;
    }
}

bool accept_payment(double price) {
    double payment = 0;
    double diff = price;
    while (payment < price) {
        cout << "Insert coin or bill (10, 20, 50 cents, 1, 2, 5, 10 euros, -1 to cancel): ";
        int coin;
        cin >> coin;
        payment += coin / 100.0;
        diff -= coin / 100.0;
        cout << "Amount paid: " << fixed << setprecision(2) << payment << " euros" << endl;
        if (coin == -1) {
            return false;
        }
        if (coin != 10 && coin != 20 && coin != 50 && coin != 100 && coin != 200 && coin != 500 && coin != 1000) {
            cout << "Invalid coin or bill. Try again." << endl;
            continue;
        }
        if (diff > 0) {
            cout << "Remaining amount: " << fixed << setprecision(2) << diff << " euros" << endl;
        } else if (diff < 0) {
            cout << "Change: " << fixed << setprecision(2) << -diff << " euros" << endl;
            cout << "Thank you" << endl;
        }
    }
    return true;
}
int main() {
    int coffee_qty = 10;
int chocolate_qty = 10;
int milk_qty = 20;
double coffee_price = 1.5;
double coffee_milk_price = 1.8;
double chocolate_price = 2.1;
double chocolate_milk_price = 2.4;
    int choice = 0;
    bool exit_flag = false;
    while (!exit_flag) {
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: // Coffee
            case 2: // Coffee with Milk
            case 3: // Chocolate
            case 4: // Chocolate with Milk
                if (check_supplies(choice)) {
                    make_drink(choice);
                    accept_payment(get_price(choice));
                } else {
                    cout << "Sorry, not enough supplies to make this drink." << endl;
                }
                break;
            case 5: // Refill supplies
                refill_supplies();
                break;
            case -1: // Exit
                exit_flag = true;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
