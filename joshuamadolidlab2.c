/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
2/13/2024
Lab #2
*/

#include <stdio.h> 
#include <math.h>

// Defining conversion factors for inches to centimeters
#define CM_CONVERSION 2.54

int main()

{
    
    // Initalizing all variables to their respective data type
    
    int radi1, radi2, radi3, radi4, radi5, maxradi;
    double radi1cm, radi2cm, radi3cm, radi4cm, radi5cm;
    double ang1, ang2, ang3, ang4, ang5;
    double anginrad1, anginrad2, anginrad3, anginrad4, anginrad5;
    double arclen1, arclen2, arclen3, arclen4, arclen5;
    double polarea1, polarea2, polarea3, polarea4, polarea5, avgradi;
    
    // Asking users to input data

    printf("Please enter an integer radius measurement (in inches) : ");
    scanf("%d", &radi1);
    printf("Please enter an integer angle (in degrees, between 0 and 360): ");
    scanf("%lf", &ang1);

    printf("\nPlease enter an integer radius measurement (in inches) : ");
    scanf("%d", &radi2);
    printf("Please enter an integer angle (in degrees, between 0 and 360): ");
    scanf("%lf", &ang2);

    printf("\nPlease enter an integer radius measurement (in inches) : ");
    scanf("%d", &radi3);
    printf("Please enter an integer angle (in degrees, between 0 and 360): ");
    scanf("%lf", &ang3);

    printf("\nPlease enter an integer radius measurement (in inches) : ");
    scanf("%d", &radi4);
    printf("Please enter an integer angle (in degrees, between 0 and 360): ");
    scanf("%lf", &ang4);

    printf("\nPlease enter an integer radius measurement (in inches) : ");
    scanf("%d", &radi5);
    printf("Please enter an integer angle (in degrees, between 0 and 360): ");
    scanf("%lf", &ang5);

    // Calculations and conversions
    
    // Converting radius in inches to centimeters
    
    radi1cm = radi1 * CM_CONVERSION;
    radi2cm = radi2 * CM_CONVERSION;
    radi3cm = radi3 * CM_CONVERSION;
    radi4cm = radi4 * CM_CONVERSION;
    radi5cm = radi5 * CM_CONVERSION;
    
    // Calculating the angle in radians by multiplying the inputted angle by pi, and dividing by 180

    anginrad1 = (ang1 * M_PI) / 180;
    anginrad2 = (ang2 * M_PI) / 180;
    anginrad3 = (ang3 * M_PI) / 180;
    anginrad4 = (ang4 * M_PI) / 180;
    anginrad5 = (ang5 * M_PI) / 180;

    // Calculated the arc length by multiplying the angle in radians by the radius, after converting to cm

    arclen1 = (radi1cm * anginrad1);
    arclen2 = (radi2cm * anginrad2);
    arclen3 = (radi3cm * anginrad3);
    arclen4 = (radi4cm * anginrad4);
    arclen5 = (radi5cm * anginrad5);

    // Calculated the polar area by multiplying by a half the angle in radians, times the radius in centimeters squared
    

    polarea1 = 0.5 * anginrad1 * pow(radi1cm, 2);
    polarea2 = 0.5 * anginrad2 * pow(radi2cm, 2);
    polarea3 = 0.5 * anginrad3 * pow(radi3cm, 2);
    polarea4 = 0.5 * anginrad4 * pow(radi4cm, 2);
    polarea5 = 0.5 * anginrad5 * pow(radi5cm, 2);

    // Finding the average radius and maxiumum radius

    avgradi = (radi1 + radi2 + radi3 + radi4 + radi5) / 5.0 ;
    maxradi = radi1;

    /* 
    With the max radius intialized to the first radius value, I created
    a chain of if statements to update the value of the maximum radius
    */

    if (radi2 > maxradi)
    {
        maxradi = radi2;
    }

    if (radi3 > maxradi)
    {
        maxradi = radi3;
    }

    if (radi4 > maxradi)
    { 
        maxradi = radi4;
    }

    if (radi5 > maxradi)
    {   
        maxradi = radi5;
    }

// Prints out data after final conversions 

    printf("\n\nRadius (in.)   Angle (radians)    Arclength(cm.)   Polar Area (sq. cm.)\n");
    printf("***********************************************************************\n");
    printf("\n%7d  %13.2f  %20.2f  %16.2f", radi1, anginrad1, arclen1, polarea1);
    printf("\n%7d  %13.2f  %20.2f  %16.2f", radi2, anginrad2, arclen2, polarea2);
    printf("\n%7d  %13.2f  %20.2f  %16.2f", radi3, anginrad3, arclen3, polarea3);
    printf("\n%7d  %13.2f  %20.2f  %16.2f", radi4, anginrad4, arclen4, polarea4);
    printf("\n%7d  %13.2f  %20.2f  %16.2f\n\n", radi5, anginrad5, arclen5, polarea5);

    printf("The average of all the radii is: %.1lf inches\n", avgradi);
    printf("          The maximum radius is:   %d inches\n", maxradi);

    return 0;

}