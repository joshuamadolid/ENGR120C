/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
2/26/2024
Project #2
*/

#include <stdio.h> 

int main()
{
    //Declaring important constants
    const int ZERO = 0;
    const int MONTHSINYEAR = 12;
    const int CONVDECI = 100;

    // Declare variables needed for calculations
    double currentbalance, monthlypaymentamount, annualinterest, begbalance;
    double monthdecinterestrate, interestamount, amountpayingloan, endingbalance = 0.0;

    //Counter variable to keep track of number of payments processed
    int paymentsprocessed = ZERO;

    //Priming read
    printf("Enter current balance in dollars and cents: ");
    scanf("%lf", &begbalance);

    //Enter the while loop
    while(begbalance != ZERO)
    {

        //Setting currentbalance to user's input, occurs beggining and near end of while loop
        currentbalance = begbalance;

        //Prompting and grabbing monthly payment amount and annual interest rate
        printf("Enter monthly payment in dollars and cents: ");
        scanf("%lf",&monthlypaymentamount);
        printf("Enter annual interest rate in percent form (ex: 8.75): ");    
        scanf("%lf",&annualinterest);
    
        //Formulas from previous project
        monthdecinterestrate = annualinterest / CONVDECI / MONTHSINYEAR;
        interestamount = currentbalance * monthdecinterestrate;
        amountpayingloan = monthlypaymentamount - interestamount;
    
        //Executes if monthly payment exceeds the sum
        if (monthlypaymentamount > currentbalance + interestamount)
        {
        
            //Amount applied to principal
            amountpayingloan = currentbalance;

            //Update current balance
            endingbalance = currentbalance - amountpayingloan;

            monthlypaymentamount = currentbalance + interestamount;
        }

        //Runs if currentbalance and interest amount does not exceed the monthly payment amount
        else 
        {
        
            //Amount applied to principal
            amountpayingloan = monthlypaymentamount - (currentbalance * monthdecinterestrate);
    
            //Amount applied to interest
            interestamount = monthlypaymentamount - amountpayingloan;

            //Update current balance
            currentbalance -= amountpayingloan;
            endingbalance = currentbalance;
        }

        //Prints out all values before asking user input again
        printf("\n          Annual interest rate:        %8.2f%%\n", annualinterest);
        printf("             Beginning Balance: $      %8.2f\n", begbalance);
        printf("             Amount of payment: $      %8.2f\n", monthlypaymentamount);
        printf("   Amount applied to principal: $      %8.2f\n", amountpayingloan);
        printf("    Amount applied to interest: $      %8.2f\n", interestamount);
        printf("                Ending balance: $      %8.2f\n", endingbalance);   
        
        //paymentsproccessed gets incremented every time it scans data from user
        paymentsprocessed++;
        
        printf("\nEnter current balance in dollars and cents (0 to quit): ");
        scanf("%lf", &begbalance);
    }

    printf("\nNumber of payments processed:                           %d\n", paymentsprocessed);
    
    return 0;
}






