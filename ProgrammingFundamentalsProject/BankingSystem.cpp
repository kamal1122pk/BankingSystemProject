#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
public:
    string accountNumber;
    string username;
    string password;
    double balance;
    vector<string> transactionHistory;

    Account(string accNo, string user, string pass, double initialBalance)
        : accountNumber(accNo), username(user), password(pass), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposited: $" + to_string(amount));
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdrew: $" + to_string(amount));
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Invalid withdrawal amount or insufficient balance.\n";
        }
    }

    void displayTransactions() {
        if (transactionHistory.empty()) {
            cout << "No transactions yet.\n";
        } else {
            cout << "Transaction History:\n";
            for (size_t i = 0; i < transactionHistory.size(); i++) {
                cout << transactionHistory[i] << endl;
            }
        }
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

    int findAccountIndex(const string& accNo) {
        for (size_t i = 0; i < accounts.size(); i++) {
            if (accounts[i].accountNumber == accNo) {
                return i;
            }
        }
        return -1; // Account not found
    }

public:
    void createAccount() {
        string accNo, user, pass;
        double initialBalance;
        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter username: ";
        cin >> user;
        cout << "Enter password: ";
        cin >> pass;
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        if (findAccountIndex(accNo) == -1) {
            accounts.push_back(Account(accNo, user, pass, initialBalance));
            cout << "Account created successfully.\n";
        } else {
            cout << "Account number already exists.\n";
        }
    }

    void depositToAccount() {
        string accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            accounts[index].deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdrawFromAccount() {
        string accNo;
        double amount;
        cout << "Enter account number: ";
        cin >> accNo;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            accounts[index].withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void viewAccountTransactions() {
        string accNo;
        cout << "Enter account number: ";
        cin >> accNo;

        int index = findAccountIndex(accNo);
        if (index != -1) {
            accounts[index].displayTransactions();
        } else {
            cout << "Account not found.\n";
        }
    }

    void displayAccounts() {
        if (accounts.empty()) {
            cout << "No accounts available.\n";
        } else {
            cout << "Accounts:\n";
            for (size_t i = 0; i < accounts.size(); i++) {
                cout << "Account Number: " << accounts[i].accountNumber
                     << ", Username: " << accounts[i].username
                     << ", Balance: $" << accounts[i].balance << endl;
            }
        }
    }
};

// Main function
int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\n=== Banking System Menu ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit to Account\n";
        cout << "3. Withdraw from Account\n";
        cout << "4. View Account Transactions\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.depositToAccount();
                break;
            case 3:
                bank.withdrawFromAccount();
                break;
            case 4:
                bank.viewAccountTransactions();
                break;
            case 5:
                bank.displayAccounts();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
