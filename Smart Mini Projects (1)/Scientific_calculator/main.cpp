#include <iostream>
#include<cmath>
#include<cstdlib>
#include <limits> // Required for numeric_limits

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    double num1, num2;
    int choice;
    cout<<"-----Menu Driven Scientific Calculator-----"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    cout<<" 0.Exit\t\t 1.Addition \t 2.Subtraction \t\t 3.Multiplication \n 4.Division \t 5.Average \t 6.Power \t\t 7.SquareRoot \n 8.Cube \t 9.Log \t\t 10.Sin \t\t 11.Factorial\n ";

    while(1){
        cout<<"\n\n Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "\tError: Invalid selection. Enter a number (0-11).";
            clearInput();
            continue;
        }

        if (choice == 0) exit(0);

         // Standard 2-number operations
        if (choice >= 1 && choice <= 6) {
            cout << "\tEnter first number: ";
            if (!(cin >> num1)) { clearInput(); continue; }
            cout << "\tEnter second number: ";
            if (!(cin >> num2)) { clearInput(); continue; }

            cout << "\tResult: ";
        switch(choice){
        case 0:
            exit(0);
            break;
        case 1 :
            cout<<"  "<<num1<<" + "<<num2<<" = "<<num1+num2;
            break;
        case 2 :
            cout<<" "<<num1<<" - "<<num2<<" = "<<num1-num2;
            break;
        case 3 :
            cout<<" "<<num1<<" * "<<num2<<"  "<<num1*num2;
            break;
        case 4 :
            if(num2!=0){
                cout<<" "<<num1<<" / "<<num2<<" = "<<num1/num2;
            }
            else{
                cout<<"Division not possible!! Denominator is Zero or Negative";
            }
            break;
        case 5 :
            cout<<"Average of "<<num1<<" and "<<num2<<" is "<<(num1+num2)/2;
            break;
        case 6 :
            cout<<num1<<" ^ "<<num2<<" = "<<pow(num1,num2);
            break;
        }
    }
        //single line operator
     else if (choice >= 7 && choice <= 11) {
            cout << "\tEnter number: ";
            if (!(cin >> num1)) {
                    clearInput(); continue;
            }

            cout << "\tResult: ";
            switch (choice) {
                case 7 :
                    cout<<"SquareRoot of "<<num1<<" is "<<sqrt(num1)<<endl;
                    break;
                case 8 :
                    cout<<" "<<num1<<"^3 = "<<pow(num1,3);
                    break;
                case 9 :
                    if(num1 > 0)cout<<"\tNatural log (ln) is  "<<log(num1);
                    else cout << "\tError: Log undefined for zero or negative!";
                    break;
                case 10 :
                    cout<<"Sin of "<<num1<<" radians is "<<sin(num1);
                    break;
                case 11 :{
                    long long fact = 1;
                    if(num1<0){
                        cout<<"Factorial of NEGATIVE number does not exist.";
                        break;
                    }
                    else{
                        for(int i=1;i<=num1;i++){
                        fact = fact*i;
                    }
                    cout<<"Factorial of "<<num1<<" is "<<fact;
                    }
                    break;
                }
              }
        }
    else {
            cout << "\tInvalid choice! Try again.";
        }
   }
    return 0;
}


