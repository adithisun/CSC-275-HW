/*************************************************************************
** Author : Adithi Sunke
** Program : HW3, Q1
** Date Created : March 21, 2025
** Date Last Modified : March 24, 2025
**
** Problem:
 - Implement multi-level inheritance and virtual functions.
*************************************************************************/

#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    //inherited functions
    Person p1("Tony", "Stark", 1, 21, 1950);
    cout << p1.getName() << " born on: " << p1.getBirthdate() << endl;

    //testing student
    Student s1("Peter", "Parker", 15, 10, 2001, 24);
    cout << s1.getName() << " has " << s1.getCredits() << " credit hours." << endl;

    //testing gradstudent
    GradStudent gs1("Bruce", "Banner", 18, 12, 1990, 35);
    cout << gs1.getName() << " can graduate? " << (gs1.canGraduate() ? "Yes" : "No") << endl;

    return 0;
}