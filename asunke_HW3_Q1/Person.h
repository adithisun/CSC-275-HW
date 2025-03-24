//
// Created by Adithi Sunke on 3/21/25.
//

#ifndef ASUNKE_HW3_Q1_PERSON_H
#define ASUNKE_HW3_Q1_PERSON_H

#include <string>

class Person
{
public:
    Person();
    Person(std::string first, std::string last, int year, int day, int month);
    std::string getName(); //inherited functions
    std::string getBirthdate();

private:
    std::string Fname;
    std::string Lname;
    int birthDay;
    int birthMonth;
    int birthYear;
};

//student is child of person ===
class Student : public Person {
public:
    Student();
    Student(std::string first, std::string last, int year, int day, int month, int credits);
    void setCredits(int c);  //mutator
    int getCredits();        //accessor

protected:
    int num_credits;
};

//gradsStudent is child of student
class GradStudent : public Student {
public:
    GradStudent();
    GradStudent(std::string first, std::string last, int year, int day, int month, int credits);
    bool canGraduate();      //accessor with logic
};

#endif //ASUNKE_HW3_Q1_PERSON_H
