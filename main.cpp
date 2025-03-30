// main.cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Enum for DegreeProgram
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

string degreeToString(DegreeProgram dp) {
    switch (dp) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNKNOWN";
    }
}

// Student class
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
    const int* getDays() const { return daysToComplete; }
    DegreeProgram getDegreeProgram() const { return degreeProgram; }
    string getEmail() const { return emailAddress; }

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

// Roster class
class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex = -1;

public:
    ~Roster() {
        for (int i = 0; i <= lastIndex; ++i)
            delete classRosterArray[i];
    }

    void add(string id, string fname, string lname, string email, int age, int d1, int d2, int d3, DegreeProgram dp) {
        int days[3] = {d1, d2, d3};
        classRosterArray[++lastIndex] = new Student(id, fname, lname, email, age, days, dp);
    }

    void printAll() const {
        for (int i = 0; i <= lastIndex; ++i)
            classRosterArray[i]->print();
    }

    void printAverageDaysInCourse(string studentID) const {
        for (int i = 0; i <= lastIndex; ++i) {
            if (classRosterArray[i]->getID() == studentID) {
                const int* d = classRosterArray[i]->getDays();
                cout << "Average days in course for " << studentID << ": " << (d[0] + d[1] + d[2]) / 3.0 << endl;
            }
        }
    }

    void printInvalidEmails() const {
        for (int i = 0; i <= lastIndex; ++i) {
            string email = classRosterArray[i]->getEmail();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email: " << email << endl;
            }
        }
    }

    void printByDegreeProgram(DegreeProgram dp) const {
        cout << "\nStudents in program: " << degreeToString(dp) << endl;
        for (int i = 0; i <= lastIndex; ++i)
            if (classRosterArray[i]->getDegreeProgram() == dp)
                classRosterArray[i]->print();
    }
};

// Main function
int main() {
    cout << "Course Title: C867 - Scripting and Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 012418342" << endl;
    cout << "Name: Janet Otieno" << endl << endl;

    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Janet,Otieno,otienojano17@gmail.com,21,25,30,35,SOFTWARE"
    };

    Roster classRoster;

    for (const string& record : studentData) {
        stringstream ss(record);
        string id, fname, lname, email, ageStr, d1, d2, d3, deg;
        getline(ss, id, ','); getline(ss, fname, ','); getline(ss, lname, ','); getline(ss, email, ',');
        getline(ss, ageStr, ','); getline(ss, d1, ','); getline(ss, d2, ','); getline(ss, d3, ','); getline(ss, deg);

        DegreeProgram dp = (deg == "SECURITY") ? SECURITY : (deg == "NETWORK") ? NETWORK : SOFTWARE;
        classRoster.add(id, fname, lname, email, stoi(ageStr), stoi(d1), stoi(d2), stoi(d3), dp);
    }

    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    for (string id : {"A1", "A2", "A3", "A4", "A5"})
        classRoster.printAverageDaysInCourse(id);

    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    return 0;
}
