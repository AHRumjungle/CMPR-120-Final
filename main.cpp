#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

// Refrence List
// - stoi() -- Google
// - stod() -- Google
// - try/catch -- Google
// - string.substr() -- Google
// - string.find -- Google
// - srand((unsigned)time(NULL)) -- Google

//////////////////////////////

// ## TODO ##
//
// # Thoughts #
// - Ask user if they want to load stats if username matches a save stats file? - UNDER BRANCH 'read-stats'

//////////////////////////////

//Global Constants
const double MAX_ALLOWED = 20.0; //Maximum the balance is allowed to reach from user inputed money
const double WIN_AMOUNT = 2.0; //Amount of money given to the user if they win
const double LOSE_AMOUNT = 1.0; //Amount of money given to the user if they lose

// Prototype Functions //
void mainmenu(double&, string&, int&, int&, int&, double&, double&); //All
int safeIntInput(); //No pass through
double safeDoubleInput(); //No pass through
char safeCharInput(); //No pass through
void showBalance(double&); //Pass balance through
void addBalance(double&); //Pass balance through
void displayStats(double&, string&, int&, int&, int&, double&, double&); //All
void saveStats(double&, string&, int&, int&, int&, double&, double&); //All
void mainGame(double&, string&, int&, int&, int&, double&, double&); //All
void getPlayerName(string&); //Pass name through

/////////////////////////////


// Main Function //
int main(){
    
    //Establish all of the passthrough varibles

    double balance = 0.0;       

    string playerName = "";          

    int totalGames = 0;         
    int totalWins = 0;          
    int totalLosses = 0;        
    double totalMoneyWon = 0;   
    double totalMoneyLoss = 0;   

    //Passthrough for all varibles:
    //double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss

    //Short pass through
    //double&, string&, int&, int&, int&, double&, double&

    //If there is no player name (there will always be no name)
    if(playerName == ""){
        getPlayerName(playerName);
    }
    //Add a 'config.txt' file to load default configs?

    //Run
    mainmenu(balance, playerName, totalGames, totalWins, totalLosses, totalMoneyWon, totalMoneyLoss);


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
        return -1.0;
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
   if(balance + balanceToAdd > MAX_ALLOWED){

        cout << "==ERROR==\n";
        cout << "Added balance will exceede the allowed maximum added by user of $" << MAX_ALLOWED << endl;
        cout << endl;
        system("pause");
        return;

   }
   

    balance += balanceToAdd;
    cout << endl;
    cout << "$" << balanceToAdd << " added\n";

    cout << fixed << showpoint << setprecision(2); //formating
    cout << "Current Total: $" << balance << endl;

    cout << endl;
    system("pause");

    
}

/////////////

