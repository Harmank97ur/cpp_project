#include <iostream>
#include <string>
#include <cctype> // For character checks like isupper, isdigit, isspace

using namespace std;

// --- FUNCTION TO CALCULATE STRENGTH ---
int calculateStrength(string pwd) {
    // Edge Case 1: Empty or extremely short
    if (pwd.empty() || pwd.length() < 4) return 0;

    // Edge Case 2: Safety limit (Prevents huge inputs from slowing the system)
    if (pwd.length() > 64) return 0;

    int points = 0;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false, hasNonSpace = false;
    string symbols = "!@#$%^&*()-_=+[]{};:,.<>?";

    // Single loop for efficiency (O(n))
    for (char c : pwd) {
        if (!isspace(c)) hasNonSpace = true; // Check if it's not just empty spaces
        if (isupper(c))  hasUpper = true;
        if (islower(c))  hasLower = true;
        if (isdigit(c))  hasDigit = true;
        if (symbols.find(c) != string::npos) hasSymbol = true;
    }

    // Edge Case 3: Reject if password is only spaces
    if (!hasNonSpace) return 0;

    // Tallying the points
    if (pwd.length() >= 8) points++; // Length rule
    if (hasUpper && hasLower) points++; // Variety rule
    if (hasDigit) points++; // Number rule
    if (hasSymbol) points++; // Symbol rule

    return points;
}

// --- MAIN PROGRAM ---
int main() {
    int attempts = 3;
    string userPassword;
    bool success = false;

    // ANSI Color Codes
    string red = "\033[31m";
    string yellow = "\033[33m";
    string green = "\033[32m";
    string reset = "\033[0m";

    cout << "==============================" << endl;
    cout << "   SECURE PASSWORD CREATOR    " << endl;
    cout << "==============================" << endl;

    while (attempts > 0) {
        cout << "\nAttempts remaining: " << attempts << endl;
        cout << "Enter a strong password: ";
        getline(cin, userPassword);

        int score = calculateStrength(userPassword);

        cout << "Strength: ";
        if (score <= 1) {
            cout << red << "WEAK" << reset << " (Score: " << score << "/4)" << endl;
            cout << "Tip: Use 8+ characters, numbers, and symbols." << endl;
        }
        else if (score >= 2 && score <= 3) {
            cout << yellow << "MEDIUM" << reset << " (Score: " << score << "/4)" << endl;
            cout << "Tip: Almost there! Add more variety." << endl;
        }
        else {
            cout << green << "STRONG" << reset << " (Score: " << score << "/4)" << endl;
            success = true;
            break; // Stop the loop on success
        }

        attempts--;
        if (attempts > 0 && !success) {
            cout << "------------------------------" << endl;
        }
    }

    // Final Outcome
    if (success) {
        cout << "\n" << green << "[ ACCESS GRANTED ]" << reset << " Your password has been saved safely." << endl;
    } else {
        cout << "\n" << red << "[ ACCESS DENIED ]" << reset << " Too many weak attempts. System locked." << endl;
    }

    return 0;
}
