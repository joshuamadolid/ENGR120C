/*
Joshua Madolid
Engrg 120C
Instructor: Mimi Rasky
2/7/2024
Project #1
*/

#include <stdio.h>
int main()
{
    // Declare variables needed for calculations
    double currentbalance, monthlypaymentamount, annualinterest;
    double monthdecinterestrate, interestamount, amountpayingloan, endingbalance;
    
    //Prompts the user to enter their financial information
    printf("Enter current balance in dollars and cents: ");
    scanf("%lf", &currentbalance);
    printf("Enter monthly payment in dollars and cents: ");
    scanf("%lf",&monthlypaymentamount);
    printf("Enter annual interest rate in percent form (ex: 8.75): ");    
    scanf("%lf",&annualinterest);
    
    // Calculates interest rates and balances
    monthdecinterestrate = annualinterest / 100 / 12;
    interestamount = currentbalance * monthdecinterestrate;
    amountpayingloan = monthlypaymentamount - interestamount;
    endingbalance = currentbalance - amountpayingloan;
    
    /* 
    Displays the results to the screen using format specifiers.
    Started a new line to make the outputted text more organized
    */
   
    printf("\n          Annual interest rate:        %8.2f%%\n", annualinterest);
    printf("             Beginning Balance: $      %8.2f\n", currentbalance);
    printf("             Amount of payment: $      %8.2f\n", monthlypaymentamount);
    printf("   Amount applied to principal: $      %8.2f\n", amountpayingloan);
    printf("    Amount applied to interest: $      %8.2f\n", interestamount);
    printf("                Ending balance: $      %8.2f\n", endingbalance);

    return 0;
}






