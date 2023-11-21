#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

// Refrence List
// - stoi() -- Google
// - stod() -- Google
// - try/catch -- Google


//////////////////////////////

//Global Constants
const double MAX_ALLOWED = 20.0; //Maximum the balance is allowed to reach from user inputed money

// Prototype Functions //
void mainMenue(double&, string&, int&, int&, int&, double&, double&); //All
int safeIntInput(); //No pass through
double safeDoubleInput(); //No pass through
char safeCharInput(); //No pass through
void showBalance(double&); //Pass balance through
void addBalance(double&); //Pass balance through
void displayStats(double&, string&, int&, int&, int&, double&, double&); //All
void saveStats(double&, string&, int&, int&, int&, double&, double&); //All
void mainGame(double&, string&, int&, int&, int&, double&, double&); //All
void getPlayerName(string&); //pass name through

/////////////////////////////



// Main Function //
int main(){
    
    //Establish all of the passthrough varibles

    double balance = 0.0;       

    string playerName;          

    int totalGames = 0;         
    int totalWins = 0;          
    int totalLosses = 0;        
    double totalMoneyWon = 0;   
    double totalMoneyLoss = 0;   

    //Passthrough for all varibles:
    //double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss

    //Short pass through
    //double&, string&, int&, int&, int&, double&, double&

    //If there is no player name
    if(playerName == ""){
        getPlayerName(playerName);
    }

    //Run
    mainMenue(balance, playerName, totalGames, totalWins, totalLosses, totalMoneyWon, totalMoneyLoss);


}



///////////////////

int safeIntInput(){

    string sInput;

    cin >> sInput;

    int Iinput;

    try{
        Iinput = stoi(sInput);
    }
    catch(std::invalid_argument){
        cout << endl << "=ERROR=\n" << "Invalid input\n" << endl << endl;
        system("pause");
        return -1;
    }

       Iinput = stoi(sInput);

    return Iinput;
    
}

/////////////////////////

double safeDoubleInput(){

    string sInput;

    cin >> sInput;

    double Dinput;

    try{
        Dinput = stod(sInput);
    }
    catch(std::invalid_argument){
        cout << endl << "=ERROR=\n" << "Invalid input\n" << endl << endl;
        system("pause");
        return -1;
    }

       Dinput = stod(sInput);

    return Dinput;
}
///////////////////

char safeCharInput(){
    string sInput;

    cin >> sInput;

    return sInput[0]; //return the fist charecter of a string, the rest is trashed
}

///////////////////

void showBalance(double& balance){


   system("cls");
   cout << "Balance\n";
   cout << "-------\n";

   cout << fixed << showpoint << setprecision(2); //formating
   cout << "Current Balance: $" << balance << endl;

   cout << endl;
   system("pause");


}

//////////////////

