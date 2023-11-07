#include<string>
#include<iostream>
using namespace std;

int main(){

    //Main Menu Loop

    bool exit = false;

    while(!exit){
        
        system("cls");

        cout << "*** ABJ ***\n";
        cout << endl;
        cout << "*** MAIN MENUE ***\n";
        cout << endl;
        cout << "Please select one of the following:\n";
        cout << endl;
        cout << "\t1: Display my available credits\n";
        cout << "\t2: Add credits to my accout\n";
        cout << "\t3: Play the Guessing Game\n";
        cout << "\t4: Display My Statistics\n";
        cout << "\t5: Save My Statistics\n";
        cout << "\t6: To Exit\n";
        cout << endl;

      
        int input;
        
        cin >> input; //More reliable, but less secure

        //Will change in the future
        //Add a function for safe int input?

        //cout << input; //debug

        cout << endl; //spacing

        switch(input){
            case(1):
                system("cls");
                cout << "You entered 1: Display my available credit\n";
                system("pause");
                break;

            case(2):
                system("cls");
                cout << "You entered 2: Add credits to my account\n";
                system("pause");
                break;

            case(3):
                system("cls");
                cout << "You entered 3: Play the Guessing Game\n";
                system("pause");
                break;

            case(4):
                system("cls");
                cout << "You entered 4: Display My Statistics\n";
                system("pause");
                break;

            case(5):
                system("cls");
                cout << "You entered 5: Save My Statistics\n";
                system("pause");
                break;

            
            
            case(6):
                system("cls");
                cout << "Thank you for using ABJ software. Good bye!\n";
                system("pause");
                exit = true;
                break;

            default:
                system("cls");
                cout << "Please enter a valid input\n";
                system("pause");
                break;

        }
    

    }
    return 0;
}