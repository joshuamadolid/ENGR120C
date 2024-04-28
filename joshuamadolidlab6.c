/*
Joshua Madolid
Engrg 120C
Instructor: Mimi Rasky
3/20/2024
Lab #6
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//Function prototype
long long myDifference (long long n);
bool nonDecreasing (long long n);

//Start main
int main()
{
    //Declare variables
    long long value, myDif, nonDec;

    //Prompt user, input is STORED into 'value'
    printf("Please enter a long integer (0 to quit): ");
    scanf("%lld", &value);

    //Enter while loop
    while (value != 0)
    {
        //Invoke functions

        //myDifference is a 'long' value returning function that will be stored in myDif
        myDif = myDifference(value);

        //nonDec is a 'bool' value returning function that will be stored in nonDec
        nonDec = nonDecreasing(value);

        //Output
        printf("You entered: %lld\n", value);
        printf("myDifference(num): %lld\n", myDif);
        printf("nonDecreasing(num): ");

        //if nonDec returns true, will print true
        if (nonDec)
            printf("true\n");

        //if nonDec returns false, will print false
        else
            printf("false\n");

        //Prompt for end of while loop
        printf("\nPlease enter a long integer (0 to quit): ");
        scanf("%lld", &value);
    }

    return 0;
}

//Functions

long long myDifference (long long n)
{
    //Declare variables
    long long weirdSum = 0, product = 1, digit;
    
    /* bool numisNegative is used to determine whether the value is less than 0
    Because we want to deal with only positive numbers, it will be a lot easier to deal with
    If the number is negative, it will correctly display the output as negative*/
    bool numisNegative = false;

    /* As the bool value for 'numisNegative' is set to false as default
    it will be set to true and multiplied by negative 1 to deal with the absolute value */
    if (n < 0)
    {
        numisNegative = true;
        n = -n;
    }
        
    //Enter while loop
    while(n != 0)
    {   
        //Strip the rightmost digit 
        digit = n % 10;

        //Checks for odd numbers, ENSURES WE DEAL WITH ONLY ODD NUMBERS
        if (digit % 2 != 0)
        {
            //Enter nested if loop

            //If the digit is less than 5, we multiply by 10 first, before adding it to the weirdSum
            if (digit < 5)
                weirdSum += (digit * 10);
            
            //If the digit is 5, then we add it to the weirdSum
            else if(digit == 5)
                weirdSum += digit;
            
            //If the digit is greater than 5, we square it and then we add it to weirdSum
            else
                weirdSum += pow(digit, 2);
        }

        //Finds the product, ONLY IF IT IS A NONZERO NUMBER
        if (digit != 0)
            product *= digit;
        
        //Cuts off the rightmost digit
        n /= 10;      
    }
    //End while loop
    
    /* If the boolean for numisNegative is true, we will ensure it's product is negative
    IF NOT, we set numisNegative to false as default*/
    if (numisNegative)
        product *= -1;

    //Returns the positive difference
    return (labs(weirdSum - product));
}


bool nonDecreasing (long long n)
{
    //Declare variables
    long long digit;

    //Set boolVal as true AS DEFAULT
    bool boolVal = true;
    int ctr = 0;

    /* If the digit is a negative number, multiply by -1
    ENSURES we deal with positive value only */
    if (n < 0)
        n = -1 * n;

    //Start while loop 
    while (n != 0)
    {
        //Take the rightmost digit
        digit = n % 10;

        /* with the boolVal set to true, we automatically assume all the values are decreasing!
        this IF statement, compares the 2ND rightmost digit to the rightmost digit. 
        IF the value of the 2ND rightmost digit is greater than the RIGHTMOST digit, we can 
        conclude this value is nondecreasing, setting the boolVal to false */
        if((n / 10) % 10 > digit)
            boolVal = false;
        
        //Kills off the rightmost digit
        n /= 10;

        //This counter checks specifically if the number is singular
        ctr++;
    }

    /* If the counter is only increased once, meaning equal to one, the user only inputted one number
    Therefore, it is a nondecreasing value, meaning it is false*/
    if (ctr == 1)
        boolVal = false;

    return boolVal;
}