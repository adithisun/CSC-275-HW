#include <iostream>
#include <string>

using namespace std;

//defining check struct
struct Check {
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
};

//defining checkbook
class CheckBook {
private:
    float balance; //track of the balance
    Check checks[5]; //array to store checks
    float lastDeposit; //keep the last deposited amount
    int numOfChecks; //keep track of number of checks written
    const int checkLimit = 5; //capacity of checkbook

public:
    CheckBook() : balance(0), numOfChecks(0) {} //default constructor

    CheckBook(float initialBalance) : balance(initialBalance), numOfChecks(0) {} //second constructor with initial balance

    //function which adds a desired amount to the current balance
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    //function that displays checks in chronological order
    void displayChecks() {
        for (int i = numOfChecks - 1; i >= 0; i--) {
            cout << checks[i].CheckAmount << " " << checks[i].CheckNum << " " << checks[i].CheckMemo << endl;
        }
    }

    //function which takes a parameter
    bool writeCheck(float amount) {
        if (amount > balance || numOfChecks >= checkLimit) {
            return false;
        }

        //details and current position of the check
        cout << "memo? ";
        cin >> checks[numOfChecks].CheckMemo;

        checks[numOfChecks].CheckAmount = amount;
        checks[numOfChecks].CheckNum = numOfChecks;

        balance -= amount; //update balance
        numOfChecks++; //number of checks will be updated

        return true;
    }
};

//defining check class
class CheckObj {
private:
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
    static int number;

public:
    CheckObj() : CheckNum(number), CheckMemo(""), CheckAmount(0) { number++; } //default constructor with static member

    //get functions
    int getCheckNum() { return CheckNum; }
    string getCheckMemo() { return CheckMemo; }
    float getCheckAmount() { return CheckAmount; }

    //set functions
    void setCheckMemo(string memo) { CheckMemo = memo; }
    void setCheckAmount(float amount) { CheckAmount = amount; }
};

int CheckObj::number = 0;

//defining checkbook
class CheckBookObj {
private:
    float balance;
    CheckObj checks[5]; //array to store checks
    float lastDeposit;
    int numOfChecks;
    static int allChecks; //will keep track of all written checks
    const int checkLimit = 5;

public:
    CheckBookObj() : balance(0), numOfChecks(0) {} //default constructor

    CheckBookObj(float initialBalance) : balance(initialBalance), numOfChecks(0) {} //second constructor with initial balance

    //function which adds a desired amount to the current balance
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    //function to display checks
    void displayChecks() {
        for (int i = numOfChecks - 1; i >= 0; i--) {
            cout << checks[i].getCheckAmount() << " " << checks[i].getCheckNum() << " " << checks[i].getCheckMemo() << endl;
        }
    }

    //function to write checks
    bool writeCheck(float amount) {
        if (amount > balance || numOfChecks >= checkLimit || allChecks >= 10) {
            return false;
        }

        string memo;
        cout << "memo? ";
        cin >> memo;

        checks[numOfChecks].setCheckMemo(memo);
        checks[numOfChecks].setCheckAmount(amount);

        balance -= amount;
        numOfChecks++;
        allChecks++;

        return true;
    }

    int getallChecks() { return allChecks; } //getter for allChecks
};

int CheckBookObj::allChecks = 0;

//main function to test checkbook
int main() {
    CheckBookObj cb1(1000), cb2(500);

    for(int i = 0; i < 10; i++) {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout << "cb1 check details" << endl;
    cb1.displayChecks();

    cout << "cb2 check details" << endl;
    cb2.displayChecks();

    cout << cb1.getallChecks() << endl;
    cout << cb2.getallChecks() << endl;

    return 0;
}