void addBalance(double& balance){

    system("cls");
    cout << "Add to Balance\n";
    cout << "--------------\n";
    cout << "Amount of money to add: $";

    double balanceToAdd;

    balanceToAdd = safeDoubleInput(); 

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


/////////////


void displayStats(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){
    system("cls");
    cout << "Current Statistics\n";
    cout << "==================\n";
    cout << "Player Name: " << playerName << endl;
    cout << "Date Time: " << __DATE__ << " " << __TIME__ << endl;
    cout << "Total Games: " << totalGames << endl;
    cout << "Total Wins: " << totalWins << endl;
    cout << "Total Losses: " << totalLosses << endl;

    cout << fixed << showpoint << setprecision(2); //Formating
    cout << "Total Money Won: $" << totalMoneyWon << endl;
    cout << "Total Money Lost: $" << totalMoneyLoss << endl;

    cout << endl;
    system("pause");
}

////////////////////

/*
Code segment made by Jan
CMPR 120
November 21, 2023
*/



void saveStats(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){
    
    string fileName = "Stats.txt";

    ofstream outFile;
    outFile.open(fileName);
    

    outFile << __DATE__ << " " << __TIME__ << endl;
    outFile << "Player Name: " << playerName << endl;
    outFile << "Available Credits: " << balance << endl;
    outFile << "Games Played: " << totalGames << endl;
    outFile << "Correct Guesses: " << totalWins << endl;
    outFile << "Wrong Guesses: " << totalLosses << endl;
    outFile << fixed << showpoint << setprecision(2); //Format
    outFile << "Money you won: $" << totalMoneyWon << endl;
    outFile << "Money you lost: $" << totalMoneyLoss << endl << endl << endl;
    
    outFile.close();

    system("cls");
    cout << "Statistics saved to: " << fileName << endl;
    system("pause");
    

    
}

///////////////////

/*
Code segment made by Blake DeFrancesco
CMPR 120
November 9, 2023
*/

//NOTE: Add code that checks the balance of the player. If their balance contains enough credits to play, let them play.
// Done

void mainGame(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){

    system("cls");

    //Checking balance

    if(balance < 1.0){
        cout << fixed << showpoint << setprecision(2);
        cout << "Uh oh! Your current balance of: $" << balance << " is not enough money to play.\n";
        cout << "Please add more funds.\n" << endl;
        system("pause");
        return;
    }

   

    cout << "Hello! I'm thinking of a number between 1 and 10." << endl; //Starting prompts which explain the game and how it works

	cout << "If you guess correctly i'll reward you with $2!" << endl; 

	cout << "However, if you lose I will have to take $1 out of your account. Would you like to play?" << endl;

    cout << fixed << showpoint << setprecision(2);
    cout << "Current Balance: $" << balance << endl;

	cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

	char choice; //Establishes the value for either continuing or not continuing as 'choice'


    //Inital Choice
    while(true){ 

        choice = safeCharInput(); //prompts user for their choicE

        if(choice == 'N'){
            return; //Boot player to main menue
        }   
        else if(choice == 'Y'){
            break; //Play the game
        }

    }

    //Infintely looping statement which will repeat the program as long as the user keeps entering 'Y' to continue. 
    //Otherwise the program will terminate.
	while (true)
	{

        //Checking balance
        if(balance < 1.0){
            cout << fixed << showpoint << setprecision(2);
            cout << "Uh oh! Your current balance of: $" << balance << " is not enough money to play.\n";
            cout << "Please add more funds.\n" << endl;
            system("pause");
            return;
        }


		system("cls"); //Clear Output
		
		srand((unsigned)time(NULL)); //Establishes a random number calculation (srand) utilizing the seed (time(Null)). The seed changes every second which randomizes the number outputted. 

		int randomNumber = 1 + (rand() % 10); //Establishes the random number as an integer within the range of 1 to 10 by performing the modulus of our random number function (rand()) and adding 1 to the result

		cout << "\nAlright! Guess what number i'm thinking of!" << endl; //prompts user to input their guess

		cout << "Remember, it's between 1 and 10!\n" << endl;

		int guess; //Establishes user input under the integer 'guess'

		guess = safeIntInput(); //prompts user to input their guess 

		if (guess == randomNumber) //if the if statement is true, it means the player guessed right and is rewarded
		{
			cout << "\nWell done! You guessed the number correctly! Here's $2!" << endl;

            totalWins++;
            totalGames++;
            totalMoneyWon += 2;
			balance += 2; //code for giving player $2 goes here


			cout << "Would you like to play again?" << endl;

            cout << fixed << showpoint << setprecision(2);
            cout << "Current Balance: $" << balance << endl;

			cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

			choice = safeCharInput();

			if (choice == 'N') 
			{
				return; //NOTE: This are to terminate the program if the player enters 'N' for no. Replace this with code to direct player back to the main menu.
			}
		}
		else //if the if statement is false, it means the player guessed incorrectly and is punished
		{
			cout << "\nUnfortunately you did not guess the number, the correct number was: "<< randomNumber << endl;

			cout << "$1 will be deducted from your account." << endl;

            totalLosses++;
            totalGames++;
            totalMoneyLoss += 1;
			balance -= 1; //code for deducting $1 goes here

			cout << endl << "Would you like to play again?" << endl;

            cout << fixed << showpoint << setprecision(2);
            cout << "Current Balance: $" << balance << endl;

			cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

			choice = safeCharInput();

			if (choice == 'N') 
			{
				return; //NOTE: This are to terminate the program if the player enters 'N' for no. Replace this with code to direct player back to the main menu.
			}           // Done
		}
		continue;
	}
}



/////////////////


//Main Menue Loop
void mainMenue(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){


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

        //Add a function for safe int input through input validation? - Done

        //cout << input; //debug

        cout << endl; //spacing

          
        switch(input){
            case(1):
                showBalance(balance);
                break;

            case(2):
                addBalance(balance);
                break;

            case(3):
                mainGame(balance, playerName, totalGames, totalWins, totalLosses, totalMoneyWon, totalMoneyLoss);
                break;

            case(4):
                system("cls");
                displayStats(balance, playerName, totalGames, totalWins, totalLosses, totalMoneyWon, totalMoneyLoss);
                break;

            case(5):
                saveStats(balance, playerName, totalGames, totalWins, totalLosses, totalMoneyWon, totalMoneyLoss);
                break;

            case(6):
                system("cls");
                cout << "Thank you for using ABJ software. Good bye!\n";
                system("pause");
                exit = true;
                break;

            case(-1)://code for invalid input
                break; 

            default:
                system("cls");
                cout << "Please enter a valid input\n";
                system("pause");
                break;

        }
        

        //cout << "Loop\n"; //debug
    }
}


/////////////////

void getPlayerName(string& playerName){
    while(true){
        system("cls");
        cout << "Welcome to ABJ softwear!\n";
        cout << "Please enter your name to continue:\n";

        cin.ignore();
        getline(cin, playerName); //fix issue where first char is delete when entring the name for first time

        cout << endl;
        cout << playerName << endl;

        cout << "Is this your correct name?(Y, N): ";
        char choice = safeCharInput();

        if(choice == 'Y'){
            return;
        }
    }
}