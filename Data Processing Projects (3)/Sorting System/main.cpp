#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits> // Required to clear the input buffer

struct Student {
    int id;
    std::string name;
    double gpa;
    int credits;

    void display() const {
        std::cout << std::left << std::setw(8) << id
                  << std::setw(15) << name
                  << std::setw(10) << gpa
                  << std::setw(10) << credits << std::endl;
    }
};

void displayAll(const std::vector<Student>& students, const std::string& message) {
    std::cout << "\n>>> " << message << " <<<\n";
    std::cout << std::string(45, '-') << "\n";
    std::cout << std::left << std::setw(8) << "ID"
              << std::setw(15) << "Name"
              << std::setw(10) << "GPA"
              << std::setw(10) << "Credits" << std::endl;
    std::cout << std::string(45, '-') << "\n";
    for (const auto& s : students) s.display();
}

// Function to handle user input for a new student
void addNewStudent(std::vector<Student>& students) {
    Student s;
    std::cout << "\n--- Enter New Student Details ---\n";

    std::cout << "Enter ID: ";
    std::cin >> s.id;

    std::cout << "Enter Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::getline(std::cin, s.name); // Allows names with spaces (e.g., "John Doe")

    std::cout << "Enter GPA: ";
    std::cin >> s.gpa;

    std::cout << "Enter Credits: ";
    std::cin >> s.credits;

    students.push_back(s);
    std::cout << "\nStudent added successfully!\n";
}

int main() {
    std::vector<Student> database = {
        {101, "Edward", 3.2, 130},
        {102, "Alice", 3.8, 120},
        {103, "Diana", 3.9, 100}
    };

    displayAll(database, "INITIAL DATABASE");

    int choice = 0;
    while (true) {
        std::cout << "\n1. Add New Student\n";
        std::cout << "2. Sort by GPA\n";
        std::cout << "3. Sort by Name\n";
        std::cout << "4. Sort by Credits\n";
        std::cout << "5. Sort by ID\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1:
                addNewStudent(database);
                displayAll(database, "UPDATED DATABASE");
                break;
            case 2:
                std::sort(database.begin(), database.end(), [](const Student& a, const Student& b) {
                    return (a.gpa != b.gpa) ? (a.gpa > b.gpa) : (a.name < b.name);
                });
                displayAll(database, "SORTED BY GPA");
                break;
            case 3:
                std::sort(database.begin(), database.end(), [](const Student& a, const Student& b) {
                    return a.name < b.name;
                });
                displayAll(database, "SORTED BY NAME");
                break;
            case 4:
                std::sort(database.begin(), database.end(), [](const Student& a, const Student& b) {
                    return a.credits > b.credits;
                });
                displayAll(database, "SORTED BY CREDITS");
                break;
            case 5:
                std::sort(database.begin(), database.end(), [](const Student& a, const Student& b) {
                    return a.id < b.id;
                });
                displayAll(database, "SORTED BY ID");
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
