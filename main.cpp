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


/*
Code segment made by Blake DeFrancesco
CMPR 120
November 9, 2023
*/

//NOTE: Add code that checks the balance of the player. If their balance contains enough credits to play, let them play.
//

void mainGame(){

    system("cls");

    cout << "Hello! I'm thinking of a number between 1 and 10." << endl; //Starting prompts which explain the game and how it works

	cout << "If you guess correctly i'll reward you with $2!" << endl; 

	cout << "However, if you lose I will have to take $1 out of your account. Would you like to play?" << endl;

	cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

	char choice; //Establishes the value for either continuing or not continuing as 'choice'

	

	while (true) //Infintely looping statement which will repeat the program as long as the user keeps entering 'Y' to continue. Otherwise the program will terminate.
	{



        

        while(true){

            cin >> choice; //prompts user for their choice

            if(choice == 'N'){
            return; //Boot player to main menue
            }   
            else if(choice == 'Y'){
                break; //Play the game
            }

        }


		
		
		srand((unsigned)time(NULL)); //Establishes a random number calculation (srand) utilizing the seed (time(Null)). The seed changes every second which randomizes the number outputted. 

		int randomNumber = 1 + (rand() % 10); //Establishes the random number as an integer within the range of 1 to 10 by performing the modulus of our random number function (rand()) and adding 1 to the result

		cout << "\nAlright! Guess what number i'm thinking of!" << endl; //prompts user to input their guess

		cout << "Remember, it's between 1 and 10!\n" << endl;

		int guess; //Establishes user input under the integer 'guess'

		guess = safeIntInput(); //prompts user to input their guess 

		if (guess == randomNumber) //if the if statement is true, it means the player guessed right and is rewarded
		{
			cout << "\nWell done! You guessed the number correctly! Here's $2!" << endl;

			balance += 2; //code for giving player $2 goes here

			cout << "Would you like to play again?" << endl;

			cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

			cin >> choice;

			if (choice == 'N') 
			{
				return; //NOTE: This are to terminate the program if the player enters 'N' for no. Replace this with code to direct player back to the main menu.
			}
		}
		else //if the if statement is false, it means the player guessed incorrectly and is punished
		{
			cout << "\nUnfortunately you did not guess the number, better luck next time!" << endl;

			cout << "$1 will be deducted from your account." << endl;

			balance -= 1; //code for deducting $1 goes here

			cout << "Would you like to play again?" << endl;

			cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

			cin >> choice;

			if (choice == 'N') 
			{
				return; //NOTE: This are to terminate the program if the player enters 'N' for no. Replace this with code to direct player back to the main menu.
			}
		}
		continue;
	}
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
                mainGame();
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