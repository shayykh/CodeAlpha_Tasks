#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class representing a Transaction
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) : type(t), amount(a) {}
};

// Class representing an Account
class Account {
public:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        transactions.emplace_back("Deposit", amount);
        cout << "Deposit successful! New balance: $" << balance << endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.emplace_back("Withdrawal", amount);
            cout << "Withdrawal successful! New balance: $" << balance << endl;
            return true;
        } else {
            cout << "Insufficient funds for withdrawal.\n";
            return false;
        }
    }

    void printAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Recent Transactions:\n";
        for (const auto &transaction : transactions) {
            cout << " - " << transaction.type << ": $" << transaction.amount << endl;
        }
    }
};

// Class representing a Customer
class Customer {
public:
    string name;
    int customerID;
    vector<Account> accounts;

    Customer(string n, int id) : name(n), customerID(id) {}

    void addAccount(const Account &account) {
        accounts.push_back(account);
    }

    void printCustomerDetails() const {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Accounts:\n";
        for (const auto &account : accounts) {
            account.printAccountDetails();
        }
    }
};

// Class representing a Bank
class Bank {
public:
    vector<Customer> customers;

    void addCustomer(const Customer &customer) {
        customers.push_back(customer);
    }

    Customer* findCustomer(int customerID) {
        for (auto &customer : customers) {
            if (customer.customerID == customerID) {
                return &customer;
            }
        }
        return nullptr;
    }

    Account* findAccount(Customer &customer, int accountNumber) {
        for (auto &account : customer.accounts) {
            if (account.accountNumber == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    void transfer(Customer &fromCustomer, int fromAccountNumber, Customer &toCustomer, int toAccountNumber, double amount) {
        Account* fromAccount = findAccount(fromCustomer, fromAccountNumber);
        Account* toAccount = findAccount(toCustomer, toAccountNumber);

        if (fromAccount && toAccount && fromAccount->withdraw(amount)) {
            toAccount->deposit(amount);
            cout << "Transfer successful!\n";
        } else {
            cout << "Transfer failed.\n";
        }
    }
};

int main() {
    Bank bank;

    // Create customers
    Customer customer1("John Doe", 1001);
    Customer customer2("Jane Smith", 1002);

    // Create accounts
    Account account1(2001, 500.0);
    Account account2(2002, 1000.0);

    // Add accounts to customers
    customer1.addAccount(account1);
    customer2.addAccount(account2);

    // Add customers to bank
    bank.addCustomer(customer1);
    bank.addCustomer(customer2);

    // Example operations
    customer1.accounts[0].deposit(200);
    customer1.accounts[0].withdraw(100);
    bank.transfer(customer1, 2001, customer2, 2002, 300);

    // Print customer details
    customer1.printCustomerDetails();
    customer2.printCustomerDetails();

    return 0;
}
