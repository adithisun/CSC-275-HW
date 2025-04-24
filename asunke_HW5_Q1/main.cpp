/*************************************************************************
** Author: Adithi Sunke
** Program: HW5, Q1
** Date Created: April 22, 2025
** Date Last Modified: April 24, 2025
**
** Problem:
This program will read president profiles from a file then store them in a custom 
templated linked list.
*************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include "mylist.h"
using namespace std;

//struct with comparison operators
struct Profile {
    string fullname;
    string state;

    bool operator==(Profile rhs) {
        return fullname == rhs.fullname;
    }

    bool operator!=(Profile rhs) {
        return fullname != rhs.fullname;
    }
};

//overloaded << operator
ostream& operator<<(ostream& out, Profile& user) {
    out << user.fullname << "--" << user.state;
    return out;
}

int main() {
    //declare mylist of profile
    MyList<Profile> pMyList;
    Profile temp;
    string line;

    //ead file and inserthead
    ifstream file("presidentsWstates.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead(temp);  //insert into linked list
        }
    }

    cout << "All Presidents in List:\n";
    pMyList.display();  //display list

    //search for a profile
    cout << "\nSearching for 'Barack Obama': ";
    Profile searchProfile = {"Barack Obama", ""};
    if (pMyList.search(searchProfile)) {
        cout << "Found: " << searchProfile << endl;
    } else {
        cout << "Not Found.\n";
    }

    //delete head and print
    cout << "\nDeleting head...\n";
    Profile deleted = pMyList.deleteHead();
    cout << "Deleted: " << deleted << endl;

    //display again to show updated list
    cout << "\nList after deletion:\n";
    pMyList.display();

    return 0;
}
