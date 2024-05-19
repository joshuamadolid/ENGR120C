/*
Joshua Madolid     
Engrg 120C
Professor Mimi Rasky         
5/4/24      
Project 6
*/

//Include libaries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Account.h"

using namespace std;

//Non-value returning function prototypes
void printReport(Account ra[]);
void getInput(Account ra[]);

//Enter main
int main()
{
    //Declare variables
    const int RASIZE = 50;

    //Declare an array of Account objects of size 50
    Account array[RASIZE];

    //Invoke getInput function
    getInput(array);

    //Invoke printReport function
    printReport(array);

    return 0;
}

/*
getInput function

Be able to:
- Declare an object for input
- Open the file
- Validate the file's existence
- Populate the array of objects with the data in ORDER
- Close the file
*/
void getInput(Account ra[])
{
    //Declare variables

    //Declare the object for input
    ifstream inputFile;

    //Variables for storing data
    double currBal, monthlyPay, annInt;

    //Open the file
    inputFile.open("Project6Loandata.txt");

    //Validate file's existence, if unable to open, print "Unable to open file"
    if(!inputFile)
    {
        printf("Unable to open file. \n");
        //Terminate program if unable to open JOSH
        exit(0);
    }

    /*As the file is open, use a while loop to read the loan data, and populate the account array
    The while loop will keep looping until there is no more data to read.The numMade static
    variable is treated like your 'i' or 'ctr' to traverse through the subscripts of the array,
    and will also be used to store the amount of objects there are
    */
    while(inputFile >> currBal >> monthlyPay >> annInt)
    {
        ra[Account::numMade] = Account(currBal, monthlyPay, annInt);
        Account::numMade++;
    }

    //CLOSE THE FILE JOSH
    inputFile.close();
}

/*
printReport function

Be able to:
- Declare an object for input
- Open the file
- Validate the file's existence
- Populate the array of objects with the data in ORDER
- Close the file
*/
void printReport(Account ra[])
{
    //Declare variables, setting all accumulators to 0
    int i;
    double totalCurrentBalance = 0;
    double totalEndingBalance = 0; 
    double totalInterestAmount = 0;
    double totalMonthlyPayment = 0;
    double totalPrincipalAmount = 0;
    
    //Get the number of loansProcessed (number of account objects)
    int numLoansProcessed = Account::numMade;

    //Declare object for outputting the data
    ofstream outputFile;

    //Open file
    outputFile.open("JoshuaMadolidProject6OUT.txt");

    //Validate file's existence, if unable to open, print "Unable to open file"
    if(!outputFile)
    {
        printf("Unable to open file. \n");
        //Terminate program if unable to open JOSH
        exit(0);
    }

    //Set formatting for the data
    outputFile << setprecision(2) << fixed;

    //Print out header
    outputFile << "Int Rate     Begin       Pmt     Princ   Interest     EndBal" << endl;
    
    /*
    WITHIN THE FOR LOOP
    - Write to the file
    - Using setw() for spacing of data
    - Accumulate the sums by adding each of the data in the subscripts to variable
    */

    for(i = 0; i < numLoansProcessed; i++)
    {
        //Write to file 
        outputFile << setw(7) << ra[i].annualInterestRate << setw(13) << ra[i].currentBalance << setw(10) << ra[i].monthlyPayment;
        outputFile << setw(9) << ra[i].principalAmount << setw(9) << ra[i].interestAmount << setw(13) << ra[i].endingBalance << endl;
        
        //Accumulate all the variables
        totalCurrentBalance += ra[i].currentBalance;
        totalMonthlyPayment += ra[i].monthlyPayment;
        totalPrincipalAmount += ra[i].principalAmount;
        totalInterestAmount += ra[i].interestAmount;
        totalEndingBalance += ra[i].endingBalance;
    }

    //After the for loop, print out the sum of the data
    outputFile << endl << "Total:    " << setw(9) << totalCurrentBalance << setw(9) << totalMonthlyPayment << setw(9) << totalPrincipalAmount;
    outputFile << setw(9) << totalInterestAmount << setw(13) << totalEndingBalance << endl;
    outputFile << "Number of payments processed:                " << numLoansProcessed;
    
    //Print to the console the sum of all the data
    cout << setprecision(2) << fixed;
	cout << endl << setw(39) << "  Total of beginning balances:" << "  " << "$" << setw(10) << totalCurrentBalance << endl;
    cout << setw(39) << "Total of payments:" << "  " << "$" << setw(10) << totalMonthlyPayment << endl;
    cout << setw(39) << "Total of amounts applied to principal:" << "  " << "$" << setw(10) << totalPrincipalAmount << endl;
    cout << setw(39) << "  Total of amounts applied to interest:" << "  " << "$" << setw(10) << totalInterestAmount << endl;
    cout << setw(39) << "  Total of ending balances:" << "  " << "$" << setw(10) << totalEndingBalance << endl;
    cout << setw(39) << "Number of payments processed:" << "  " << setw(8) << numLoansProcessed << endl;

    //CLOSE FILE JOSH
    outputFile.close();
}