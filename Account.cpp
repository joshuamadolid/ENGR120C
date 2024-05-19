#include "Account.h"
#include <iostream>
using namespace std;

/*
Set accumulator for int variable member of Account equal to 0, 
we will utilize this in the main file
*/
int Account::numMade = 0;
 
//Default Constructor Definition
Account::Account()
{
    currentBalance = 0;
    monthlyPayment = 0;
    annualInterestRate = 0;
    interestAmount = 0;
    principalAmount = 0;
    endingBalance = 0;
}

//Special Constructor (Not Default) Definiton
Account::Account(double FnCurrentBal, double FnMonthlyPayment, double FnAnnualIntRate)
{
    //Set member variables to parameters
    currentBalance = FnCurrentBal;
    monthlyPayment = FnMonthlyPayment;
    annualInterestRate = FnAnnualIntRate;

    //Invoke setTheOthers to calculate the rest of the OTHER variables
    setTheOthers();
}
void Account::setTheOthers()
{
    //Declare variables
    double monthlyIntRate;
    
    //Calculate the monthly INTEREST RATE
    //The annual interest rate divided by 12 (for months) converted to a percentage
    monthlyIntRate = annualInterestRate / 100 / 12;

    //Calculate INTEREST AMOUNT
    //The current balance multiplied by the monthly interest rate
    interestAmount = currentBalance * monthlyIntRate;

    //IF statements to check if the borrower's payment exceeds the amount needed to pay
    //These If statements are from the previous project
    
    if(currentBalance + interestAmount < monthlyPayment)
    {
        //Monthly payment adjustment
        monthlyPayment = currentBalance + interestAmount;

        //Principal Amount will be recalculated 
        principalAmount = currentBalance;

        //Set ending balance equal to 0
        endingBalance = 0;
     }
     else
     {
        //Get the amount needed to pay off the loan
        principalAmount = monthlyPayment - interestAmount;
        //Set ending balance
        endingBalance = currentBalance - principalAmount;
    }
}