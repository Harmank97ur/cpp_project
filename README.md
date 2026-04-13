** C++ Multi-Tool Utility Suite **

A collection of three robust, console-based C++ applications demonstrating Object-Oriented Programming (OOP), procedural logic, and secure input handling.

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

