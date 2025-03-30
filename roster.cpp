// roster.cpp
#include <iostream>
#include <string>
using namespace std;

// Enum for degree programs
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Convert degree enum to string
string degreeToString(DegreeProgram dp) {
    switch (dp) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNKNOWN";
    }
}

// Student class definition
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
        cout << "ID: " << studentID
             << "\tFirst Name: " << firstName
             << "\tLast Name: " << lastName
             << "\tAge: " << age
             << "\tDays in Course: {" << daysToComplete[0] << ", "
             << daysToComplete[1] << ", " << daysToComplete[2] << "}"
             << "\tDegree Program: " << degreeToString(degreeProgram)
             << endl;
    }
};

// Roster class definition
class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex = -1;

public:
    ~Roster() {
        for (int i = 0; i <= lastIndex; ++i) {
            delete classRosterArray[i];
        }
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

    void printByDegreeProgram(DegreeProgram dp) const {
        cout << "\nStudents in program: " << degreeToString(dp) << endl;
        for (int i = 0; i <= lastIndex; ++i) {
            if (classRosterArray[i]->getDegreeProgram() == dp) {
                classRosterArray[i]->print();
            }
        }
    }
};

// Main function to demonstrate functionality
int main() {
    Roster roster;
    roster.add("A1", "Alice", "Smith", "alice@example.com", 20, 30, 35, 40, SOFTWARE);
    roster.add("A2", "Bob", "Brown", "bob@example.com", 22, 40, 45, 50, NETWORK);
    roster.add("A3", "Charlie", "Johnson", "charlie@example.com", 25, 20, 25, 30, SECURITY);

    cout << "All Students:\n";
    roster.printAll();

    roster.printByDegreeProgram(SOFTWARE);

    return 0;
}
