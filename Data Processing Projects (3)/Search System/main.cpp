#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Student {
    int id;
    std::string name;
    double gpa;
};

void displayList(const std::vector<Student>& list, std::string title) {
    std::cout << "\n" << title << "\n";
    std::cout << std::string(35, '=') << "\n";
    std::cout << std::left << std::setw(8) << "ID" << std::setw(15) << "Name" << "GPA" << "\n";
    std::cout << std::string(35, '-') << "\n";
    for (const auto& s : list) {
        std::cout << std::left << std::setw(8) << s.id << std::setw(15) << s.name << std::fixed << std::setprecision(2) << s.gpa << "\n";
    }
    std::cout << std::string(35, '=') << "\n";
}

int main() {
    std::vector<Student> students = {
        {101, "Alice", 3.9}, {102, "Bob", 3.2}, {103, "Charlie", 3.5},
        {104, "David", 2.8}, {105, "Elena", 4.0}, {106, "Aman",2.8}, {107, "Veer" ,3.9}
    };

    int choice;
    do {
        displayList(students, "STUDENT DATABASE SYSTEM");
        std::cout << "Search Menu:\n1. Search by Unique ID\n2. Search by GPA Range\n3. Exit\nEnter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int searchID;
            std::cout << "Enter Student ID to find: ";
            std::cin >> searchID;

            auto it = std::find_if(students.begin(), students.end(), [searchID](const Student& s) {
                return s.id == searchID;
            });

            if (it != students.end()) {
                std::cout << "\n>> FOUND: " << it->name << " (GPA: " << it->gpa << ")\n";
            } else {
                std::cout << "\n>> ERROR: Student ID " << searchID << " not found.\n";
            }

        } else if (choice == 2) {
            double minG, maxG;
            std::cout << "Enter Minimum GPA: ";
            std::cin >> minG;
            std::cout << "Enter Maximum GPA: ";
            std::cin >> maxG;

            std::cout << "\n>> Results for Range [" << minG << " - " << maxG << "]:\n";
            bool foundAny = false;
            for (const auto& s : students) {
                if (s.gpa >= minG && s.gpa <= maxG) {
                    std::cout << " - " << s.name << " (ID: " << s.id << ", GPA: " << s.gpa << ")\n";
                    foundAny = true;
                }
            }
            if (!foundAny) std::cout << "No students found in this range.\n";
        }

    } while (choice != 3);

    std::cout << "System closed." << std::endl;
    return 0;
}
