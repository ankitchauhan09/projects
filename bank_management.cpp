#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

void acc_details();
// void mini();
// void balance_check();
void withdrawl();
void deposit();
void new_acc();

int main()
{
    // ofstream account("database.txt", ios::app);
    cout << " <---------------------------- WELCOME TO ANKIT CHAUHAN BANKING SYSTEM -----------------------------> " << endl;
    cout << " 1 for Account Details " << endl;
    cout << " 2 for Mini Statement " << endl;
    cout << " 3 for Cash Withdrawl " << endl;
    cout << " 4 for Cash Deposit " << endl;
    cout << " 5 for Check Balance " << endl;
    cout << " 6 for Opening New Account : " << endl;
    cout << " Enter your choice : ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        acc_details();
        break;
    // case 2:
    //     mini();
    //     break;
    case 3:
        withdrawl();
        break;
    case 4:
        deposit();
        break;
    // case 5:
    //     balance_check();
    //     break;
    case 6:
        new_acc();
        break;
    }
    return 0;
}

// Functions........................

void new_acc()
{
    system("cls");
    ofstream new_acc("database.txt", ios::app);
    string first_name;
    string second_name;
    string dob;
    int account_number;
    int password, total_balance = 0;

    cout << " Enter your first name : ";
    cin >> first_name;
    new_acc << first_name << " ";
    cout << " Enter your second name : ";
    cin >> second_name;
    new_acc << second_name << " ";
    cout << " Enter your Date of Birth (dd/mm/yyyy) : ";
    cin >> dob;
    new_acc << dob << " ";
    cout << " Enter your account number : " << endl;
    cin >> account_number;
    new_acc << account_number << " ";
    cout << " Enter your password : " << endl;
    cin >> password;
    new_acc << password << " ";
    cout << " Enter the amount which you want to deposit ( min : 5k) : " << endl;
    cin >> total_balance;
    new_acc << total_balance << endl;
    new_acc.close();

    cout << "Account created successfully \n\n\n";
    main();
}

void acc_details()
{
    ifstream acc("database.txt");
    string first_name;
    string second_name;
    string dob;
    int account_number;
    int password, account_balance, count = 0, check_account, check_password;

    cout << " Enter your account Number and Password to Print the details : " << endl;
    cin >> check_account;
    cin >> check_password;
    while (acc >> first_name >> second_name >> dob >> account_number >> password >> account_balance)
    {
        if (account_number == check_account && password == check_password)
        {
            count = 1;
            break;
        }
    }
    acc.close();
    if (count == 1)
    {
        cout << " Your account details are " << endl;
        cout << " Name : " << first_name << " " << second_name << endl;
        cout << " DOB : " << dob << endl;
        cout << " Account Number : " << account_number << endl;
        cout << " Password : " << password << endl;
        cout << " Your total Account Balance is : " << account_balance << endl;
        main();
    }
    else
    {
        cout << " You have entered incorrect credentials..... \n Please try again... " << endl
             << "--------------------------------------------------------------------------------------------------------" << endl;
        main();
    }
}

void withdrawl()
{
    int deposit_amount, total_amount;
    string temp;
    int tp, account_number, password, count = 0, check_number, check_pass;
    ifstream account("database.txt");

    cout << " Enter your account Number and Password to Print the details : " << endl;
    cin >> check_number;
    cin >> check_pass;

    while (account >> temp >> temp >> temp >> account_number >> password >> total_amount)
    {
        if (account_number == check_number && password == check_pass)
        {
            count = 1;
            break;
        }
    }
    account.close();
    if (count == 1)
    {
        cout << " How much money do you want to withdraw : ";
        cin >> deposit_amount;
        if (deposit_amount <= total_amount)
        {
            int old_amount = total_amount;
            total_amount -= deposit_amount;
            ofstream temp("temp_file.txt", ios::app);
            ifstream acc("database.txt");
            string first_name;
            string second_name;
            string dob;
            int account_number;
            int password, account_balance;
            while (acc >> first_name >> second_name >> dob >> account_number >> password >> account_balance)
            {
                if (account_balance == old_amount)
                {
                    account_balance = total_amount;
                }
                temp << first_name << " " << second_name << " " << dob << " " << account_number << " " << password << " " << account_balance << endl;
            }
            acc.close();
            temp.close();
            int succes = remove("database.txt");
            if (succes == 0)
            {
                cout << "File deleted successfullly..." << endl;
            }
            else
            {
                cout << " File deletion unsuccessfull.... " << endl;
            }
            rename("temp_file.txt", "database.txt");
            // remove("temp_file.txt");
            cout << " Amount withdrawl successfully....\n Please collect your cash....\n"
                 << endl;
            main();
        }
        else
        {
            cout << "INSUFFICIENT BALANCE " << endl;
            main();
        }
    }
    else
    {
        cout << " INCORRECT CREDENTIALS \n Please try again later...." << endl;
        main();
    }
}

void deposit()
{
    int deposit_amount, total_amount;
    string temp;
    int tp, account_number, password, count = 0, check_number, check_pass;
    ifstream account("database.txt");

    cout << " Enter your account Number and Password to Print the details : " << endl;
    cin >> check_number;
    cin >> check_pass;

    while (account >> temp >> temp >> temp >> account_number >> password >> total_amount)
    {
        if (account_number == check_number && password == check_pass)
        {
            count = 1;
            break;
        }
    }
    account.close();
    if (count == 1)
    {
        cout << " How much money do you want to deposit : ";
        cin >> deposit_amount;
        int old_amount = total_amount;
        total_amount += deposit_amount;
        ofstream temp("temp_file.txt", ios::app);
        ifstream acc("database.txt");
        string first_name;
        string second_name;
        string dob;
        int account_number;
        int password, account_balance;
        while (acc >> first_name >> second_name >> dob >> account_number >> password >> account_balance)
        {
            if (account_balance == old_amount)
            {
                account_balance = total_amount;
            }
            temp << first_name << " " << second_name << " " << dob << " " << account_number << " " << password << " " << account_balance << endl;
        }
        acc.close();
        temp.close();
        remove("database.txt");
        rename("temp_file.txt", "database.txt");
        // remove("temp_file.txt");
        cout << " Amount deposited successfully....\n Please visit us again....\n"
             << endl;
        main();
    }
    else
    {
        cout << " INCORRECT CREDENTIALS \n Please try again later...." << endl;
        main();
    }
}