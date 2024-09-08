#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool includeUpper, bool includeLower, bool includeNumbers, bool includeSpecial) {
    string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerChars = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string specialChars = "!@#$%^&*()-_=+[]{};:,.<>?";

    string characterPool = "";
    string password = "";

    // Build the character pool based on user preferences
    if (includeUpper) characterPool += upperChars;
    if (includeLower) characterPool += lowerChars;
    if (includeNumbers) characterPool += numbers;
    if (includeSpecial) characterPool += specialChars;

    // Check if at least one type of character is selected
    if (characterPool.empty()) {
        cout << "Error: No character types selected. Please select at least one type of character." << endl;
        return "";
    }

    // Generate random password
    for (int i = 0; i < length; i++) {
        password += characterPool[rand() % characterPool.length()];
    }

    return password;
}

int main() {
    srand(time(0));  // Seed the random number generator

    int length;
    char choice;
    bool includeUpper, includeLower, includeNumbers, includeSpecial;

    cout << "Welcome to the Random Password Generator!" << endl;

    // Get user input for password criteria
    cout << "Enter desired password length: ";
    cin >> length;

    cout << "Include uppercase letters? (y/n): ";
    cin >> choice;
    includeUpper = (choice == 'y' || choice == 'Y');

    cout << "Include lowercase letters? (y/n): ";
    cin >> choice;
    includeLower = (choice == 'y' || choice == 'Y');

    cout << "Include numbers? (y/n): ";
    cin >> choice;
    includeNumbers = (choice == 'y' || choice == 'Y');

    cout << "Include special characters? (y/n): ";
    cin >> choice;
    includeSpecial = (choice == 'y' || choice == 'Y');

    // Generate the password
    string password = generatePassword(length, includeUpper, includeLower, includeNumbers, includeSpecial);

    // Display the generated password
    if (!password.empty()) {
        cout << "Generated Password: " << password << endl;
    }

    return 0;
}
