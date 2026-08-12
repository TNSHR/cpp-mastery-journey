#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:

    BankAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    void displayBalance()
    {
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account;

    account.deposit(5000);

    account.withdraw(1500);

    account.displayBalance();

    return 0;
}