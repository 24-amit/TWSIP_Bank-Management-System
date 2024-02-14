#include <iostream>
#include <stdio.h>
#include <conio.h>
#define clrscr() system("cls")
using namespace std;
class bank
{
    int amount;

public:
    bank()
    {
        amount = 0;
    }
    void deposit(int amt);
    void withdrawal(int amt);
    void balance();
};

void bank::deposit(int amt)
{
    if (amt < 0)
        cout << "Invalid amount\n";
    else
        amount = amount + amt;
}

void bank::withdrawal(int amt)
{
    if (amt < 0)
    {
        cout << "Invalid amount\n";
    }
    else if (amt > amount)
    {
        cout << "Insufficient balance.. please check!\n";
    }
    else
    {
        amount = amount - amt;
        cout << "Congratulations, Your amount is Successfully withdrawal.\n";
    }
}

void bank::balance()
{
    cout << "\nYour current balance: " << amount << endl;
}

int main()
{
    char ch1, ch2, ch3, ch4;
    int count = 4;
    // Correct PIN = 1234
    while (count != 0)
    {
        cout << "Enter PIN(4 digit): ";
        ch1 = getch();
        cout << "*";
        ch2 = getch();
        cout << "*";
        ch3 = getch();
        cout << "*";
        ch4 = getch();
        cout << "*";
        if (ch1 == '1' && ch2 == '2' && ch3 == '3' && ch4 == '4')
            break;
        else
        {
            count--;
            cout << "\nInvalid PIN: only " << count << " options remaining.\n";
        }
    }

    if (count == 0)
    {
        cout << "\nYour account is block for 24 hours: Please contact in your bank branch...\n";
    }

    if (ch1 == '1' && ch2 == '2' && ch3 == '3' && ch4 == '4')
    {
        int choice, myamt;
        bank B;
        clrscr();
        do
        {
            cout << "\n------------------------Bank Application---------------------------";
            cout << "\n1. Diposit";
            cout << "\n2. Withdrawal";
            cout << "\n3. Check Balance";
            cout << "\n4. Exit";
            cout << "\n-------------------------------------------------------------------";
            cout << "\nEnter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "\nEnter amount for deposit: ";
                cin >> myamt;
                B.deposit(myamt);
                cout << "Congratulations, Your amount is Successfully deposited.\n";
                break;

            case 2:
                cout << "\nEnter amount for withdrawal: ";
                cin >> myamt;
                B.withdrawal(myamt);
                break;

            case 3:
                B.balance();
                break;

            default:
                break;
            }
        } while (choice != 4);
    }
    else
    {
        cout << "\nWrong pin!";
    }
    return 0;
}