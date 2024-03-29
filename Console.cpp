#include "Console.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void displayDivider() {
    cout << std::setw(60) << std::setfill('-') << "" << endl;
}

int32_t getInputInt(int32_t min, int32_t max) {
    int32_t out;

    while (true) {
        cin >> out;

        // Ignore the newline character after the input
        cin.ignore();

        // Handle invalid values
        if (cin.fail()) {
            cerr << "Invalid value provided, please provide a number" << endl;

            // Clear the stream state
            cin.clear();

            // Ignore any remaining characters
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Minimum bound check
        if (out < min) {
            cerr << "That number is too small, it must be atleast " << min
                 << endl;
            continue;
        }

        // Maximum bound check
        if (out > max) {
            cerr << "That number is too big it must be at most " << max << endl;
            continue;
        }

        break;
    }

    return out;
}

float getInputFloat(float min, float max) {
    float out;

    while (true) {
        cin >> out;
        // Ignore the newline character after the input
        cin.ignore();

        // Handle invalid values
        if (cin.fail()) {
            cerr << "\nInvalid value provided, please provide a number" << endl;

            // Clear the stream state
            cin.clear();

            // Ignore any remaining characters
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Minimum bound check
        if (out < min) {
            cerr << "\nThat number is too small, it must be atleast " << min
                 << endl;
            continue;
        }

        // Maximum bound check
        if (out > max) {
            cerr << "\nThat number is too big it must be at most " << max
                 << endl;
            continue;
        }

        break;
    }

    return out;
}

bool getInputBool() {
    char out;

    while (true) {
        cin >> out;
        // Ignore the newline character after the input
        cin.ignore();

        // Handle invalid values
        if (cin.fail()) {
            cerr << "\nInvalid value provided, please provide a number" << endl;

            // Clear the stream state
            cin.clear();

            // Ignore any remaining characters
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (out) {
                // Handle truthys values
            case 'y':
            case 'Y':
            case 't':
            case '1':
                return true;
            // Handle falsey values
            case 'n':
            case 'N':
            case 'f':
            case '0':
                return false;
            // Handle unkown values
            default: {
                cerr << "Unexpected value please choose Y or N" << endl;
                continue;
            }
        }
    }
}

string getInputString() {
    string value;
    std::getline(cin, value);
    return value;
}