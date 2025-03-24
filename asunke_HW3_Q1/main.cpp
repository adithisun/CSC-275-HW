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
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main()
{
    //-inheritance test
    Person p1("Tony", "Stark", 1, 21, 1950);
    cout << p1.getName() << " born on: " << p1.getBirthdate() << endl;

    Student s1("Peter", "Parker", 15, 10, 2001, 24);
    cout << s1.getName() << " has " << s1.getCredits() << " credit hours." << endl;

    GradStudent gs1("Bruce", "Banner", 18, 12, 1990, 35);
    cout << gs1.getName() << " can graduate? " << (gs1.canGraduate() ? "Yes" : "No") << endl;

    //virtual function test
    cout << "\n--- Shape Drawing ---\n";
    Rectangle rect(5, 9);
    Triangle tri(10, 5);

    cout << "\nRectangle:\n";
    rect.draw();
    cout << "Area: " << rect.getArea() << endl;

    cout << "\nTriangle:\n";
    tri.draw();
    cout << "Area: " << tri.getArea() << endl;

    //changing dimensions
    rect.setWidth(7);
    rect.setHeight(4);
    tri.setWidth(9);
    tri.setHeight(6);

    cout << "\nModified Rectangle Area: " << rect.getArea() << endl;
    cout << "Modified Triangle Area: " << tri.getArea() << endl;

    return 0;
}

// question 1
// the error that comes up is cannot instantiate abstract class
// this fails because polygon has pure virtual functions (getarea and draw)

// question 2
// the error that comes up is function declared but not defined
// the compiler expects definition for non-pure virtual function
