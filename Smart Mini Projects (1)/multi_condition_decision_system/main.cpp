#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits  "clearInput()"

using namespace std;

class ATM {
private:
    int pin;
    double balance;
    int attempts;
    const int MAX_ATTEMPTS = 3;

    // it clears the "error" state if a user types letters
    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    // Constructor to initialize the account
    ATM(int initialPin, double initialBalance) {
        pin = initialPin;
        balance = initialBalance;
        attempts = 0;
    }

    bool authenticate() {
        int enteredPin;
        while (attempts < MAX_ATTEMPTS) {
            cout << "\n[SECURITY] Enter PIN: ";
            if (!(cin >> enteredPin)) {
                cout << "Invalid input. Please enter numbers only." << endl;
                clearInput();
                continue;
            }

            if (enteredPin == pin) {
                attempts = 0; // Reset attempts on success
                return true;
            } else {
                attempts++;
                cout << "Invalid PIN. Attempts remaining: " << (MAX_ATTEMPTS - attempts) << endl;
            }
        }
        cout << "CRITICAL: Account locked. Please visit a branch." << endl;
        return false;
    }

    void withdraw() {
        double amount;
        cout << "Current Balance: $" << balance << endl;
        cout << "Enter amount to withdraw: $";
         if (!(cin >> amount)) {
            cout << "Error: Invalid numeric input." << endl;
            clearInput();
            return;
        }

        if (amount <= 0) {
            cout << "Error: Invalid amount." << endl;
        } else if (amount > balance) {
            cout << "Error: Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Success! New Balance: $" << balance << endl;
        }
    }

    void showMenu() {
        if (!authenticate()) return;

        int choice;
        do {
            cout << "\n--- ATM MAIN MENU ---" << endl;
            cout << "1. Withdraw Cash" << endl;
            cout << "2. Check Balance" << endl;
            cout << "3. Exit" << endl;
            cout << "Selection: ";

            if (!(cin >> choice)) {
                cout << "Invalid selection. Please enter a number (1-3)." << endl;
                clearInput();
                choice = 0; // Reset choice to keep the loop active
                continue;
            }

            switch (choice) {
                case 1: withdraw(); break;
                case 2: cout << "Your balance is: $" << balance << endl; break;
                case 3: cout << "Thank you for using our ATM. Goodbye!" << endl; break;
                default: cout << "Invalid selection." << endl;
            }
        } while (choice != 3);
    }
};

int main() {
    // Create an ATM object (Account Setup)
    ATM myAccount(1234, 5000.0);

    // Start the system
    myAccount.showMenu();

    return 0;
}
