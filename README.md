** C++ Smart Mini Project **

** Features**

1. Scientific Calculator
Basic Operations: Addition, Subtraction, Multiplication, Division.
Advanced Math: Square Root, Power (), Cubing (), Natural Log (ln), and Sine (radians).
Factorial Logic: Efficient loop-based calculation for integers.
Error Handling: Prevents division by zero and logs of negative numbers.

3. Secure ATM System
OOP Design: Encapsulated in a class with private balance and PIN data.
Security: 3-attempt PIN authentication limit with account lockout.
Banking: Real-time balance updates for withdrawals and deposits.
Validation: Prevents overdrafts and negative transactions.

5. Unit Converter
Distance Conversion: Seamlessly switch between Kilometers, Miles, and Feet.
Precision: Uses high-accuracy conversion constants (
 for Miles/Km).
Interactive Menu: Clean sub-menus for selecting target units.

 **Technical Highlights**
Robust Input Validation: Every tool uses a clearInput() function to prevent infinite loops when a user enters text instead of numbers.
Memory Safety: Uses local variable scoping to prevent data corruption.
Standard Headers: Leverages <cmath> for math functions and <limits> for buffer management.

** Project Structure**
Scientific Calculator: Procedural implementation with switch-case logic.
ATM System: Class-based implementation with constructors and access modifiers.
Unit Converter: Modular function-based design with precision formatting.

**License**
This project is open-source and free to use for educational purposes.





------------------------------------------------------------------------------------------------------------------------------

**Logic & Game Guessing**

1. Data-Driven Quiz
A flexible quiz system that loads questions from an external text file.
🛠️ Setup
Create a file named quiz.txt in the same directory as the executable. Use the following format:
Question|OptionA|OptionB|OptionC|OptionD|CorrectIndex

Example quiz.txt:
text
Which is a C++ keyword?|int|integer|number|var|0
What is the capital of France?|London|Paris|Berlin|Rome|1

✨ Features
External Loading: Update questions without recompiling.
Scoring: +5 for correct answers, -2 for incorrect answers.
Total Calculation: Displays final score out of the maximum possible points.


2. Secure Password Creator
A security tool that evaluates password strength based on industry-standard criteria.
✨ Features
Complexity Scoring: Points for length, case variety, digits, and symbols.
Visual Feedback: Uses ANSI color codes (Green/Yellow/Red) to indicate strength levels.
Efficiency: Analyzes input in time with a single loop.
Strict Validation: Rejects passwords that are too short, too long, or only whitespace.
📊 Scoring Logic
WEAK: 0-1 points.
MEDIUM: 2-3 points.
STRONG: 4 points (Required to pass).
3. Advanced Guessing Game
A polished "Number Guessing" game built using C++ classes.
✨ Features
Difficulty Levels:
Easy: 1-20 (10 lives)
Medium: 1-50 (7 lives)
Hard: 1-100 (5 lives)
Proximity Feedback: Tells the user if they are "BURNING UP" when they are within 5 units of the answer.
Robust Input: Handles invalid non-numeric inputs without crashing.
Replayability: Loop logic allows for multiple rounds in one session.

