/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
4/16/2024
Lab #9
*/

#include <stdlib.h>
#include <stdio.h>

//Function prototype
char *serchit(char *str, char ref_char);

int main()
{
    //Declare variables
    char userString[50];
    char targetChar;
    int ctr = 0, i = 0;
    char *chrptr;
     
    //Prompt user for string
    printf("Please enter a string: ");
    scanf("%[^\n]", userString);

    //Prompt user for character to search for
    printf("Please enter a character to search for: ");
    scanf("\n%c", &targetChar);

    //Cookbook Code to find length of string
    while (userString[ctr])
        ctr++;

    //Print the user inputted string
    printf("The string is: %s\n", userString);
    //Print the length of the string
    printf("The length of the string is: %d\n", ctr);

    //Invoke function, assign the chrptr to point to it
    chrptr = serchit(userString, targetChar);

    //If the character was not found, we print out the character was not found
    if(chrptr == NULL)
        printf("%c was not found in the string\n\n", targetChar);
     
    else
    //If the character was found, we print the character was found, and rest of the string beggining at char
    {
        printf("%c was found in the string\n", *chrptr);
        printf("The string, beggining at %c is: %s\n\n", *chrptr, chrptr);
        
    }
    
    //WHETHER THE CHAR WAS FOUND OR NOT, we print out the contents of the string
    printf("Address%10sContents%5sDecimal%5sASCII\n","","","");
        
    //If the char was found, enter if statement
    if(*chrptr != '\0')
    {
        //Use a while loop to print out the contents of the char
        while(chrptr[i] != '\0')
        {
            //Use the correct format specifiers to print out the address, contents, decimal, and ASCII
            printf("%08X%11s0x%02x%9s%3d%9s%c\n",(chrptr+i),"",*(chrptr+i),"",*(chrptr+i),"",*(chrptr+i));
            i++;
        }
        //End the while loop, print out the address of the null terminator
        printf("%08X%11s0x%02x%9s%3d%9s%c\n",chrptr,"",userString[ctr],"",userString[ctr],"",userString[ctr]);
    }
        
    //If the char was not found, enter else statement, and print out the address of the null terminator
    else
        printf("%08X%11s0x%02x%9s%3d%9s%c\n",chrptr,"",userString[ctr],"",userString[ctr],"",userString[ctr]);
    
    return 0;
}

char *serchit(char *str, char ref_char)
{
    //Declare variables
    int n = 0;
    char *character;

    //Traverse char array 
    while(str[n])
    {
        //If char is found, we return the character to main
        if(str[n] == ref_char)
        {
            //Set the character pointer to the value in the string, and return it
            character = &str[n];
            return character;
        }
        n++;
    }
    //If char is not found, return the null pointer
    return &str[n];
}