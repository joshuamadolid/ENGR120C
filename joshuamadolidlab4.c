/*
Joshua Madolid
Engrg 120C
Instructor: Mimi Rasky
3/1/2024
Lab #4
*/

#include <stdio.h>

int main()
{
    //Declare all variables
    int counter = 0, bitwise, row = 0, column, i, j, n;

    //Header
    printf("%12d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    printf("%4d%4d%4d%4d%4d\n",11, 12, 13, 14, 15);
    printf("-------------------------------------------------------------------------\n");
 
    //Enter for loop
    for(int row = 0; row < 16; row++)
    {
        //Prints out number for rows on the left side
        printf("%2d |", row);
        for(i = 0; i < (16 - row); i++)
        {
            printf("    ");
        }

        //Calculates the bitwise AND results for the row and displays them
        for(j = row + 1; j >= 1; j--)
        {
            n = 16 - j;
            bitwise = row & n;
            printf("%4d", bitwise);
        }

        //Move onto the next row
        printf("\n");
    }
    //Exit for loop

    return 0;
}