// student.cpp
#include <iostream>
#include <string>
using namespace std;

// Enum for degree programs
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Utility function to convert enum to string
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
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

public:
    Student(string id, string fname, string lname, string email, int a, int days[], DegreeProgram dp) {
        studentID = id;
        firstName = fname;
        lastName = lname;
        emailAddress = email;
        age = a;
        for (int i = 0; i < 3; ++i) daysToComplete[i] = days[i];
        degreeProgram = dp;
    }

    void print() const {
        cout << "ID: " << studentID
             << "\tFirst Name: " << firstName
             << "\tLast Name: " << lastName
             << "\tAge: " << age
             << "\tDays in Course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}"
             << "\tDegree Program: " << degreeToString(degreeProgram) << endl;
    }
};

// Main function to test the class
int main() {
    int days[3] = {30, 35, 40};
    Student s("A1", "Jane", "Doe", "jane.doe@example.com", 20, days, SOFTWARE);
    s.print();
    return 0;
}
