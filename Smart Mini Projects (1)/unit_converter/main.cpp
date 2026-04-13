#include <iostream>
#include <limits>

using namespace std;

double inputValue, outputValue;

// Helper to prevent infinite loops if user types text
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void kmToOthers(){

    cout<<"\nSelect a desired option: ";
    cout<<"\n 1.Km --> Miles";
    cout<<"\n 2.Km --> Feet";
    cout<<"\n 3.Km --> Inches";
    cout<<"\n";
    int opt;

    if (!(cin >> opt)) {
            clearInput(); return;
    }

    cout << "\nEnter value in kilometers: ";
    if (!(cin >> inputValue)) {
            clearInput(); return;
    }

    switch(opt){
        case 1:
            outputValue = inputValue * 0.62137;
            cout<<"\n\t"<<inputValue<<" km --> "<< outputValue <<" miles\n";
            break;

         case 2:
            outputValue = inputValue* 3280.84;
            cout<<"\n\t"<<inputValue<<" km --> "<< outputValue <<" feet\n";
            break;
         case 3:
            outputValue = inputValue* 39370;
            cout<<"\n\t"<<inputValue<<" km -->"<< outputValue <<" inches\n";
            break;

    }
};
void milesToOthers(){

    cout<<"\nSelect a desired option: ";
    cout<<"\n 1.Miles --> Km";
    cout<<"\n 2.Miles --> Feet";
    cout<<"\n 3.Miles --> Inches";
    cout<<"\n";

    int opt;
    if (!(cin >> opt)) {
            clearInput();
            return;
    }

    cout << "\nEnter value in Miles: ";
    if (!(cin >> inputValue)) {
            clearInput();
        return;
    }

    switch(opt){
        case 1:
            outputValue = inputValue* 1.6093;
            cout<<"\n\t"<<inputValue<<" miles --> "<< outputValue <<" Km\n";
            break;

         case 2:
            outputValue= inputValue* 5280;
            cout<<"\n\t"<<inputValue<<" miles --> "<< outputValue <<" Feet\n";
            break;
         case 3:
            outputValue = inputValue* 63360;
            cout<<"\n\t"<<inputValue<<" miles -->"<< outputValue <<" Inches\n";
            break;

    }
};
void feetToOthers(){

    cout<<"\nSelect a desired option: ";
    cout<<"\n 1.Feet --> Km";
    cout<<"\n 2.Feet --> Miles";
    cout<<"\n 3.Feet --> Inches";
    cout<<"\n";

    int opt;
    if (!(cin >> opt)) {
            clearInput();
            return;
    }

    cout << "\nEnter value in Feet: ";
    if (!(cin >> inputValue)) {
            clearInput();
        return;
    }

    switch(opt){
        case 1:
            outputValue = inputValue* 0.000304;
            cout<<"\n\t"<<inputValue<<" Feet -->"<< outputValue <<" Km\n";
            break;

         case 2:
            outputValue = inputValue* 0.000189;
            cout<<"\n\t"<<inputValue<<" Feet -->"<< outputValue <<" Miles\n";
            break;
         case 3:
            outputValue = inputValue* 12;
            cout<<"\n\t"<<inputValue<<" Feet -->"<< outputValue <<" Inches\n";
            break;

    }

};
int main()
{
    bool running = true;
    while(running) {
        //cout << "\033[2J\033[H"; // Clears screen and moves cursor to top

        cout<<"\n--- Unit Converter ---";
        cout<<"\n 1. Km\n 2. Miles\n 3. Feet\n Choice: ";
        int sele;
        if (!(cin >> sele)) {
            cout << "Invalid input. Please use numbers.\n";
            clearInput();
            continue;
        }

        switch(sele){
            case 1: kmToOthers(); break;
            case 2: milesToOthers(); break;
            case 3: feetToOthers(); break;
            default: cout<<"Invalid choice!\n"; break;
        }

        cout << "\nPress 'E' to Exit, or any other key to continue: ";
        char choice;
        cin >> choice;
        if(choice == 'E' || choice == 'e') {
            running = false;
        }
    }

    cout << "\nProgram finished. Press Enter to close...";
    cin.ignore(1000, '\n'); // Clears any leftover keys in the buffer
    cin.get();             // Waits for the user to press Enter
    return 0;
}
