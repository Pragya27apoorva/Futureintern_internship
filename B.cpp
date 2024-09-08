#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator
    int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
    int userGuess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100: ";

    while (true) {
        cin >> userGuess;

        if (userGuess > numberToGuess) {
            cout << "Too high! Try again: ";
        } else if (userGuess < numberToGuess) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Congratulations! You guessed the correct number: " << numberToGuess << endl;
            break;
        }
    }

    return 0;
}
