/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
04/30/24
Project #5
*/

#include <stdio.h>
#include <stdlib.h>

//Structure for Loan
typedef struct 
{
    double currentBalance;
    double endingBalance;
    double monthlyPayment;
    double annualInterestRate;
    double principalAmount;
    double interestAmount;
} LOAN;

//Value returning function prototypes
int getInput(LOAN *ra);

//Non-value returning function prototypes
void printReport(LOAN *ra, int FnPaymentsProc, char *FILEHeadline, char *FILETotal, char *FILETotalPayments, char *FnTotalBegginingBalance, char *FnTotalPayments, char *FnTotalPrincipalAmount, char *FnTotalInterestAmount, char *FnTotalEndingBalance, char *FnTotalPayment);

int main()
{
    //Declare variables
    int const MONTHINYEAR = 12;
    int const ZERO = 0;
    int const CONVTODECI = 100;
    int const SIZEOFRA = 100;
    double monthlyInterestRate;
    int i, numLoans = 0;

    

    //Create an array of structures
    LOAN loanRa[SIZEOFRA];

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

    //Invoke getInput to capture the number of loans
    numLoans = getInput(loanRa);

    for(i = 0; i < numLoans; i++)
    {
        //Calculate monthly interest rate, which is your annual interest rate divided by twelve, converted to a percentage
        monthlyInterestRate = loanRa[i].annualInterestRate / CONVTODECI / MONTHINYEAR;

        //Calculate interest amount, which is your current balance times the monthly interest rate
        loanRa[i].interestAmount = loanRa[i].currentBalance * monthlyInterestRate;

        //If conditions to check if the borrower's payment (current balance with the interest amount) is more than the monthly payment
        if(loanRa[i].currentBalance + loanRa[i].interestAmount < loanRa[i].monthlyPayment)
        {
            //Recalculate your monthly payment to successfully pay off loan
            loanRa[i].monthlyPayment = loanRa[i].currentBalance + loanRa[i].interestAmount;
            //Reset principalAmount to the current balance
            loanRa[i].principalAmount = loanRa[i].currentBalance;
            //Reset ending balance to equal 0
            loanRa[i].endingBalance = ZERO;
        }
        else
        {
            //Calculate principal amount to pay off loan
            loanRa[i].principalAmount = loanRa[i].monthlyPayment - loanRa[i].interestAmount;

            //Recalculate ending balance
            loanRa[i].endingBalance = loanRa[i].currentBalance - loanRa[i].principalAmount;
        }
    }

    printReport(loanRa, numLoans, FILEHeadline, FILETotal, FILETotalPayments, CONBegginingBalance, CONTotalPayments, CONTotalPrincipalAmount, CONTotalInterestAmount, CONTotalEndingBalance, CONPaymentsProcessed);

    return ZERO;
}
//FUNCTIONS

/*
getInput function:

Will be able to:
- Declare a file structure pointer
- Open the file
- Read from the file
- Use a while loop, to populate the array of structures
- Return the number of loans proccessed
*/
int getInput(LOAN *ra)
{
    //Declare file pointer, and variables
    FILE *inputFile;
    
    int loanTransCtr = 0;

    //Open the file
    inputFile = fopen("EC-Project5-loanDataLong.txt", "r");

    //Validate the file's existence, if not print out a statement 
    if(inputFile == NULL)
    {
        printf("Unable to open input file. \n");
        exit(0);
    }

    //Use a while loop to scan, and populate the arrays with the elements
    while(fscanf(inputFile, "%lf %lf %lf", &ra[loanTransCtr].currentBalance, &ra[loanTransCtr].monthlyPayment, &ra[loanTransCtr].annualInterestRate) != EOF)
    {
        //Accumulate the loan transcation counter to calculate the amount of loans processed
        loanTransCtr++;
    }
    
    //Close the file JOSH
    fclose(inputFile);

    return loanTransCtr;
}

/*
printReport Function

Be able to:
- Declare a file pointer
- Open the file
- Write to the file with the data from the array of structures
- Accumulate the totals for current balance, ending balance, monthly payment, principal amount, interest amount
- Write to the file
- Print to the console
*/

void printReport(LOAN *ra, int FnPaymentsProc, char *FILEHeadline, char *FILETotal, char *FILETotalPayments, char *FnTotalBegginingBalance, char *FnTotalPayments, char *FnTotalPrincipalAmount, char *FnTotalInterestAmount, char *FnTotalEndingBalance, char *FnTotalPayment)
{
    //Declare variables

    //SET THESE EQUAL TO 0 SINCE THESE ARE ACCUMULATORS JOSH
    double totCurrentBalance = 0, totEndingBalance = 0;
    double totMonthlyPayment = 0, totPrincipalAmount = 0;
    double totInterestAmount = 0;
    int i;

    //Declare file pointer to output file
    FILE *outputFile;

    //Open up the file with the intentions of writing "w"
    outputFile = fopen("JoshuaMadolidProject5OUT.txt", "w");

    //Validate file's existence, if not terminate
    if(outputFile == NULL)
    {
        printf("Unable to open output file. \n");
        exit(0);
    }

    fprintf(outputFile, "%s\n", FILEHeadline);

    for(i = 0; i < FnPaymentsProc; i++)
    {
        //Write to the file 
        fprintf(outputFile, "%7.2lf %11.2lf %8.2lf %8.2lf %8.2lf %13.2lf\n", ra[i].annualInterestRate, ra[i].currentBalance, ra[i].monthlyPayment, ra[i].principalAmount, ra[i].interestAmount, ra[i].endingBalance);
        
        //Add up values from these structures to the accumulators
        totCurrentBalance += ra[i].currentBalance;
        totMonthlyPayment += ra[i].monthlyPayment;
        totPrincipalAmount += ra[i].principalAmount;
        totInterestAmount += ra[i].interestAmount;
        totEndingBalance += ra[i].endingBalance;
    }

    //Write to the file, the total for the current balances, monthly payment, principal amounts, interest amounts, and ending balance
    fprintf(outputFile, "\n%3s%s %8.2f %8.2f %8.2f %8.2f %13.2f\n", "",FILETotal, totCurrentBalance, totMonthlyPayment, totPrincipalAmount, totInterestAmount, totEndingBalance);
    fprintf(outputFile, "%3s%13s%d\n", FILETotalPayments,"", FnPaymentsProc);

    //Close output file JOSH
    fclose(outputFile);

    //Print to the console the totals
    printf("\n%40s $%11.2lf\n", FnTotalBegginingBalance, totCurrentBalance);
	printf("%40s $%11.2lf\n", FnTotalPayments, totMonthlyPayment);
	printf("%40s $%11.2lf\n", FnTotalPrincipalAmount, totPrincipalAmount);
	printf("%40s $%11.2lf\n", FnTotalInterestAmount, totInterestAmount);
	printf("%40s $%11.2lf\n", FnTotalEndingBalance, totEndingBalance);
    printf("%10s%3s %6d\n","", FnTotalPayment, FnPaymentsProc);
}








