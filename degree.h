// degree.h
#ifndef DEGREE_H
#define DEGREE_H

#include <iostream>
#include <string>

// Define the DegreeProgram enumeration
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// Optional: Convert enum to string for display
inline std::string degreeProgramToString(DegreeProgram dp) {
    switch (dp) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNKNOWN";
    }
}

// Test main (to make degree.h runnable independently)
#ifdef RUN_DEGREE_MAIN
int main() {
    DegreeProgram dp = SOFTWARE;
    std::cout << "Degree Program: " << degreeProgramToString(dp) << std::endl;
    return 0;
}
#endif

#endif // DEGREE_H
