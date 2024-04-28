/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
3/22/2024
Project #3
*/

#include <stdio.h>

// Value returning function prototypes
double getCurrentbalance();
double getMonthlypay();
double getAnnualintrate();

// Non-value returning function prototypes
void printLoan(double fcurrentbalance, double fmonthlypaymentamount, double fmonthdecinterestrate, double fannualinterest, double fprincipalamount, double finitialamount, double fendingbalance);
void printTotal(double ftotalPayments, double ftotalBegginingbalance, double ftotalAppliedPrincipal, double ftotalAppliedInterest, double ftotalEndingbalance, int fpaymentsProcessed);

int main() 
{
    //Declare variables

    //Important constants
    const int ZERO = 0;
    const int MONTHSINYEAR = 12;
    const int CONVDECI = 100;

    // Total accumulators
    double totalBeginningBalance = ZERO, totalPayments = ZERO, totalAppliedPrincipal = ZERO;
    double totalAppliedInterest = ZERO, totalEndingBalance = ZERO;
    int paymentsProcessed = ZERO;

    //User inputted values + values for formulas
    double currentBalance, monthlyPayment, annualInterestRate;
    double principalAmount, endingBalance;
    double monthlyInterestRate, interestAmount;
    
    //Invoke getCurrentbalance function, PRIMING READ
    currentBalance = getCurrentbalance();

    //Enter while loop
    while (currentBalance != ZERO) 
    {
        //Invoke getMonthlypay function to get monthlypayment
        monthlyPayment = getMonthlypay();

        //Invoke getAnnualintrate function to get annualInterestRate
        annualInterestRate = getAnnualintrate();

        //Formulas from previous project

        //MonthlyInterestRate is annual interest rate divided by 12, turning into decimals
        monthlyInterestRate = annualInterestRate / MONTHSINYEAR / CONVDECI;
        //Interest amount is your current balance times the monthly interest rate
        interestAmount = currentBalance * monthlyInterestRate;

        //Executes if monthly payment exceeds the sum
        if(monthlyPayment > currentBalance + interestAmount)
        {
            //Recalculate monthly payment to accurately pay off loan (interest amount plus the current balance)
            monthlyPayment =  currentBalance + interestAmount;

            //Recalculate/set principalamount to equal the current balance
            principalAmount = currentBalance;
        }
        
        //Runs if currentbalance and interest amount does not exceed the monthly payment amount
        else
        {
            //Recalculate principal amount to pay off loan
            principalAmount = monthlyPayment - interestAmount;

            //Recalculate/set ending balance (The difference of the currentbalance and the newly calculated principal amount)
            endingBalance = currentBalance - principalAmount;
        }

        //Invoke PrintLoan function to print the current loan data
        printLoan(currentBalance, monthlyPayment, monthlyInterestRate, annualInterestRate, principalAmount, interestAmount, endingBalance);

        // ACCUMULATOR ADDING
        totalBeginningBalance += currentBalance;
        totalPayments += monthlyPayment;
        totalAppliedPrincipal += principalAmount;
        totalAppliedInterest += interestAmount;
        totalEndingBalance += endingBalance;
        paymentsProcessed++;

        //Reprompt user (0 will quit)
        currentBalance = getCurrentbalance();
    }

    // Print the totals from all the loans
    printTotal(totalPayments, totalBeginningBalance, totalAppliedPrincipal, totalAppliedInterest, totalEndingBalance, paymentsProcessed);

    return ZERO;
}

//FUNCTIONS

//getCurrentbalance function, for scanning in current balance and returning it
double getCurrentbalance() 
{
    double fcurrentBalance;

    //Prompt and grab current balance
    printf("Enter the current in dollars and cents: ");
    scanf("%lf", &fcurrentBalance);

    return fcurrentBalance;
}

//getMonthlypay function, for scanning in monthly payment and returning it
double getMonthlypay() 
{
    double fmonthlyPayment;

    //Prompt and grab monthly payment
    printf("Enter the monthly payment in dollars and cents: ");
    scanf("%lf", &fmonthlyPayment);

    return fmonthlyPayment;
}

//getAnnualintrate, for scanning annual interest rate and returning it
double getAnnualintrate() 
{
    double fannualInterestRate;

    //Prompt and grab annual interest rate
    printf("Enter the annual interest rate in percent form (ex: 8.75): ");
    scanf("%lf", &fannualInterestRate);

    return fannualInterestRate;
}

//printLoan function, used for taking in the current data in the while loop in the main function, and displaying it
void printLoan(double fcurrentbalance, double fmonthlypaymentamount, double fmonthdecinterestrate, double fannualinterest, double fprincipalamount, double finitialamount, double fendingbalance) 
{
    //Display data using format specifiers
    printf("%36s%16.2f%%\n", "Annual interest rate: ", fannualinterest);
    printf("%36s%4s%12.2f\n", "Beginning Balance: ", "$", fcurrentbalance);
    printf("%36s%4s%12.2f\n", "Amount of payment: ", "$", fmonthlypaymentamount);
    printf("%36s%4s%12.2f\n", "Amount applied to principal: ", "$", fprincipalamount);
    printf("%36s%4s%12.2f\n", "Amount applied to interest: ", "$", finitialamount);
    printf("%36s%4s%12.2f\n\n", "Ending balance: ", "$", fendingbalance);

    //Do not return anything, since the task of this function is just to print
}

//printTotal function, used in the end where display all the data, after being accumulated
void printTotal(double ftotalPayments, double ftotalBegginingbalance, double ftotalAppliedPrincipal, double ftotalAppliedInterest, double ftotalEndingbalance, int fpaymentsProcessed) 
{
    //Display data using format specifiers
    printf("\n%40s$%11.2f\n", "Total of beginning balances:  ", ftotalBegginingbalance);
    printf("%40s$%11.2f\n", "Total of payments:  ", ftotalPayments);
    printf("%40s$%11.2f\n", "Total of amounts applied to principal:  ", ftotalAppliedPrincipal);
    printf("%40s$%11.2f\n", "Total of amounts applied to interest:  ", ftotalAppliedInterest);
    printf("%40s$%11.2f\n\n", "Total of ending balances:  ", ftotalEndingbalance);
    printf("%38s%11d\n", "Number of payments processed:", fpaymentsProcessed);

    //Do not return anything, since the task of this function is just to print
}
