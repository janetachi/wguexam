// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

// Enum for degree program
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Utility to convert enum to string
inline std::string degreeToString(DegreeProgram dp) {
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
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

public:
    // Constructors
    Student() {}
    Student(std::string id, std::string fname, std::string lname, std::string email, int a, int days[], DegreeProgram dp) {
        studentID = id;
        firstName = fname;
        lastName = lname;
        emailAddress = email;
        age = a;
        for (int i = 0; i < 3; ++i) daysToComplete[i] = days[i];
        degreeProgram = dp;
    }

    // Accessors
    std::string getStudentID() const { return studentID; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getEmailAddress() const { return emailAddress; }
    int getAge() const { return age; }
    const int* getDaysToComplete() const { return daysToComplete; }
    DegreeProgram getDegreeProgram() const { return degreeProgram; }

    // Print function
    void print() const {
        std::cout << studentID << "\tFirst Name: " << firstName
                  << "\tLast Name: " << lastName
                  << "\tAge: " << age
                  << "\tDays in Course: {" << daysToComplete[0] << ", "
                  << daysToComplete[1] << ", " << daysToComplete[2] << "}"
                  << "\tDegree Program: " << degreeToString(degreeProgram) << std::endl;
    }
};

#endif // STUDENT_H

// Allow this header to run on its own
#ifdef RUN_STUDENT_MAIN
int main() {
    int days[3] = {30, 35, 40};
    Student testStudent("A1", "John", "Doe", "johndoe@example.com", 22, days, SOFTWARE);
    testStudent.print();
    return 0;
}
#endif
