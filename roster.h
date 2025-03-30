// roster.h
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
using namespace std;

// Degree enum
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Convert enum to string
string degreeToString(DegreeProgram dp) {
    switch (dp) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNKNOWN";
    }
}

// Minimal Student class
class Student {
private:
    string studentID, firstName, lastName, emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

public:
    Student(string id, string fname, string lname, string email, int age, int days[], DegreeProgram dp) {
        studentID = id;
        firstName = fname;
        lastName = lname;
        emailAddress = email;
        this->age = age;
        for (int i = 0; i < 3; ++i) daysToComplete[i] = days[i];
        degreeProgram = dp;
    }

    string getID() const { return studentID; }
    DegreeProgram getDegreeProgram() const { return degreeProgram; }

    void print() const {
        cout << "ID: " << studentID << "\tFirst Name: " << firstName
             << "\tLast Name: " << lastName << "\tAge: " << age
             << "\tDays in Course: {" << daysToComplete[0] << ", "
             << daysToComplete[1] << ", " << daysToComplete[2] << "}"
             << "\tDegree Program: " << degreeToString(degreeProgram) << endl;
    }
};

// Roster class
class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex = -1;

public:
    ~Roster() {
        for (int i = 0; i <= lastIndex; ++i) delete classRosterArray[i];
    }

    void add(string id, string fname, string lname, string email, int age, int d1, int d2, int d3, DegreeProgram dp) {
        int days[3] = {d1, d2, d3};
        classRosterArray[++lastIndex] = new Student(id, fname, lname, email, age, days, dp);
    }

    void printAll() const {
        for (int i = 0; i <= lastIndex; ++i) {
            classRosterArray[i]->print();
        }
    }
};

#endif // ROSTER_H

// Test main (allows this file to run independently)
#ifdef RUN_ROSTER_MAIN
int main() {
    Roster roster;
    roster.add("A1", "Alice", "Smith", "alice@example.com", 21, 30, 35, 40, SOFTWARE);
    roster.add("A2", "Bob", "Brown", "bob@example.com", 22, 40, 45, 50, NETWORK);
    roster.printAll();
    return 0;
}
#endif
