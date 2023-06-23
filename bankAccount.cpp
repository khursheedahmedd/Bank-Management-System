#include "bankAccount.hpp"
#include <iostream>
#include <string>
using namespace std;

int accCount=0;

const int Max_Acc=10;
bankAccount acc1[Max_Acc];

void menu()
{
    char ch='y';
    int choice;
    
    do{
        cout<<"\n\t----------------------------";
        cout<<"\n\t*  1. Add Account          *";
        cout<<"\n\t*  2. Deposit  amount      *";
        cout<<"\n\t*  3. Withdraw  amount     *";
        cout<<"\n\t*  4. Transfer amount      *";
        cout<<"\n\t*  5. Delete Account       *";
        cout<<"\n\t*  6. Search an Account    *";
        cout<<"\n\t*  7. Display all accounts *";
        cout<<"\n\t*  8. Exit                 *";
        cout<<"\n\t----------------------------";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            {
                acc1[accCount].addAcc();
                accCount++;
                break;;
            }
            case 2:
            {
                acc1[0].deposit();
                break;
            }
            case 3:
            {
                acc1[0].withdraw();
                break;
            }
            case 5:
            {
                acc1[0].deleteAccount();
                break;
            }
            case 4:
            {
                acc1[0].transfer();
                break;
            }
            case 6:
            {
                acc1[0].searchAccount();
                break;
            }
            case 7:
            {
                acc1[0].displayAll();
                break;
            }
            case 8:
            {
                cout<<"\nExiting....";
                exit(0);
            }
            default:
                cout<<"\nInvalid choice..";
                
        }
        cout<<"\nDo you want to repeat the process? Press y: ";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}

bankAccount::bankAccount()
{
    
}

void bankAccount::setAccNum(string accNum)
{
    accountNumber=accNum;
}
string bankAccount::getAccNum()const
{
    return accountNumber;
}

void bankAccount::setBalance(int bal)
{
    balance=bal;
}
int bankAccount::getBalance()const
{
    return balance;
}

void bankAccount::addAcc()
{
    cout<<"\n_-_-_- Add Account -_-_-_\n";
    string accNum="##"+to_string(rand()+100000);
    acc1[accCount].setAccNum(accNum);
    
    int bal;
    cout<<"\nEnter first amount of balance you want to deposit: ";
    cin>>bal;
    int amount=checkAmmount(bal);
    acc1[accCount].setBalance(amount);
    
    cout<<"\nCongratulations your account is added successfully..";
    cout<<"\n--- Account Information ---\n";
    cout<<"\nAccount Number: "<<accNum;
    cout<<"\nBalance: "<<bal;
}

void bankAccount::displayAll()
{
    cout<<"\n_-_-_-_- All Accounts -_-_-_-_\n";
    for(int i=0; i<accCount; i++)
    {
        cout<<"\n--- Account "<<(i+1)<<" ---";
        cout<<"\nAccount Number: "<<acc1[i].getAccNum();
        cout<<"\nBalance: "<<acc1[i].getBalance();
    }
}

void bankAccount::deposit()
{
    cout<<"\n_-_-_- Deposit -_-_-_\n";
    cin.ignore();
    string acc;
    cout<<"\nEnter the account number in which you want to deposit: ";
    cin>>acc;
    
    bool check=false;
    
    for(int i=0; i<accCount; i++)
    {
        if(acc1[i].getAccNum()==acc)
        {
            int amount;
            cout<<"\nEnter the amount you want to deposit: ";
            cin>>amount;
            
            int newbalance=acc1[i].getBalance()+checkAmmount(amount);
            acc1[i].setBalance(newbalance);
            check=true;
            break;
        }
    }
    if(check)
    {
        cout<<"\nThe amount is deposited successfeully...";
        acc1[0].display(acc);
    }
    else
        cout<<"\nAccount not found.";
    
}

