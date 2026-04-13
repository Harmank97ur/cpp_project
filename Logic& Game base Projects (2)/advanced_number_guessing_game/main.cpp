#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class GuessingGame {
private:
    int secretNumber;
    int maxRange;
    int lives;
    int score;

    void setDifficulty() {
        int choice;
        cout << "\n ---Select Difficulty ---\n1. Easy (1-20, 10 lives)\n2. Medium (1-50, 7 lives)\n3. Hard (1-100, 5 lives)\nChoice: ";

        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cout << "Invalid choice. Enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 1) { maxRange = 20; lives = 10; }
        else if (choice == 2) { maxRange = 50; lives = 7; }
        else { maxRange = 100; lives = 5; }
    }

public:
    void start() {
        srand(time(0)); // Seed random number generator
        setDifficulty();
        secretNumber = rand() % maxRange + 1;
        int guess;

        cout << "\n --- Game Started! --- " << endl;
        cout << "I'm thinking of a number between 1 and " << maxRange << "." << endl;

        while (lives > 0) {
            cout << "\nLives left: " << lives << " | Enter your guess: ";

            // Input Validation
            if (!(cin >> guess)) {
                cout << "❌ Error: Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (guess == secretNumber) {
                score = lives * 100;
                cout << " CORRECT! The number was " << secretNumber << "." << endl;
                cout << "Your Score: " << score << endl;
                return;
            }

            lives--;

            if (lives > 0) {
                if (guess < secretNumber) cout << " HIGHER!";
                else cout << " LOWER!";

                // "Hot/Cold" Advanced Logic
                int diff = abs(guess - secretNumber);
                if (diff <= 5) cout << " (You are BURNING UP!)";
            }
        }

        cout << "\n GAME OVER. The number was " << secretNumber << "." << endl;
    }
};

int main() {
    char playAgain;
    do {
        GuessingGame game;
        game.start();
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
