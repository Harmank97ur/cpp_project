#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

struct Question {
    string text;
    string options[4];
    int correctAnswerIndex;
};

vector<Question> loadQuestions(string filename) {
    vector<Question> bank;
    ifstream file(filename);
    string line;

    if (!file.is_open()) return bank;

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        Question q;
        string indexStr;

        // 1. Get Question Text
        getline(ss, q.text, '|');

        // 2. Get first 4 options using the pipe delimiter
        for (int i = 0; i < 4; i++) {
            getline(ss, q.options[i], '|');
        }

        // 3. Get the index (the rest of the string)
        if (getline(ss, indexStr)) {
            try {
                q.correctAnswerIndex = stoi(indexStr);
                bank.push_back(q);
            } catch (...) {
                /* Handle non-numeric data gracefully */
            }
        }
    }
    file.close();
    return bank;
}

int main() {
    vector<Question> quizBank = loadQuestions("quiz.txt");

    if (quizBank.empty()) {
        cout << " Error: No questions loaded. Ensure 'quiz.txt' exists and is formatted correctly." << endl;
        cout << "Format: Question|OptA|OptB|OptC|OptD|Index" << endl;
        return 1;
    }

    int score = 0;
    int maxScore = quizBank.size() * 5;
    int userChoice;

    cout << "--- Phase 4: Data-Driven C++ Quiz ---" << endl;
    cout << "Loaded " << quizBank.size() << " questions." << endl << endl;

    for (size_t i = 0; i < quizBank.size(); i++) {
        cout << "Question " << (i + 1) << ": " << quizBank[i].text << endl;
        for (int j = 0; j < 4; j++) {
            cout << "  " << j << ") " << quizBank[i].options[j] << endl;
        }

        cout << "Choice (0-3): ";
        while (!(cin >> userChoice) || userChoice < 0 || userChoice > 3) {
            cout << " Invalid. Enter 0-3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Clear the buffer after a valid choice to prevent skipping
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice == quizBank[i].correctAnswerIndex) {
            cout << " Correct!" << endl << endl;
            score += 5;
        } else {
            cout << " Wrong! Correct: " << quizBank[i].options[quizBank[i].correctAnswerIndex] << endl << endl;
            score -= 2;
        }
    }

    cout << "------------------------------" << endl;
    cout << " FINAL SCORE: " << score << " / " << maxScore << endl;

    // Optional: Add a percentage
    double percentage = (double)score / maxScore * 100;
    if (score > 0) {
        cout << "Percentage: " << percentage << "%" << endl;
    }
    return 0;
}