int checkAmmount(int amount)
{
    while(amount<1000)
    {
        cout<<"\nPlease enter amount more than 1000: ";
        cin>>amount;
    }
    return amount;
}

void bankAccount::withdraw()
{
    cout<<"\n_-_-_-_ Withdraw _-_-_-_\n";
    
    string acc;
    cout<<"\nEnter account from which you want to withdraw: ";
    cin>>acc;
    
    bool check=false;
    
    for(int i=0; i<accCount; i++)
    {
        if(acc1[i].getAccNum()==acc)
        {
            int amount;
            cout<<"\nEnter amount you want to withdraw: ";
            cin>>amount;
            
            if((acc1[i].getBalance()+1000)>amount)
            {
                acc1[i].setBalance(acc1[i].getBalance()-checkAmmount(amount));
                check=true;
            }
            else
            {
                cout<<"\nInsufficient amount in your account.";
                break;
            }

        }
    }
    if(check)
    {
        cout<<"\nThe required amount is withdraw successfully...";
        acc1[0].display(acc);
    }
    else
        cout<<"\nAccount not found.";
}

void bankAccount::display(string acc)
{
    cout<<"\n--- Account Information ---\n";
    for(int i=0; i<accCount; i++)
    {
        if(acc==acc1[i].getAccNum())
        {
            cout<<"\nAccount Number: "<<acc1[i].getAccNum();
            cout<<"\nBalance: "<<acc1[i].getBalance();
        }
    }
}

void bankAccount::transfer()
{
    cout<<"\n_-_-_ Transfer _-_-_\n";
    string senderAccount,recieverAccount;
    cout<<"\nEnter your account number: ";
    cin>>senderAccount;
    cout<<"\nEnter the account number of to whom you want to transfer ammount: ";
    cin>>recieverAccount;
    
    int am;
    cout<<"\nEnter the amount you want to transfer: ";
    cin>>am;
    int amount=checkAmmount(am);
    
    bool senderCheck=false;
    bool recieverCheck=false;
    
    for(int i=0; i<accCount; i++)
    {
        if(senderAccount==acc1[i].getAccNum())
        {
            if((acc1[i].getBalance()+1000)>amount)
            {
                acc1[i].setBalance((acc1[i].getBalance()-amount));
            }
            else
                cout<<"\nInsufficient amount in your account.";
            senderCheck=true;
        }
    }
    
    for(int i=0; i<accCount; i++)
    {
        if(recieverAccount==acc1[i].getAccNum())
        {
            acc1[i].setBalance(acc1[i].getBalance()+amount);
            recieverCheck=true;
        }
    }
    if(senderCheck)
    {
        if(recieverCheck)
            cout<<"\nThe amount is transfered successfully..";
        else
            cout<<"\nreciever account is not found..";
    }
    else
        cout<<"\nSender account is not found..";
    
    cout<<"\nNow your account is: ";
    acc1[0].display(senderAccount);
}

void bankAccount::searchAccount()
{
    cout<<"\n_-_-_ Search Account _-_-_\n";
    string acc;
    cout<<"\nEnter the account number you want to search: ";
    cin>>acc;
    
    bool check=false;
    for(int i=0; i<accCount; i++)
    {
        if(acc==acc1[i].getAccNum())
        {
            acc1[i].display(acc);
            check=true;
        }
    }
    if(!check)
        cout<<"\nThe required account is not found..";
}

void bankAccount::deleteAccount()
{
    cout<<"\n_-_-_ Delete _-_-_\n";
    string acc;
    cout<<"\nEnter the account number you want to delete: ";
    cin>>acc;
    
    bool check=false;
    
    for(int i=0; i<accCount; i++)
    {
        if(acc==acc1[i].getAccNum())
        {
            acc1[i].setBalance(0);
            acc1[i].setAccNum("");
            check=true;
        }
    }
    if(check)
        cout<<"\nAccount is deleted successfully..";
    else
        cout<<"\nAccount not found..";
}
