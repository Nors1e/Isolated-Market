//file name: dopewars.h
#ifndef DOPEWARS 
#define DOPEWARS
#include <iostream>
#include <fstream>

using namespace std;
//********Class Stocks********
class Stocks{
    public:
            Stocks();
            Stocks(string,double,double);
            Stocks(string,double,double,int);
            Stocks(ifstream&);
            void read(ifstream& fin);
            void print();
            void writeFile(string fileName);
            void readFile(ifstream&);
            void write(ofstream&);
            void writeFile(vector<Stocks>& oneVectorToRuleThemAll, string fileName);
            void setPrice(double);
            double getPrice() const;
    private:
            string companyName;
            double price;
            double performance;
            int account;
};

void Stocks::setPrice(double newPrice){
        price = newPrice;
}

double Stocks::getPrice() const{
        return price;
}

/**
Initialization of constructor definitions
*/
Stocks::Stocks() {
    companyName = "None";
    price = 0.00;
    performance = 0.0;
    account = 0;
}

/**
 * constructor for stocks
*/
Stocks::Stocks(string newcompanyName,double newPrice,double newPerformance,int newAccount){
    companyName = newcompanyName;
    price = newPrice;
    performance = newPerformance;
    account = newAccount;
}

/**
 * Assists with fileStream insertion with read/write functions 
 * for vectors
*/
Stocks::Stocks(ifstream& fin){
        readFile(fin);
}

/**
prints the company names and prices
& works with other functions
*/
void Stocks::print(){
    cout << companyName << endl;
    cout << price << endl;
}

/**
reads the company data including name and price from the file
@param fout
*/
void Stocks::write(ofstream& fout) {
    fout << companyName << endl;
    fout << price << endl;
}

/**
    reads the file data and places it into a vector of objects containing company names
    & price
    @param vector oneVectorToRuleThemAll
    @param string fileName
*/
void Stocks::writeFile(vector<Stocks>& oneVectorToRuleThemAll, string fileName) //retrieved from notes
{
    ofstream fout(fileName);
    if (fout.fail())
    {
        cout << "Output file " << fileName << " failed to open.\n";
        exit(-1);
    }
    fout << fixed; // two decimal places
    for (unsigned i = 0; i < oneVectorToRuleThemAll.size(); i++)
    {
        oneVectorToRuleThemAll[i].print();
    }
    fout.close();
}

/**
Supporting function for our reading functions
*/
void Stocks::readFile(ifstream& fin) {
        fin >> ws;
        if (fin.good()) {
                getline(fin, companyName);
                fin >> price;
        }
}
//***************Class Stocks*****************
#endif /*DOPEWARS.h*/
