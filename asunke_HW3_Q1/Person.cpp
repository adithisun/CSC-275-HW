//
// Created by Adithi Sunke on 3/21/25.
//

#include "Person.h"
#include <sstream>

using namespace std;

//person class
Person::Person() : Fname(""), Lname(""), birthDay(1), birthMonth(1), birthYear(1) {}
Person::Person(string first, string last, int day, int month, int year)
        : Fname(first), Lname(last), birthDay(day), birthMonth(month), birthYear(year) {}

string Person::getName() {
    return Fname + " " + Lname;
}

string Person::getBirthdate() {
    ostringstream bday;
    bday << birthDay << "/" << birthMonth << "/" << birthYear;
    return bday.str();
}

//student class
Student::Student() : Person(), num_credits(0) {}
Student::Student(string first, string last, int year, int day, int month, int credits)
        : Person(first, last, year, day, month), num_credits(credits) {}

void Student::setCredits(int c) {
    num_credits = c; //set value
}

int Student::getCredits() {
    return num_credits; //return value
}

//gradstudent class
GradStudent::GradStudent() : Student() {}
GradStudent::GradStudent(string first, string last, int year, int day, int month, int credits)
        : Student(first, last, year, day, month, credits) {}

bool GradStudent::canGraduate() {
    return num_credits >= 30; //logic for graduation
}