#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

using namespace std;

// ==========================================
// MODULE 1: DATA ENTITY
// ==========================================
class Student {
private:
    int id;
    string name;
    float gpa;

public:
    Student(int i, string n, float g) : id(i), name(n), gpa(g) {}

    int getId() const { return id; }
    string getName() const { return name; }
    float getGpa() const { return gpa; }

    void displayRow() const {
        cout << left << setw(10) << id
             << setw(25) << name
             << setw(5) << fixed << setprecision(2) << gpa << endl;
    }
};

// ==========================================
// MODULE 2: SYSTEM CONTROLLER
// ==========================================
class StudentManager {
private:
    vector<Student> students;
    const string filename = "students_db.txt";

    // CORE LOGIC: Ensures sequential order by ID
    void sortDatabase() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getId() < b.getId();
        });
    }

public:
    StudentManager() {
        loadFromFile();
    }

    void addStudent() {
        try {
            int id;
            string name;
            float gpa;

            cout << "\n--- Enroll New Student ---\n";
            cout << "Enter ID: ";
            if (!(cin >> id)) throw invalid_argument("ID must be a number.");

            for(const auto& s : students) {
                if(s.getId() == id) throw invalid_argument("This ID already exists!");
            }

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter GPA (0.0 - 4.0): ";
            cin >> gpa;
            if (gpa < 0.0 || gpa > 4.0) throw out_of_range("GPA must be between 0.0 and 4.0.");

            students.emplace_back(id, name, gpa);

            // Re-sort after adding
            sortDatabase();
            saveToFile();

            cout << "Record added and database re-sequenced!\n";
        }
        catch (const exception& e) {
            cout << "ERROR: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    void showDatabase() {
        if (students.empty()) {
            cout << "\nDatabase is currently empty.\n";
            return;
        }

        // Final safety sort before displaying
        sortDatabase();

        cout << "\n" << string(45, '=') << endl;
        cout << left << setw(10) << "ID" << setw(25) << "NAME" << setw(5) << "GPA" << endl;
        cout << string(45, '-') << endl;
        for (const auto& s : students) s.displayRow();
        cout << string(45, '=') << endl;
    }

    void updateStudent() {
        int searchID;
        cout << "\nEnter ID to update: ";
        cin >> searchID;

        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == searchID) {
                string newName;
                float newGpa;
                cout << "Record Found! New Name: ";
                cin.ignore();
                getline(cin, newName);
                cout << "New GPA: ";
                cin >> newGpa;

                students[i] = Student(searchID, newName, newGpa);

                sortDatabase();
                saveToFile();
                cout << "Update successful and sequence maintained.\n";
                found = true;
                break;
            }
        }
        if(!found) cout << "Student with ID " << searchID << " not found.\n";
    }

    void deleteStudent() {
        int searchID;
        cout << "\nEnter ID to delete: ";
        cin >> searchID;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == searchID) {
                students.erase(it);
                saveToFile();
                cout << "Record deleted successfully.\n";
                return;
            }
        }
        cout << "Student ID not found.\n";
    }

    // ==========================================
    // MODULE 3: PERSISTENCE (File I/O)
    // ==========================================
    void saveToFile() {
        ofstream outFile(filename);
        for (const auto& s : students) {
            outFile << s.getId() << "," << s.getName() << "," << s.getGpa() << endl;
        }
        outFile.close();
    }

    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) return;

        students.clear();
        string line;
        while (getline(inFile, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.rfind(',');
            if(p1 != string::npos && p2 != string::npos) {
                int id = stoi(line.substr(0, p1));
                string name = line.substr(p1 + 1, p2 - p1 - 1);
                float gpa = stof(line.substr(p2 + 1));
                students.emplace_back(id, name, gpa);
            }
        }
        inFile.close();

        // Sort immediately after loading from file
        sortDatabase();
    }
};

// ==========================================
// MAIN INTERFACE
// ==========================================
int main() {
    StudentManager sm;
    int choice;

    do {
        cout << "\n--- STUDENT MANAGEMENT SYSTEM ---";
        cout << "\n1. Add Student (Auto-Sort)";
        cout << "\n2. View Database (Sequential)";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nSelection: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.showDatabase(); break;
            case 3: sm.updateStudent(); break;
            case 4: sm.deleteStudent(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid option selected.\n";
        }
    } while (choice != 5);

    return 0;
}
