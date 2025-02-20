/*************************************************************************
** Author : Adithi Sunke
** Program : CheckBook Management
** Date Created : February 20, 2025
** Date Last Modified : February 20, 2025
** Usage : No command line arguments
**
** Problem:
 - Create a Check struct and a CheckBook class to manage check transactions.
*************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//defining the check struct
struct Check {
    int CheckNum;
    string CheckMemo;
    float CheckAmount;

    //overloaded operator to compare check amount with a float value
    bool operator>(float amount) const {
        return CheckAmount > amount;
    }

    //overloaded operator
    friend ostream& operator<<(ostream& os, const Check& check) {
        os << "Check Num: " << check.CheckNum << " | Amount: $" << check.CheckAmount << " | Memo: " << check.CheckMemo;
        return os;
    }
};

class CheckBook {
    //define the checkbook class with required data members
private:
    float balance;
    Check* chkPtr;
    float lastDeposit;
    int numOfChecks;
    int checkBookSize;

    //resizing of the check array when half of the checkbook is used
    void expandCheckBook() {
        checkBookSize *= 2;
        Check* newChkPtr = new Check[checkBookSize];
        for (int i = 0; i < numOfChecks; ++i) {
            newChkPtr[i] = chkPtr[i];
        }
        delete[] chkPtr;
        chkPtr = newChkPtr;
        cout << "Warning: Checkbook size doubled to " << checkBookSize << " checks!" << endl;
    }

public:
    //default constructor
    CheckBook() : balance(0), numOfChecks(0), checkBookSize(4) {
        chkPtr = new Check[checkBookSize];
    }

    //parameterized constructor
    CheckBook(float initialBalance) : balance(initialBalance), numOfChecks(0), checkBookSize(2) {
        chkPtr = new Check[checkBookSize];
    }

    //destructor
    ~CheckBook() {
        delete[] chkPtr;
    }

    //copy constructor
    CheckBook(const CheckBook& other) : balance(other.balance), lastDeposit(other.lastDeposit), numOfChecks(other.numOfChecks), checkBookSize(other.checkBookSize) {
        chkPtr = new Check[checkBookSize];
        for (int i = 0; i < numOfChecks; ++i) {
            chkPtr[i] = other.chkPtr[i];
        }
    }

    //overloaded operator
    CheckBook& operator=(const CheckBook& other) {
        if (this != &other) {
            delete[] chkPtr;
            balance = other.balance;
            lastDeposit = other.lastDeposit;
            numOfChecks = other.numOfChecks;
            checkBookSize = other.checkBookSize;
            chkPtr = new Check[checkBookSize];
            for (int i = 0; i < numOfChecks; ++i) {
                chkPtr[i] = other.chkPtr[i];
            }
        }
        return *this;
    }

    //get functions
    float getBalance() const { return balance; }
    int getNumOfChecks() const { return numOfChecks; }
    int getCheckBookSize() const { return checkBookSize; }
    float getLastDeposit() const { return lastDeposit; }

    //set functions
    void setBalance(float newBalance) { balance = newBalance; }
    void setLastDeposit(float deposit) { lastDeposit = deposit; }

    //deposit function to add amount to balance, as required
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    //implements writecheck function to process a check, update balance, and select a memo randomly
    bool writeCheck(Check c_amount) {
        if (!(c_amount > balance)) {
            string memos[] = {"party", "girls trip", "pasta", "dental office", "hair salon", "banquet", "electronics", "appliances"};
            c_amount.CheckMemo = memos[rand() % 8];
            c_amount.CheckNum = numOfChecks + 1;
            balance -= c_amount.CheckAmount;

            if (numOfChecks >= checkBookSize / 2) {
                expandCheckBook();
            }

            chkPtr[numOfChecks++] = c_amount;
            return true;
        }
        return false;
    }

    //display all checks in order
    void displayChecks() const {
        for (int i = numOfChecks - 1; i >= 0; --i) {
            cout << chkPtr[i] << endl;
        }
    }
};

//test the checkbook class by writing checks until the balance is exhausted and doubling checkbook size when needed
void checkTest(CheckBook& cb, float balance) {
    srand(time(0));
    cb.deposit(balance);

    while (cb.getBalance() > 0) {
        float checkAmount = (rand() % 50) + 1; //random small check amount
        Check newCheck = {0, "", checkAmount};
        if (!cb.writeCheck(newCheck)) break;
    }

    cb.displayChecks();
}

//main function initializes a checkbook object and calls the checktest function to demonstrate functionality
int main() {
    CheckBook cb(500); //initialize with high balance
    checkTest(cb, 500);
    return 0;
}
