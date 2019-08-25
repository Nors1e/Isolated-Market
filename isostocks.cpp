/**
Author: Caleb Stout
Email: hisurfingc@yahoo.com
OS: Mac
Date: 5/17/2019
**/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "dopewars.h"
#include "portfolio.h"

using namespace std;
/**
* Provides main menu for the user
@no params
 */
void menuOne(){
        cout << "\n\nMAIN MENU" << endl;
        cout << "Please choose one of the following: "<< endl;
        cout << "\n0. Exit program\n" << endl
             << "1. List available stocks\n" << endl
             << "2. Begin the game\n" << endl;
}

/**
 * Set's the amount of time passed with respect to the stocks price
*/
void setDuration(){
    int days = 0;
    cin >> days;
}

/**
Provides random price generation within the company prices
*/
double randomMovements(double ogPrice){
    srand(time(NULL));
    double foo[6] = {1.0,3.0,5.0,7.0,11.0,25.0};
    double randomNum = foo[rand() % 3];
    cout << "Number change: " << randomNum << endl;
    double percentageGen = randomNum/100.0;
    cout << "Percentage change: " << percentageGen << endl;
    double priceOne = ogPrice + (ogPrice * percentageGen);
    cout << "New Price: " << priceOne << endl;
    return priceOne;
}

/**
Provides game menu for the user
setprecision(20);
Prompts for buying, selling and days advancing
*/
void gameMenu(Portfolio& objectOne){
    int choiceOne = -1;
    int choiceThree = 3;
    int choiceFour = 4;
    cout << "Please choose one of the options below." << endl;
    cout << "\n\n1. Buy Company" << endl;
    cout << "2. Sell Company" << endl;
    cout << "3. Enter in the days you wish to advance" << endl;
    cout << "4. See current account value." << endl;
    cout << "0. Retire.\n" << endl;
    cout << "Please enter your choice: ";
    cin >> choiceOne;
    if (choiceOne == 1){
        objectOne.buyCompany();
    }
    else if (choiceOne == 2){
        cout << "Please choose a stock you wish to sell." << endl;
        objectOne.sellCompany();
    }
    else if (choiceOne == choiceThree){
        cout << "Please enter the amount of days you wish to advance.";
                setDuration();
                double foo = 0.0;
                for (unsigned int i = 0; i < objectOne.getcompaniesOwned().size(); i++){
                    foo = randomMovements(objectOne.getcompaniesOwned()[i].getPrice());
                    objectOne.getcompaniesOwned()[i].setPrice(foo);
                }
    }
    else if (choiceOne == choiceFour){
        cout << "Account Value: ";
        cout << objectOne.getAccount();
    }
}

int main() {
  cout << endl << endl;
  cout << "███████╗████████╗ ██████╗  ██████╗██╗  ██╗    ██╗    ██╗ █████╗ ██████╗ ███████╗" << endl
       << "██╔════╝╚══██╔══╝██╔═══██╗██╔════╝██║ ██╔╝    ██║    ██║██╔══██╗██╔══██╗██╔════╝" << endl
       << "███████╗   ██║   ██║   ██║██║     █████╔╝     ██║ █╗ ██║███████║██████╔╝███████╗" << endl
       << "╚════██║   ██║   ██║   ██║██║     ██╔═██╗     ██║███╗██║██╔══██║██╔══██╗╚════██║" << endl
       << "███████║   ██║   ╚██████╔╝╚██████╗██║  ██╗    ╚███╔███╔╝██║  ██║██║  ██║███████║" << endl
       << "╚══════╝   ╚═╝    ╚═════╝  ╚═════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝" << endl;
    int twentyTwo = 22;
    cout << setw(twentyTwo) << "Welcome to the Isolated Market Game" << endl;
    cout << setw(twentyTwo) << "-----------------------------------" << endl;
    int choice = -1;
    Portfolio objectOne;
    while(choice != 0){
        menuOne();
        cout << "Please Enter your Decision: ";
        int choice = -1;
        cin >> choice;
        if(cin.fail()){
            cout << "Please enter a choice within the range specified.";
        }
        bool sentV = true;
        while (sentV) {
            if(choice < 0 || choice > 2) {
                cout << "Your input sucks!";
                sentV = false;
            }
            else if(choice == 1) {
                cout << "\n\nNow listing Companies: \n\n" << endl;
                objectOne.listStocks();
                sentV = false;
            }
            else if(choice == 2) {
                cout << "Beginning the Game...\n" << endl;
                gameMenu(objectOne);
                sentV = false;
            }
            else if(choice == 0) {
                sentV = false;
                exit(false);
            }
        }
    }
    return 0;
}
