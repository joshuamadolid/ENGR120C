/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
4/01/2024
Lab #7
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Non returning function prototypes
void printArray(int ra[], int size);
void evenOdd(int ra1 [], int ra2 [], int size);

//Returning function protoypes
int getTotal(int ra[], int size);
double getAverage(int ra[], int size);
int getHighest(int ra[], int size);
int getLowest(int ra[], int size);
bool containsInRange(int a [], int size, int x, int start, int end);
bool sum28(int ra[], int size);
int getMode(int ra[], int size);

int main()
{
    FILE *inputfile;
    
    //Declare variables
    int size, maxofArray, minofArray, sumofArray;
    int start, end, targetVal, mode;
    double arrayAverage;
      
    /*Declare a File pointer, then open the file. Your text file and its directory 
    path may be different, so be sure and have it match the
    location of YOUR file on your computer! */

    inputfile = fopen("dataArrayECLab7Sp24.txt", "r");

    if(inputfile == NULL)
    {
        printf("Unable to open input file.\n");
        return 1; //ends the main
    }

    //Use fscanf to scan the size from the file
    fscanf(inputfile, "%d", &size);

    //Now you can declare your arrays:
    int arrayOne [size], arrayTwo[size];

    //populate the first array with the remaining file values:
    for(int i = 0; i < size; i++)
    {
        fscanf(inputfile, "%d", &arrayOne[i]);
    }
    
    //START ORIGINAL 

    //print original ray by invoking the printArray function
    printf("Here is a printout of the original array:\n\n");
    printArray(arrayOne, size);

    //Invoke getTotal function to assign value to sumofArray
    sumofArray = getTotal(arrayOne, size);
    //Print out sumofArray, returned from the getTotal function
    printf("\n\nThe sum of all the elements in the array is: %d\n", sumofArray);

    //Invoke getAverage function to assign value to arrayAverage
    arrayAverage = getAverage(arrayOne, size);
    //Print out arrayAverage, returned from getAverage function
    printf("\nThe average of all the elements in the array is: %.2f\n", arrayAverage);

    //Invoke getHighest function to assign value to maxofArray
    maxofArray = getHighest(arrayOne, size);
    //Print out maxofArray, returned from getHighest function
    printf("\nThe max of all elements in the array is: %d\n", maxofArray);

    //Invoke getLowest function to assign value to minofArray
    minofArray = getLowest(arrayOne, size);
    //Print out minofArray, returned from getLowest function
    printf("\nThe min of all elements in the array is: %d\n\n", minofArray);

    //Invoke evenOdd function to set arrayTwo 
    evenOdd(arrayOne, arrayTwo, size);
    printf("Here is a printout of the new array where evens are first:\n\n");
    //Invoke printArray function to print out arrayTwo
    printArray(arrayTwo, size);

    //START FOR IN RANGE ELEMENT
    //Prompt user to grab, the targetVal (x), the start index and end index
    printf("\n\nWhat value to search for in the original array? ");
    scanf("%d", &targetVal);
    printf("Give the start index: ");
    scanf("%d", &start);
    printf("Give the end index: ");
    scanf("%d", &end);    
    printf("Invoking containsInRange: ");

    //Invoke containsInRange function, if returned true, will display true, else returns false
    if(containsInRange(arrayOne, size, targetVal, start, end))
        printf("true\n");
    else
        printf("false\n");

    //START FOR IN RANGE ELEMENT, FOR EVENS
    //Prompt user to grab, the targetVal (x), the start index and end index
    printf("\nWhat value to search for in the new even-odd array? ");
    scanf("%d", &targetVal);
    printf("Give the start index: ");
    scanf("%d", &start);
    printf("Give the end index: ");
    scanf("%d", &end);    
    printf("Invoking containsInRange: ");
    
    //Invoke containsInRange function, if returned true, will display true, else returns false
    if(containsInRange(arrayTwo, size, targetVal, start, end))
        printf("true\n\n");
    else
        printf("false\n\n");

    //START FOR SUM 28 Function
    printf("Invoking sum28: ");
    //Invoke sum28 function, if the function returns true, will print true. Else, print false.
    if(sum28(arrayTwo, size))
        printf("true\n\n");
    else
        printf("false\n\n");
    
    //Invoke getMode function to assign value to mode
    mode = getMode(arrayOne, size);
    //Print out mode, returned from the getModefunction
    printf("The mode of the array is: %d\n", mode);

    return 0;
}

