//file name: portfolio.h
#ifndef PORTFOLIO
#define PORTFOLIO

#include "dopewars.h"

using namespace std;

class Portfolio{
    public:
            Portfolio();
            void acctVal();
            void buyCompany();
            void sellCompany();
            void setDifficulty();
            void listStocks();
            void purchase();
            void setAccount(double);
            double getAccount() const;
            vector<Stocks> getcompaniesOwned() const;
    private:
            double account;
            vector<Stocks> oneVectorToRuleThemAll;
            vector<Stocks> companiesOwned;
            void portVector();
};
/**
 * constructor
*/
Portfolio::Portfolio(){
    acctVal();
    portVector();
}

/**
 * setter for account
*/
void Portfolio::setAccount(double newAccount){
    account = newAccount;
}

/**
 * getter for account
*/
double Portfolio::getAccount() const {
    return account;
}

/**
 * Getter functions
*/
vector<Stocks> Portfolio::getcompaniesOwned() const {
    return companiesOwned;
}

/**
 * opens imported stock file
*/
void Portfolio::portVector() {
    ifstream fin;
    fin.open("companies.txt");
    while(fin.good()) {
        oneVectorToRuleThemAll.push_back(Stocks(fin));
    }
}

/**
 * communicates with other functions
*/
void Portfolio::listStocks() {
        for(unsigned i = 0;i < oneVectorToRuleThemAll.size();i++){
            cout << i+1 << "# ";
            oneVectorToRuleThemAll[i].print();
    }
}

//assistance from Matthew/Jacob: Stem Tutor
/**
 * Purchases the companies 
 * communicates with other functions
 * puts them in vector Companies Owned
*/
void Portfolio::buyCompany() {
    if(oneVectorToRuleThemAll.size() == 0) {
        cout << "nothing to buy";
    }
    for(unsigned i = 0;i < oneVectorToRuleThemAll.size();i++){
        cout << "COMPANY "<< i+1 << ". ";
        oneVectorToRuleThemAll[i].print();
    }
    cout << "What do you want to buy(enter in #)?" << endl;
    int initialVar = 0;
    cin >> initialVar;
    if(cin.fail() || initialVar > int(oneVectorToRuleThemAll.size()) || initialVar <= 0) {
        cout << "your input sucks...terminating program" << endl;
        exit(-1);
    }
    initialVar--;
    Stocks vectorCompany = oneVectorToRuleThemAll[initialVar];
    double savedPrice = vectorCompany.getPrice();
    if(account < savedPrice){
        cout << "Not enough money.";
        return;
    }
    else if(account >= savedPrice){
        double newVal;
        newVal = account - savedPrice;
        cout << newVal;
        account = newVal;
    }
    companiesOwned.push_back(vectorCompany);
    swap(oneVectorToRuleThemAll[initialVar], oneVectorToRuleThemAll[oneVectorToRuleThemAll.size() - 1]);
    oneVectorToRuleThemAll.pop_back();
}

//assistance from Matthew/Jacob: Stem Tutor
/**
 * Provides link to vector with companynames
 * 
*/
void Portfolio::sellCompany() {
        if(companiesOwned.size() == 0) {
        cout << "nothing to buy";
    }
    for(unsigned i = 0;i < companiesOwned.size();i++){
        cout << "COMPANY "<< i+1 << ". ";
        companiesOwned[i].print();
    }
    cout << "Please select the company you wish to sell from: " << endl;
    int initialVar = 0;
    cin >> initialVar;
    if(cin.fail() || initialVar > int(companiesOwned.size()) || initialVar <= 0) {
        cout << "your input sucks...terminating program" << endl;
        exit(-1);
    }
    initialVar--;
    Stocks vectorCompany = companiesOwned[initialVar];
    double savedPrice = vectorCompany.getPrice();
    double newVal;
    newVal = account + savedPrice;
    cout << newVal;
    account = newVal;

    oneVectorToRuleThemAll.push_back(companiesOwned[initialVar]);
    swap(companiesOwned[initialVar], companiesOwned[companiesOwned.size() - 1]);
    companiesOwned.pop_back();
}



/**
 * Holds the account value of the user
*/
void Portfolio::acctVal() {
    account = 0.0;
    cout << "Please enter your initial account value: ";
    cin >> account;
}



#endif /*PORTFOLIO.h*/
