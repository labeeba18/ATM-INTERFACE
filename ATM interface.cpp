#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    ATM(string accountNumber, string pin, double balance) {
        this->accountNumber = accountNumber;
        this->pin = pin;
        this->balance = balance;
    }

    void displayMenu() {
        cout << "Welcome to the ATM!" << endl;
        cout << "1. Withdraw Cash" << endl;
        cout << "2. Deposit Cash" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
    }

    void withdrawCash() {
        double amount;
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    void depositCash() {
        double amount;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void checkBalance() {
        cout << "Your current balance is: " << balance << endl;
    }

    bool authenticate(string accountNumber, string pin) {
        return this->accountNumber == accountNumber && this->pin == pin;
    }

    void run() {
        string accountNumber;
        string pin;
        cout << "Enter your account number: ";
        cin >> accountNumber;
        cout << "Enter your PIN: ";
        cin >> pin;

        if (authenticate(accountNumber, pin)) {
            int choice;
            while (true) {
                displayMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                switch (choice) {
                    case 1:
                        withdrawCash();
                        break;
                    case 2:
                        depositCash();
                        break;
                    case 3:
                        checkBalance();
                        break;
                    case 4:
                        cout << "Thank you for using the ATM!" << endl;
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
        } else {
            cout << "Invalid account number or PIN!" << endl;
        }
    }
};

int main() {
    ATM atm("123456789", "1234", 5000.0);
    atm.run();
    return 0;
}






