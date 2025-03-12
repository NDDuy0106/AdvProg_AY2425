#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // Return a random number in range 1 to 100
    return rand() % 100 + 1;
}

/***
    Args:
        
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    int number;
    cout << "Enter your guess (1-100): ";
    while (!(cin >> number) || number < 1 || number > 100) {
        cin.clear();  // Xóa trạng thái lỗi của cin
        cin.ignore(10000, '\n');  // Bỏ qua các ký tự còn lại trong bộ đệm
        cout << "Invalid input! Enter a number between 1 and 100: ";
    }
    return number;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) {
        return "Your number is higher.";
    } else if (number < randomNumber) {
        return "Your number is lower.";
    } else {
        return "Congratulation! You win.";
    }
}

/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(string answer) {
    return (answer == "Congratulation! You win.");
}

/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    return (isContinued == 'y' || isContinued == 'Y');
}

/***
    Args:
        
    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Enter 'y' to continue or 'n' to quit: ";
    }
    return choice;
}

void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    cout << "=== Welcome to Guess It! ===" << endl;
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));

    cout << "Thanks for playing! Goodbye!" << endl;
    return 0;
}
