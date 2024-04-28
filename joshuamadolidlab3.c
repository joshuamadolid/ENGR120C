/*
Joshua Madolid
Engrg 120C
Instructor: Professor Mimi Rasky
2/20/2024
Lab #3
*/

#include <stdio.h> 
#include <string.h>
#include <math.h>

int main()
{
    // Declaring all variables 
    char country [20];
    double totalusd;

    //Declaring all country notes from Europe - British - Japan
    double euroamount = 0, poundamount = 0, yenamount = 0, temp = 0;
    int euronote500, euronote200, euronote100, euronote50, euronote20, euronote10, euronote5;
    int pound50, pound20, pound10, pound5;
    int yententho, yen5tho, yen2tho, yen1tho;

    //Declaring all country coins from Europe - British - Japan
    double eurocoins, poundcoins, yencoins;
    int eurocoin2, eurocoin1, eurocoinhalf, eurocoinfifth, eurocointenth, eurocointwentieth, eurocoinfiftieth, eurocoinpenny;
    int poundco2, poundco1, poundcohalf, poundcofifth, poundcotenth, poundcotwentieth, poundcofiftieth, poundcopenny;
    int jpy500, jpy100, jpy50, jpy10, jpy5, jpy1;

    //Declaring counters for country and whole values
    int eurocounter, poundcounter, yencounter, change;
    int eurowhole, poundwhole, yenwhole;
    int wholeusd = totalusd;
    
    // Prompt and grab from the user
    printf("Enter the destination zone (Europe, United Kingdom, Japan): ");
    scanf("%[^\n]s", country);
    
    // If statement initates if user chooses europe
    if (strcasecmp(country, "Europe") == 0)
        {
            //Scans the user's input for USD
            printf("Enter the amount of USD you want to convert: ");
            scanf("%lf", &totalusd);
            
            //Exchange rate: 1 USD = 0.88 Euros
            euroamount = totalusd * 0.88;
            eurocounter = totalusd * 0.88;
            eurowhole = (int) euroamount;

            //Calculating euro notes
            euronote500 = eurocounter / 500;
            eurocounter %= 500;
            euronote200 = eurocounter / 200;
            eurocounter %= 200;
            euronote100 = eurocounter / 100;
            eurocounter %= 100;
            euronote50 = eurocounter / 50;
            eurocounter %= 50;
            euronote20 = eurocounter / 20;
            eurocounter %= 20;
            euronote10 = eurocounter / 10;
            eurocounter %= 10;
            euronote5 = eurocounter / 5;
            eurocounter %= 5;

            //Stripping the decimal from total and adding leftover from notes
            eurocoins = euroamount - eurowhole;
            temp = (eurocounter + eurocoins) * 100;
            change = (int) round(temp);
            
            //Calculating euro coins
            eurocoin2 = change / 200;
            change %= 200;
            eurocoin1 = change / 100;
            change %= 100;
            eurocoinhalf = change / 50;
            change %= 50;
            eurocoinfifth = change / 20;
            change %= 20;
            eurocointenth = change / 10;
            change %= 10;
            eurocointwentieth = change / 5;
            change %= 5;
            eurocoinfiftieth = change / 2;
            change %= 2;
            eurocoinpenny = change;

            //Displaying the conversions from USD to euro notes
            printf("\n%.2f is %.2f Euros\n", totalusd, euroamount);
            printf("****************************\n");
            printf("\nPaper Currency:\n");
            printf("%3d of the  500 Euro Notes\n", euronote500);
            printf("%3d of the  200 Euro Notes\n", euronote200);
            printf("%3d of the  100 Euro Notes\n", euronote100);
            printf("%3d of the   50 Euro Notes\n", euronote50);
            printf("%3d of the   20 Euro Notes\n", euronote20);
            printf("%3d of the   10 Euro Notes\n", euronote10);
            printf("%3d of the    5 Euro Notes\n\n", euronote5);

            //Displaying the conversions from USD to euro coins
            printf("Coin Currency:\n");
            printf("%3d of the 2    Euro Coins\n", eurocoin2);
            printf("%3d of the 1    Euro Coins\n", eurocoin1);
            printf("%3d of the 0.50 Euro Coins\n", eurocoinhalf);
            printf("%3d of the 0.20 Euro Coins\n", eurocoinfifth);
            printf("%3d of the 0.10 Euro Coins\n", eurocointenth);
            printf("%3d of the 0.05 Euro Coins\n", eurocointwentieth);
            printf("%3d of the 0.02 Euro Coins\n", eurocoinfiftieth);
            printf("%3d of the 0.01 Euro Coins\n", eurocoinpenny);
        }
    
    // If statement initates if user chooses UnitedKingdom
    else if (strcasecmp(country, "United Kingdom") == 0)

        {
            //Scans the user's input for USD
            printf("Enter the amount of USD you want to convert: ");
            scanf("%lf", &totalusd);

            //Exchange rate: 1 USD = 0.72 British Pounds
            poundamount = totalusd * 0.72;
            poundcounter = totalusd * 0.72;
            poundwhole = (int) poundamount;
            
            //Calculating pound notes
            pound50 = poundcounter / 50;
            poundcounter %= 50;
            pound20 = poundcounter / 20;
            poundcounter %= 20;
            pound10 = poundcounter / 10;
            poundcounter %= 10;
            pound5 = poundcounter / 5;
            poundcounter %= 5;

            //Stripping the decimal from total and adding leftover from notes
            poundcoins = poundamount - poundwhole;
            temp = (poundcounter + poundcoins) * 100;
            change = (int) round(temp);
            
            //Calculating Pound coins
            poundco2 = change / 200;
            change %= 200;
            poundco1 = change / 100;
            change %= 100;
            poundcohalf = change / 50;
            change %= 50;
            poundcofifth = change / 20;
            change %= 20;
            poundcotenth = change / 10;
            change %= 10;
            poundcotwentieth = change / 5;
            change %= 5;
            poundcofiftieth = change / 2;
            change %= 2;
            poundcopenny = change;

            //Displaying the conversions from USD to Pounds
            printf("\n$%.2f is %.2f British Pounds\n", totalusd, poundamount);
            printf("****************************\n");
            printf("\nPaper Currency:\n");
            printf("%3d of the 50   Pound Notes\n", pound50);
            printf("%3d of the 20   Pound Notes\n", pound20);
            printf("%3d of the 10   Pound Notes\n", pound10);
            printf("%3d of the  5   Pound Notes\n", pound5);

            //Displaying the conversions from USD to pound coins
            printf("\nCoin Currency:\n");
            printf("%3d of the 2    Pound Coins\n", poundco2);
            printf("%3d of the 1    Pound Coins\n", poundco1);
            printf("%3d of the 0.50 Pound Coins\n", poundcohalf);
            printf("%3d of the 0.20 Pound Coins\n", poundcofifth);
            printf("%3d of the 0.10 Pound Coins\n", poundcotenth);
            printf("%3d of the 0.05 Pound Coins\n", poundcotwentieth);
            printf("%3d of the 0.02 Pound Coins\n", poundcofiftieth);
            printf("%3d of the 0.01 Pound Coins\n", poundcopenny);
        }

    // If statement initates if user chooses Japan
    else if (strcasecmp(country, "Japan") == 0)

        {
            //Scans the user's input for USD
            printf("Enter the amount of USD you want to convert: ");
            scanf("%lf", &totalusd);

            //Exchange Rate: 1 USD = 133.35 Yen
            yenamount = totalusd * 133.35;
            yencounter = totalusd * 133.35;
            yenwhole = (int) yenamount;
            
            //Calculating Yen notes
            yententho = yencounter / 10000;
            yencounter %= 10000;
            yen5tho = yencounter / 5000;
            yencounter %= 5000;
            yen2tho = yencounter / 2000;
            yencounter %= 2000;
            yen1tho = yencounter / 1000;
            yencounter %= 1000;

            // Using the leftover yen notes, calculate yen coins
            yencoins = yenamount - yenwhole;
            temp = (yencounter + yencoins);
            change = (int) temp;
            
            //Calculating Yen coins
            jpy500 = change / 500;
            change %= 500;
            jpy100 = change / 100;
            change %= 100;
            jpy50 = change / 50;
            change %= 50;
            jpy10 = change / 10;
            change %= 10;
            jpy5 = change / 5;
            change %= 5;
            jpy1 = change;
             
            //Displaying the conversions from USD to Yen
            printf("\n$%.2f is %.2d Yen\n", totalusd, yenwhole);
            printf("****************************\n");
            printf("\nPaper Currency:\n");
            printf("%3d of the 10,000 Yen Notes\n", yententho);
            printf("%3d of the  5,000 Yen Notes\n", yen5tho);
            printf("%3d of the  2,000 Yen Notes\n", yen2tho);
            printf("%3d of the  1,000 Yen Notes\n", yen1tho);

            //Displaying the conversions from USD to Yen Coins
            printf("\nCoin Currency:\n");
            printf("%3d of the    500 Yen Coins\n", jpy500);
            printf("%3d of the    100 Yen Coins\n", jpy100);
            printf("%3d of the     50 Yen Coins\n", jpy50);
            printf("%3d of the     10 Yen Coins\n", jpy10);
            printf("%3d of the      5 Yen Coins\n", jpy5);
            printf("%3d of the      1 Yen Coins\n", jpy1);
            
        }
    // Will return a prompt if the user enters neither country
    else {
            printf("Invalid destination zone.\n"); }

    return 0;

}
