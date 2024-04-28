/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
4/06/2024
Lab #8
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//Declare global variable
int cols = 0;

//Value non-returning function prototypes
void printArray(int ra[][cols], int rows); //a
void getGrades(int ra[][cols], int rows); //i

//Value returning function protoypes
double getClassAvg(int ra[][cols], int rows); //b
int getRange(int ra[][cols], int row); //c
double getRowAverage(int ra[][cols], int rows, int fixedrow); //d
double getColumnAverage(int ra[][cols], int rows, int fixedcol); //e
int getHighestInRow(int ra[][cols], int fixedrow); //f
int getLowestInRow(int ra[][cols], int fixedrow); //g
double getStandardDeviation(int ra[][cols], int rows, int fixedcol); //h

int main()
{
    FILE *inputFile;
    
    //Declare variables
    int row, classRan, i, j;
    double classAvg;
      
    /*Declare a File pointer, then open the file. Your text file and its directory 
    path may be different, so be sure and have it match the
    location of YOUR file on your computer! */

    //Use fopen to open the file
    inputFile = fopen("dataECLab8Sp24.txt", "r");

    //If file is opened incorrectly or contents are nothing, terminate and return -1
    if(inputFile == NULL)
    {
        printf("Unable to open input file.\n");
        return 1; //ends the main
    }

    //Use fscanf to read the row and column from file
    fscanf(inputFile, "%d %d", &row, &cols);
    int gradeBook[row][cols];

    //Populate the 2d array to populate it with the data from file
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < cols; j++)
        {
            fscanf(inputFile, "%d", &gradeBook[i][j]);
        }
    }

    //REMEMBER TO CLOSE THE FILE, JOSH
    fclose(inputFile);

    //START ORIGINAL

    //print the array by invoking the printArray function
    printArray(gradeBook, row);
    //END OF FUNC, Follow with a new line
    printf("\n");

    //Invoke getClassAvg function to assign the value to classAvg (average)
    classAvg = getClassAvg(gradeBook, row);
    //Print out classAvg, returned from getClassAvg function
    printf("The class average of all grades is:%6.1f", classAvg);
    //END OF FUNC, Follow with a new line
    printf("\n");

    //Invoke getRange function to assign the value to classRan (range)
    classRan = getRange(gradeBook, row);
    printf("The range of all grades is: %d", classRan);
    //END OF FUNC, Follow with two new lines
    printf("\n\n");

    //Invoke getRowAverage function in FOR loop to print out average of student scorees
    for(i = 0; i < row; i++)
    {
        //Enter for loop, print until we reach end of array
        printf("The average for student #%d:%6.1f\n",i + 1,  getRowAverage(gradeBook, row, i));
    }
    //END OF FUNC, Follow with a new line
    printf("\n");

    //Invoke getColumnAverage function in FOR loop to print out average of exams
    for(i = 0; i < cols; i++)
    {
        //Enter for loop, print until we reach end of array
        printf("The average for exam #%d: %6.1f\n", i + 1, getColumnAverage(gradeBook, row, i));
    }
    //END OF FUNC, Follow with a new line
    printf("\n");

    //Invoke getHighestInRow function in FOR loop to print out the highest exam grade for each student
    for(i = 0; i < row; i++)
    {
        //Enter for loop, print until we reach end of array
        printf("The highest exam grade for student #%d: %4d\n",i + 1,  getHighestInRow(gradeBook, i));
    }
    //END OF FUNC, Follow with a new line
    printf("\n");

    //Invoke getLowestInRow function in FOR loop to print out the lowest exam grade for each student
    for(i = 0; i < row; i++)
    {
        //Enter for loop, print until we reach end of array
        printf("The lowest exam grade for student #%d: %4d\n", i + 1, getLowestInRow(gradeBook, i));
    }
    //END OF FUNC, Follow with a new line
    printf("\n");

    //Invoke getStandardDeviation function in FOR loop to print out the standard deviations for each exam
    for(i = 0; i < cols; i++)
    {
        //Enter for loop, print until we reach end of array
        printf("The standard deviation for exam #%d: %6.1f\n", i + 1, getStandardDeviation(gradeBook, row, i));
    }
    //END OF FUNC, Follow with a new line
    printf("\n");

    //invoke getGrades function
    getGrades(gradeBook, row);

    //End main
    return 0;
} 

void printArray(int ra[][cols], int rows) //a
{
    //Declare variables
    int i, j;
    
    //Print out 10 spaces
    printf("%10s", "");

    //Print out list of exams, and its respective number
    for(i = 0; i < cols; i++)
        printf("%8s%d","Exam #", i + 1);

    //Follow with new line
    printf("\n");

    //Print out exams scores, alligned with respective exam number
    for(i = 0; i < rows; i++)
    {  
        //Print out list of students, and its respective number
        printf("Student #%d", i + 1);

        for(j = 0; j < cols; j++)
        {
            printf("%9d", ra[i][j]);
        }

        //Follow with new line
        printf("\n");
    }
}

double getClassAvg(int ra[][cols], int rows) //b
{
    //Declare variables, assigning zeros to accumulators
    double avg;
    int sum = 0, ct = 0;

    //Walk through whole 2D array
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            //Add values of data to sum
            sum += ra[i][j];

            //Increase counter for each value taken
            ct++;
        }
    }

    //Calculate average, the sum of all scores (CASTED) divided by the amount of scores
    avg = (double) sum / ct;

    //Return the value assigned to avg to main
    return avg;
}
int getRange(int ra[][cols], int row) //c
{
    //Declare variables
    int ran, max = ra[0][0], min = ra[0][0];

    //Walk through 2D array, obtaining the max and min, by checking and comparing the values
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(max < ra[i][j])
                max = ra[i][j];
            if(min > ra[i][j])
                min = ra[i][j];
        }
    }

    //Calculate range, range is the difference of the maximum score and the minimum score plus one
    ran = max - min + 1;

    //Return the value assigned to ran (range) to main
    return ran;
}

