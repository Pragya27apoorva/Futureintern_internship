#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get the computer's choice
string getComputerChoice() {
    int randomNum = rand() % 3; // Random number between 0 and 2

    switch(randomNum) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
    }
    return ""; // This line will never be reached
}

// Function to determine the winner
string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "scissors" && computerChoice == "paper") ||
               (userChoice == "paper" && computerChoice == "rock")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    string userChoice;
    char playAgain;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    do {
        // Get user's choice
        cout << "Enter your choice (rock, paper, scissors): ";
        cin >> userChoice;

        // Get computer's choice
        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        // Determine the winner
        string result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;

    return 0;
}