void printArray(int ra[], int size)
{
    //Declare variables
    int i;
    
    //Enter for loop
    for (i = 0; i < size; i++)
    {
        //Walks through the whole array, printing out 10 values per row
        printf("%3d ", ra[i]);
        
        //If statements assigns a new line, if we reach the tenth value of the row
        if (i == size || (i + 1) % 10 == 0)
            printf("\n");
    }
}

int getTotal(int ra[], int size)
{
    //Variables
    int sum = 0;

    //Enter for loop
    for(int i = 0; i < size; i++)
    {
        //Walks through array, picking up all the values and adding them
        sum += ra[i];
    }
        
    //Return the sum
    return sum;
}
double getAverage(int ra[], int size)
{
    //Variables
    double average;

    //Average is the sum of the values, divided by the number of values

    //We cast the value of invoking the getTotal function for the sum, avoiding int division
    //Then we divide by the size, the number of values in the array
    //We assign this value to average
    average = (double) getTotal(ra, size) / size;

    //Return the average
    return average;
}

int getHighest(int ra[], int size)
{
    //Variables, intialize the max to the first subscript of the array
    int i, maxsofar = ra[0];

    //Enter for loop
    for(i = 0; i < size; i++)
    {
        //Walk through array, comparing each indiviual value to find the max
        if(maxsofar  < ra[i])
            maxsofar = ra[i];
    }

    return maxsofar;
}

int getLowest(int ra[], int size)
{
    //Declare variables, intialize the min to the first subscript of the array
    int i, minsofar = ra[0];

    //Enter for loop
    for(i = 0; i < size; i++)
    {
        //Walk through array, comparing each indiviual value to find the max
        if(minsofar > ra[i])
            minsofar = ra[i];
    }

    return minsofar;
}

void evenOdd(int ra1[], int ra2[], int size)
{
    //Declare variables, 
    int num = 0, i;

    //Enter for loop, to check for evens
    for(i = 0; i < size; i++)
    {
        if(ra1[i] % 2 == 0)
        {
            /*If the value in the array can be divided by two evenly, 
            we will add the value to the second array*/
            ra2[num] = ra1[i];

            //Increase num to step into the next subscript
            num++;
        }
    }

    //Enter for loop, to check for odds
    for(int i = 0; i < size; i++)
    {
        if(ra1[i] % 2 != 0)
        {
            /*If the value in the array CANNOT be divided into two evenly
            we will add the value from where we left off, using the num as our subscript*/
            ra2[num] = ra1[i];

            //Increase num to step into the next subscript
            num++;
        }
    }
}

bool containsInRange(int a[], int size, int x, int start, int end)
{
    //Declare variables, set bool targetisFound automatically to false
    int i;
    bool targetisFound = false;

    //Walk through the start to the prompted end subscript
    for(i = start; i < end; i++)
    {
        //If the targetVal (x) is founded, set bool TargetisFound to true
        if(x == a[i])
            targetisFound = true;
    }
    //Return bool of targetisFound
    return targetisFound;
}

bool sum28(int ra[], int length)
{
    //Declare variables, set sumofTwo equal to 0, to accumalate all 2s.
    //Automatically set bool, isSumEight to false
    int i, sumofTwo = 0;
    bool isSumEight = false;

    //Enter for loop
    for(i = 0; i < length; i++)
    {
        //If the value in the subscript is 2, it will be added to sumofTwo
        if(ra[i] == 2)
            sumofTwo += ra[i];
    }

    //After the for loop, if the value of sumofTwo is indeed eight, set isSumEight true
    if(sumofTwo == 8)
        isSumEight = true;

    //Return bool of sumisEight
    return isSumEight;
}

int getMode(int ra[], int size)
{
    //Declare variables, declare counter array
    int i, ctr_array[size];
    int ctr, wantedScore, maxsoFar, position, mode;

    //Enter for loop
    for(i = 0; i < size; i++)
    {
        ctr = 0;
        wantedScore = ra[i];

        for(int j = i; j < size; j++)
        {
            if(ra[j] == wantedScore)
                ctr++;
        }
        ctr_array[i] = ctr;
    }

    maxsoFar = ctr_array[0];
    position = 0;

    for(int i = 1; i < size; i++)
    {
        if(ctr_array[i] > maxsoFar)
        {
            maxsoFar = ctr_array[i];
            position = i;
        }
    }
    if(maxsoFar > 1)
    {
        mode = ra[position];
        return mode;
    }
    else
        return -1000;
}