double getRowAverage(int ra[][cols], int rows, int fixedrow) //d
{
    //Declare variables, assign 0s to accumulators
    int sum = 0, ct = 0;
    double avg;
    
    //Walk through the columns of the fixedrow
    for(int i = 0; i < cols; i++)
    {
        //Add values of the fixed row to the sum
        sum += ra[fixedrow][i];

        //Increase ct
        ct++;
    }

    //The average is the total sum (CASTED) divided by the amount
    avg = (double) sum / ct;

    //Return the value assigned to avg (average) in main
    return avg;
}

double getColumnAverage(int ra[][cols], int rows, int fixedcol) //e
{
    //Declare variables, assign 0s to accumulators
    int sum = 0, ct = 0;
    double avg;

    //Walk through the rows of the fixed column
    for(int i = 0; i < rows; i++)
    {
        //Add values of the fixed column to the sum
        sum += ra[i][fixedcol];

        //Increase ct
        ct++;
    }

    //The average is the total sum (CASTED) divided by the amount
    avg = (double) sum / ct;

    //Return the value assigned to avg (average) in main
    return avg;
}

int getHighestInRow(int ra[][cols], int fixedrow) //f
{
    //Declare variables, assign max value to first subscript of array
    int max = ra[fixedrow][0];

    //Walk through the array, compare values within the respective row, to find the max
    for(int i = 1; i < cols; i++)
    {
        if(max < ra[fixedrow][i])
            max = ra[fixedrow][i];
    }

    //Return the value assigned to max in main
    return max;
}

int getLowestInRow(int ra[][cols], int fixedrow) //g
{
    //Declare variables, assign min value to first subscript of array
    int min = ra[fixedrow][0];

    //Walk through the array, compare values within the respective row, to find the min
    for(int i = 1; i < cols; i++)
    {
        if(min > ra[fixedrow][i])
            min = ra[fixedrow][i];
    }

    //Return the value assigned to min in main
    return min;
}

double getStandardDeviation(int ra[][cols], int rows, int fixedcol) //h
{
    //Declare variables, assigning 0s to accumulators
    double stdDev, sum = 0, avg;
    int i;

    /*
    HOW TO STANDARD DEVIATION CALCULATION
    1. Work out the Mean (the simple average of the numbers). (Your function may invoke the
    getColumnAverage function in order to do this step.)
    2. Then for each test score: subtract the Mean and square the result.
    3. Then work out the mean of those squared differences, i.e. add all of the squared differences
    together and divide by the number of scores.
    4. Take the square root of that and we are done
    */
    
    //STEP 1: Invoke getColumnAverage function with to assign the returned value with avg (average)
    avg = getColumnAverage(ra, rows, fixedcol);

    //STEP 2: For each test scores, subtract the mean (assigned to avg) and square the result
    for(i = 0; i < rows; i++)
    {
        //STEP 3a: Work out the mean of those squared differences, add to the sum of the squared differences
        sum += pow(ra[i][fixedcol] - avg, 2);
    }

    //STEP 3b: Divide by the number of scores
    sum /= i;

    //STEP 4: Take the square root
    stdDev = sqrt(sum);

    //Return the value assigned to stdDev to main
    return stdDev;
}

void getGrades(int ra[][cols], int rows) //i
{
    //Declare variables, assigning 0s to accumulators
    int lowestScore, sum = 0;
    double studAvg;
    
    //Walk through the array of student score
    for(int i = 0; i < rows; i++)
    {
        //Invoke getLowestInRow function to assign the value to lowestScore
        lowestScore = getLowestInRow(ra, i);

        //Walk through the columns, adding the total scores to the sum
        for(int j = 0; j < cols; j++)
        {
            sum += ra[i][j];
        }

        /*
        First, we cast the value of the difference of the lowest score and total sum, dividing it by the number of scores.
        Since we took one value away (the lowest score) the number of scores will be the amount of columns minus one*/
        studAvg = (double) (sum - lowestScore) / (cols - 1);

        //START OF: If statements to determine what grade the student has, depending on the NEW student average
        
        //If student lands a 90 or above, recieves A
        if(studAvg >= 90)
        {
            printf("Student #%d had an average of  %.1f (after dropping lowest score).\n", i + 1, studAvg);
            printf("This student received a grade of A in the class.\n");
        }
        
        //ELSE If student lands a 80 or above, recieves B
        else if(studAvg >= 80)
        {
            printf("Student #%d had an average of  %.1f (after dropping lowest score).\n", i + 1, studAvg);
            printf("This student received a grade of B in the class.\n");           
        }

        //ELSE If student lands a 70 or above, recieves C
        else if(studAvg >= 70)
        {
            printf("Student #%d had an average of  %.1f (after dropping lowest score).\n", i + 1, studAvg);
            printf("This student received a grade of C in the class.\n");            
        }

        //If student lands a 60 or above, recieves D
        else if(studAvg >= 60)
        {
            printf("Student #%d had an average of  %.1f (after dropping lowest score).\n", i + 1, studAvg);
            printf("This student received a grade of D in the class.\n");            
        }

        //Trailing else: If student lands anywhere else, recieves F
        else
        {
            printf("Student #%d had an average of  %.1f (after dropping lowest score).\n", i + 1, studAvg);
            printf("This student received a grade of F in the class.\n");
        }

        //Reset sum equal to 0 to prepare for next accumulation of values
        sum = 0;

        //Follow with new line
        printf("\n");
    }
}


