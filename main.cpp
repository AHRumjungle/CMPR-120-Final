#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

//global varibles and stats
int credits = 0;

void readStats(){

    ofstream oFile;

    oFile.open("stats.txt", ios::app); // will make a stats.txt if not found

    oFile.close();



    ifstream inFile;

    inFile.open("stats.txt"); //File with all of the statistics involving credits, wins, losses, ect


    /*
    stats.txt file structure:

    line
    1 | Current Creddits
    2 | Amount of games played
    3 | # of Wins
    4 | # of losses
    5 | # of credits added
    6 | # of creddits gained/loss based on # of creddits added

    */

   string output;

   getline(inFile, output); //reading line 1
    
    if(output != ""){

        credits = stoi(output);
    }
   cout << output; //debug

   inFile.close();

}

void showCreddits(){


   system("cls");
   cout << "Credits\n";
   cout << "-------\n";
   cout << "Current Credits: " << credits << endl;
   system("pause");


}

void addCreddits(){

    system("cls");
    cout << "Add to Balance\n";
    cout << "--------------\n";
    cout << "Amount of credits to add: ";

    int creditsToAdd;

    cin >> creditsToAdd;

   

    credits += creditsToAdd;

    cout << endl;

    cout << creditsToAdd << " credtis added\n";
    cout << "Current toltal: " << credits << endl;
    system("pause");


}





// MAIN FUNCTION //
int main(){


    readStats(); //gets data from 'stats.txt'

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

        cin >> input;
        

        //cout << input; //debug

        cout << endl; //spacing

        
        
        switch(input){
            case(1):
                showCreddits();
                break;

            case(2):
                addCreddits();
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
        

        cout << "Loop\n"; //debug
    }
    return 0;
}