void displayStats(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){
    system("cls");
    cout << "Current Statistics\n";
    cout << "==================\n";
    cout << "Date & Time: " << __DATE__ << " " << __TIME__ << endl;
    cout << "Player Name: " << playerName << endl;
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
Code function made by Jan
CMPR 120
November 21, 2023
*/

void saveStats(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){
    

    string userFirstName = playerName.substr(0, playerName.find(" ")); //Will extract the first word in the player name

    //File name will need to be the user's name
    string fileName = userFirstName + ".txt"; 



    //Check for existing file
    fstream existingFile;

    existingFile.open(fileName);

    //If opening file with 'filename' works due to file exsisting, display message
    if(!existingFile.fail()){
        while(true){
            system("cls");
            cout << "!==WARNING==!\n";
            cout << "Stats under this username already exists!\n";
            cout << "Do you want to overwrite? Y, N\n";

            char choice = safeCharInput();

            if(choice == 'Y'){
                break;//Continue
            }
            else if(choice == 'N'){
                return; //boot player to menu
            }
        }
    }
    existingFile.close();




    ofstream outFile;
    outFile.open(fileName);
    
    outFile << "Date & Time: " << __DATE__ << " " << __TIME__ << endl;
    outFile << "Player Name: " << playerName << endl;
    outFile << "Total Games: " << totalGames << endl;
    outFile << "Total Wins: " << totalWins << endl;
    outFile << "Total Losses: " << totalLosses << endl;
    
    outFile << fixed << showpoint << setprecision(2); //Formating
    outFile << "Total Money Won: $" << totalMoneyWon << endl;
    outFile << "Total Money Lost: $" << totalMoneyLoss;
    
    outFile.close();

    system("cls");
    cout << "Statistics saved to: " << fileName << endl;
    system("pause");
    

    
}

///////////////////

/*
Code function made by Blake DeFrancesco
CMPR 120
November 9, 2023
*/

//NOTE: Add code that checks the balance of the player. If their balance contains enough credits to play, let them play.
// Done

void mainGame(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){

    system("cls");

    //Checking balance

    if(balance < LOSE_AMOUNT){
        cout << fixed << showpoint << setprecision(2);
        cout << "Uh oh! Your current balance of: $" << balance << " is not enough money to play.\n";
        cout << "You need atlest $" << LOSE_AMOUNT << " to play.\n";
        cout << "Please add more funds.\n" << endl;
        system("pause");
        return;
    }

    cout << "Hello! I'm thinking of a number between 1 and 10." << endl; //Starting prompts which explain the game and how it works

    cout << fixed << showpoint << setprecision(2);
	cout << "If you guess correctly i'll reward you with $"<< WIN_AMOUNT << "!" << endl; 

	cout << "However, if you lose I will have to take $" << LOSE_AMOUNT <<" out of your account. Would you like to play?" << endl;

    
    cout << "Current Balance: $" << balance << endl;

	cout << "(Type 'Y' for yes or 'N' for no)\n" << endl;

	char choice; //Establishes the value for either continuing or not continuing as 'choice'


    //Inital Choice
    while(true){ 

        choice = safeCharInput(); //prompts user for their choice

        if(choice == 'N'){
            return; //Boot player to main menu
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
        if(balance < LOSE_AMOUNT){
            cout << fixed << showpoint << setprecision(2);
            cout << "Uh oh! Your current balance of: $" << balance << " is not enough money to play.\n";
            cout << "Please add more funds.\n" << endl;
            system("pause");
            return;
        }

	
		
		srand((unsigned)time(NULL)); //Establishes a random number calculation (srand) utilizing the seed (time(Null)). The seed changes every second which randomizes the number outputted. 

		int randomNumber = 1 + (rand() % 10); //Establishes the random number as an integer within the range of 1 to 10 by performing the modulus of our random number function (rand()) and adding 1 to the result

        int guess; //Establishes user input under the integer 'guess'

        //Valid input loop
        while(true){

            system("cls"); //Clear Output

		    cout << "Alright! Guess what number i'm thinking of!" << endl; //prompts user to input their guess

		    cout << "Remember, it's between 1 and 10!\n";
            cout << "Type 0 to quit now\n" << endl;

            double wideGuess; 
            //will allow user to enter a non-whole number
            //Insted of automaticly round down, 
            //will tell the user to enter an whole number and not take their money

            wideGuess = safeDoubleInput();//prompts user to input their guess 

            //Whole number check
            //If fail, restart loop
            if(!(floor(wideGuess) == wideGuess)){
                cout << endl << "Please enter a whole integer please.\n" << endl;
                system("pause");
                continue;
            }

            guess = static_cast<int>(wideGuess);

            if(guess > 0 && guess < 11){ 
                //A valid guess will continue
                break;
            }
            else if(guess == 0){
                //Typing 0 will boot the player to the menu and will not deduct any money
                return;
            }
            else if(guess != -1){
                //-1 is the error return for safeDoubleInput()
                //This will prevent a second redundent error message from poping up
                
                //Display error message
                cout << endl;
                cout << "Please enter a valid input\n" << endl;
                system("pause");
            }
            


        }
		

		if (guess == randomNumber) //if the if statement is true, it means the player guessed right and is rewarded
		{
			cout << "\nWell done! You guessed the number correctly! Here's $2!" << endl;

            totalWins++;
            totalGames++;
            totalMoneyWon += WIN_AMOUNT;
			balance += WIN_AMOUNT; //code for giving player $2/win amount goes here


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
            totalMoneyLoss += LOSE_AMOUNT;
			balance -= LOSE_AMOUNT; //code for deducting $1/Lose amount goes here

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

//Main menu Loop
void mainmenu(double& balance, string& playerName, int& totalGames, int& totalWins, int& totalLosses, double& totalMoneyWon, double& totalMoneyLoss){

    bool exit = false;

    while(!exit){
        
        system("cls");

        cout << "*** ABJ ***\n";
        cout << endl;
        cout << "*** MAIN menu ***\n";
        cout << endl;
        cout << "Please select one of the following:\n";
        cout << endl;
        cout << "\t1: Display my available balance\n";
        cout << "\t2: Add money to my account\n";
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
        cout << "Welcome to ABJ software!\n";
        cout << "Please enter your name to continue:\n";

        
        getline(cin, playerName);
        

        cout << endl;
        cout << playerName << endl;

        cout << "Is this your correct name?(Y, N): ";
        char choice = safeCharInput();

        if(choice == 'Y'){
            return;
        }

        cin.ignore(); //clear cin buffer

    }
}