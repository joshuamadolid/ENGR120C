/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
04/21/24
Project #4
*/

#include <stdio.h>
#include <stdlib.h>

//Define size to be 50
#define SIZE 50

/*
FUNCTION PROTOYPES
Fn = Function parameter variable (Less confusion with main function variables and my function variables)
FILE = For writing to the file
CON = For printing out to the console
*/

//Value-returning functions
int getInput(double *FnCurrentBalance, double *FnMonthlyPayment, double *FnInterestRate);

//Non value-returning functions
void printReport(char *FILEHeadline, char *FILETotal, char *FILETotalPayments, int FnPaymentsProc, double *FnMonthlyPayment, double *FnCurrentBalance, double *FnAnnualInterestRate, double *FnPrincipalAmount, double *FnInterestAmount, double *FnEndingBalance);
void printTotals(char *CONBegginingBalance, char *CONSumOfPayments, char *CONTotalPrincipalAmount, char *CONTotalInterestAmount, char *CONTotalEndingBalance, char *CONTotalPayment, int FnPaymentsProc, double *FnTotalPayments,  double *FnTotalBegginingBalance, double *FnTotalAmountAppliedtoPrincipal, double *FnTotalAmountAppliedtoInterest, double *FnTotalEndingBalance);

int main()
{
    //DECLARE VARIABLES

    //Declare important constants
    const int MONTHINYEAR = 12;
    const int ZERO = 0;
    const int CONVTODECI = 100;

    //Declare arrays with DMA
    double *currentBalance = (double*) malloc(SIZE * sizeof(double));
    double *endingBalance = (double*) malloc(SIZE * sizeof(double));
    double *interestRate = (double*) malloc(SIZE * sizeof(double));
    double *interestAmt = (double*) malloc(SIZE * sizeof(double));
    double *principalAmt = (double*) malloc(SIZE * sizeof(double));
    double *monthPayment = (double*) malloc(SIZE * sizeof(double));
    
    //Declare arrays of char for file write
    char *FILEHeadline = "Int Rate     Begin     Pmt     Princ    Interest    EndBal";
    char *FILETotal = "Total:";
    char *FILETotalPayments = "Number of payments processed:";
    
    //Declare arrays of char to print out to the console
    char *CONBegginingBalance = "Total of beginning balances: ";
    char *CONTotalEndingBalance =  "Total of ending balances: ";
    char *CONTotalInterestAmount = "Total of amounts applied to interest: ";
    char *CONTotalPrincipalAmount = "Total of amounts applied to principal: ";
    char *CONTotalPayments = "Total of payments: ";
    char *CONPaymentsProcessed = "Number of payments processed: ";

    //Declare other variables
    double monthlyIntRate;
    int paymentsProcCtr = ZERO;
    int i;

    //START

    //Invoke getInput function for paymentsProcessed to capture the int value
    paymentsProcCtr = getInput(currentBalance, monthPayment, interestRate);

    //Populate the arrays with for loop to go through all the payments processed
    for(i = 0; i < paymentsProcCtr; i++)
    {
        //Calculate the monthly interest rate, which is the interest rate divided by 12, using its percentage
        monthlyIntRate = interestRate[i] / CONVTODECI / MONTHINYEAR;

        //Calculate the interest amount which is the current balance times the monthly interest rate
        interestAmt[i] = currentBalance[i] * monthlyIntRate;

        /*If the current balance and the principal amount is indeed less than the monthly payment,
        calculate your monthly payment and set your ending balance equal to -/
        */
        if(currentBalance[i] + principalAmt[i] < monthPayment[i])
        {
            monthPayment[i] = currentBalance[i] + interestAmt[i];
            principalAmt[i] = currentBalance[i];
            endingBalance[i] = ZERO;
        }
        //However, if it does go over, recalculate the principal amount that would pay off the loan
        else
        {
            principalAmt[i] = monthPayment[i] - interestAmt[i];
            endingBalance[i] = currentBalance[i] - principalAmt[i];
        }

        //At the subscript of paymentsProcessed, which should be the last, accumulate all the balances and payments
        currentBalance[paymentsProcCtr] += currentBalance[i];
        endingBalance[paymentsProcCtr] += endingBalance[i];
        interestAmt[paymentsProcCtr] += interestAmt[i];
        principalAmt[paymentsProcCtr] += principalAmt[i];
        monthPayment[paymentsProcCtr] += monthPayment[i];
    }

    //Invoke printTotals function to print out the data
    printTotals(CONBegginingBalance, CONTotalPayments, CONTotalPrincipalAmount, CONTotalInterestAmount, CONTotalEndingBalance, CONPaymentsProcessed, paymentsProcCtr, monthPayment, currentBalance, principalAmt, interestAmt, endingBalance);

    //Invoke printReport function to write to the file
    printReport(FILEHeadline, FILETotal, FILETotalPayments, paymentsProcCtr, monthPayment, currentBalance, interestRate, principalAmt, interestAmt, endingBalance);

    //Free up the memory
    free(currentBalance);
    free(endingBalance);
    free(interestRate);
    free(interestAmt);
    free(principalAmt);
    free(monthPayment);
    
    return ZERO;
    //End main
}

