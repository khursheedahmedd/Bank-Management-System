#ifndef bankAccount_hpp
#define bankAccount_hpp
#include<string>
using namespace std;

void menu();
void mainFunctio();

class bankAccount
{
private:
    string accountNumber;
    int balance;
public:
    bankAccount();
    void setAccNum(string);
    string getAccNum()const;
    void setBalance(int);
    int getBalance()const;
    void addAcc();
    void deposit();
    void withdraw();
    void displayAll();
    void display(string);
    void transfer();
    void searchAccount();
    void deleteAccount();
};
int checkAmmount(int);

#endif
