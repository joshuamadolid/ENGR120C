#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip> 

/*
class Account

Will be able to:

- Have six public instance variables 
(Current Balance, MonthlyPayment, Annual Interest Rate, Principal Amount, Ending Balance)
- One constructor with three parameters
- setTheOthers, has no parameters
*/
class Account
{
    public:
        double currentBalance;
        double endingBalance;
        double annualInterestRate;
        double monthlyPayment;
        double interestAmount;
        double principalAmount;

        int static numMade; //Static field class variable

        Account(); //Declare constructor, with three parameters both valued at double
        Account(double, double, double);

    private:
        void setTheOthers();

};
#endif