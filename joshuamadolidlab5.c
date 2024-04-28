/*
Joshua Madolid        
Engrg 120C 
Instructor: Professor Mimi Rasky         
Date         
Title: Lab #5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(0));
    int userFiveRoll, compFiveRoll, userLoadRoll, compLoadRoll, userfiveCtr = 0, userfourCtr = 0;
    int userthreeCtr = 0, usertwoCtr = 0, useroneCtr = 0, compfiveCtr = 0, compfourCtr = 0, compthreeCtr = 0, comptwoCtr = 0, componeCtr = 0;
    int compDifference = 0, userDifference = 0, roundCtr = 1, compWin = 0, userWin = 0, ties = 0;

    for(int i = 0; i < 17; i++);
    {
        userFiveRoll = rand()%5 + 1;
        compFiveRoll = rand()%5 + 1;
        userLoadRoll = rand()%100 + 1;
        compLoadRoll = rand()%100 + 1;
        
        //For loaded user roll
        if(userLoadRoll < 68)
        {
            useroneCtr++;
        }

        else if(userLoadRoll < 74)
        {
            usertwoCtr++;
        }

        else if(userLoadRoll < 82)
        {
            userthreeCtr++;
        }

        else if(userLoadRoll < 90)
        {
            userfourCtr++;
        }

        else
        {
            userfiveCtr++;
        }

        //For loaded computer roll
        if(compLoadRoll < 68)
        {
            componeCtr++;
        }

        else if(compLoadRoll < 74)
        {
            comptwoCtr++;
        }

        else if(compLoadRoll < 82)
        {
            compthreeCtr++;
        }

        else if(compLoadRoll < 90)
        {
            compfourCtr++;
        }

        else
        {
            compfiveCtr++;
        }

        compDifference = abs(compLoadRoll - compFiveRoll);
        userDifference = abs(userLoadRoll - userFiveRoll);

        printf("Computer Turn Round #%d\n", roundCtr);
        printf("- - - - - - - - - - - - - - - -\n");
        printf("Normal Die:   %d\n", compFiveRoll);
        printf("Loaded Die:   %d\n", compLoadRoll);
        printf("Difference:"  %d\n\n", compDifference);
        
        printf("User Turn Round #%d\n", roundCtr);
        printf("- - - - - - - - - - - - - - - -\n");
        printf("Normal Die:   %d\n", userFiveRoll);
        printf("Loaded Die:   %d\n", userFiveRoll);
        printf("Difference:"  %d\n\n", userDifference);

        if(compDifference < userDifference)
        {
            printf("The Computer wins this round!!!!!");
            compWin++;
        }

        else if(compDifference == userDifference)
        {
            tie++;
        }
        
        else
        {
            printf(The User has run this round!!!!!");
            userWin++;
        }
        
        roundCtr++;
    }

    printf("Total number of Computer Wins: %d", compWin);
    printf("Total number of User Wins: %d", userWin");
    printf("Total number of Ties: %d", ties");

    if(CompWin == userWin)
        printf("TIE GAME!!!! Nobody wins this game, sorry."");

    else if(Comp Win > userWin)
        printf("The Computer is the Grand Champion!!!");
    
    else
        printf("The User is the Grand Champion!");


        return 0;

    }





}