//FUNCTIONS

/*
getInput function

Be able to:

- Open the file 
- Validate the file's existence
- Use a while loop to scan in, and populate the array with elements
- Close the file
- Return the amount of loan transactions processed
*/
int getInput(double *FnCurrentBalance, double *FnMonthlyPayment, double *FnInterestRate)
{
    //Declare variables
    int loanTransCtr = 0;

    //Declare file pointer
    FILE *inputFile;

    //Open the file
    inputFile = fopen("Project4Loandata.txt", "r");

    //Validate the file's existence, if not print out a statement 
    if(inputFile == NULL)
    {
        printf("Unable to open input file. \n");
        return 1;
    }

    //Use a while loop to scan, and populate the arrays with the elements
    while(fscanf(inputFile, "%lf %lf %lf", &FnCurrentBalance[loanTransCtr], &FnMonthlyPayment[loanTransCtr], &FnInterestRate[loanTransCtr]) != EOF)
        loanTransCtr++;
    
    //Close the file
    fclose(inputFile);

    //Return the total number of loan transcations
    return loanTransCtr;
}

/*
printReport function

Be able to:

- Open a file under my name
- Validate the file's existence
- Write to the file (respecting spacing)
- Start off with the file's header
- Use a for loop, to print out the data
- Print out the accumulators, for current balance, monthly payment, principal interest rate, interest rate, and ending balance
- Close file
- Do not return anything
*/
void printReport(char *FILEHeadline, char *FILETotal, char *FILETotalPayments, int FnPaymentsProc, double *FnMonthlyPayment, double *FnCurrentBalance, double *FnAnnualInterestRate, double *FnPrincipalAmount, double *FnInterestAmount, double *FnEndingBalance)
{
    //Declare variables
    int i;
    
    //Declare pointer for file
    FILE *outputFile;

    //Open the file
    outputFile = fopen("JoshuaMadolidProject4OUT.txt", "w");

    //Validate the file's existence, if not print out a statement that says file not found
    if(outputFile == NULL)
    {
        printf("Unable to open input file. \n");
        exit(0);
    }

    //Print out the header
    fprintf(outputFile, "%s\n", FILEHeadline);

    //Use a for loop, to traverse through the parallel arrays and print out the data
    for(i = 0; i < FnPaymentsProc; i++)
        fprintf(outputFile, "%7.2f %11.2f %8.2f %8.2f %8.2f %13.2f\n", FnAnnualInterestRate[i], FnCurrentBalance[i], FnMonthlyPayment[i], FnPrincipalAmount[i], FnInterestAmount[i], FnEndingBalance[i]);
    

    //Respecting the spacing, print the needed components
    fprintf(outputFile, "\n  %s %1s%8.2f %8.2f %8.2f %8.2f %13.2f\n", FILETotal, "", FnCurrentBalance[FnPaymentsProc], FnMonthlyPayment[FnPaymentsProc], FnPrincipalAmount[FnPaymentsProc], FnInterestAmount[FnPaymentsProc], FnEndingBalance[FnPaymentsProc]);

    //Print out the amount of payments processed
    fprintf(outputFile, "%s%d\n", FILETotalPayments, FnPaymentsProc);

    //Close the file
    fclose(outputFile);
}

/*
printTotals function

Be able to:

- Print out the data to the console
- Prints out the header and prints out the rest of the data
- Does not return anything
*/
void printTotals(char *CONBegginingBalance, char *CONSumOfPayments, char *CONTotalPrincipalAmount, char *CONTotalInterestAmount, char *CONTotalEndingBalance, char *CONTotalPayment, int FnPaymentsProc, double *FnTotalPayments,  double *FnTotalBegginingBalance, double *FnTotalAmountAppliedtoPrincipal, double *FnTotalAmountAppliedtoInterest, double *FnTotalEndingBalance)
{
	//Print all the data to the screen
	printf("\n%40s $%11.2f\n", CONBegginingBalance, FnTotalBegginingBalance[FnPaymentsProc]);
	printf("%40s $%11.2f\n", CONSumOfPayments, FnTotalPayments[FnPaymentsProc]);
	printf("%40s $%11.2f\n", CONTotalPrincipalAmount, FnTotalAmountAppliedtoPrincipal[FnPaymentsProc]);
	printf("%40s $%11.2f\n", CONTotalInterestAmount, FnTotalAmountAppliedtoInterest[FnPaymentsProc]);
	printf("%40s $%11.2f\n\n", CONTotalEndingBalance, FnTotalEndingBalance[FnPaymentsProc]);
    printf("%10s%6s %6d\n","", CONTotalPayment, FnPaymentsProc);
}