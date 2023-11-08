#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

// Refrence List
// - stoi() -- Google
// - try/catch -- Google
//


//global varibles, constants and stats
double balance = 0.0;

const double MAX_ALLOWED = 20.0; //Maximum the balance is allowed to reach from user inputed money


int safeIntInput(){

    string sInput;

    cin >> sInput;

    int Iinput;

    try{
        Iinput = stoi(sInput);
    }
    catch(std::invalid_argument){
        cout << endl << "=ERROR\n" << "Invalid input\n" << endl << endl;
        system("pause");
        return -1;
    }

       Iinput = stoi(sInput);

    return Iinput;
    
}

void showBalance(){


   system("cls");
   cout << "Balance\n";
   cout << "-------\n";

   cout << fixed << showpoint << setprecision(2); //formating
   cout << "Current Balance: $" << balance << endl;

   cout << endl;
   system("pause");


}

void addBalance(){

    system("cls");
    cout << "Add to Balance\n";
    cout << "--------------\n";
    cout << "Amount of money to add: $";

    double balanceToAdd;

    balanceToAdd = safeIntInput(); //Need a safeDoubleInput() function

    if(balanceToAdd <= 0){
        cout << "==ERROR==\n";
        cout << "Balance to be added must be greater than $0\n";
        cout << endl;
        system("pause");
        return;

    }

    //check if balance will exceed
   if(balance + balanceToAdd > 20.00){

        cout << "==ERROR==\n";
        cout << "Added balance will exceede the allowed maximum added by user of $20\n";
        cout << endl;
        system("pause");
        return;

   }
   

    balance += balanceToAdd;
    cout << endl;
    cout << "$" << balanceToAdd << " dollars added\n";

    cout << fixed << showpoint << setprecision(2); //formating
    cout << "Current total: $" << balance << endl;

    cout << endl;
    system("pause");

    
}





// MAIN FUNCTION //
int main(){

    //Main Menue Loop

    bool exit = false;

    while(!exit){
        
        system("cls");

        cout << "*** ABJ ***\n";
        cout << endl;
        cout << "*** MAIN MENUE ***\n";
        cout << endl;
        cout << "Please select one of the following:\n";
        cout << endl;
        cout << "\t1: Display my available balance\n";
        cout << "\t2: Add money to my accout\n";
        cout << "\t3: Play the Guessing Game\n";
        cout << "\t4: Display My Statistics\n";
        cout << "\t5: Save My Statistics\n";
        cout << "\t6: To Exit\n";
        cout << endl;

      
        int input;
        
        input = safeIntInput();

        //cin >> input; //More reliable, but less secure

        //Will change in the future
        //Add a function for safe int input through input validation?

        //cout << input; //debug

        cout << endl; //spacing

          
        switch(input){
            case(1):
                showBalance();
                break;

            case(2):
                addBalance();
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

            case(-1):
                break; //code for invalid input

            default:
                system("cls");
                cout << "Please enter a valid input\n";
                system("pause");
                break;

        }
        

        //cout << "Loop\n"; //debug
    }
    return 0;
}