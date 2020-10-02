/*  This "program" checks to see if a given number is prime.
    It gets its its input as an argument from the command line.
    Current version  is v2.
    For help call the program with the parameter h.
    2020 Antonios Giannakopoulos, https://github.com/AvariCe-git */


#include <stdio.h>                                                          //Standard input output
#include <stdbool.h>                                                        // Need this for boolean functionality
#include <stdlib.h>                                                         // Need this for atoi function
#include <string.h>                                                         // Used for the strncmp funtion

int prime(char p1[]);                                                       // This function checks if the given number is prime

int main(int argc,char* argv[]){

    prime(argv[1]);                                                         // Using a separate function because I don't feel comfortable
    return 0;                                                               // having more than two lines of code in main

}

int prime(char p1[]){                                                      // Function to check if the given number is prime

    if(strncmp(p1, "h", 1) == 0){                                          // Check if it must print the "help" page.
        printf("This so called program checks to see if a given number is prime.\n");
        printf("It gets its its input as an argument from the command line.\n");
        printf("Current version  is v2.\n");
        printf("For help call the program with the parameter h.\n");
        printf("2020 Antonios Giannakopoulos, https://github.com/AvariCe-git\n");
        return 0;
    }
    int number = 0, i = 0;                                                  // number is the given number after conversion, i is used for the loop
    bool trip = false;                                                      // Boolean to check later if the given number has any divisors other than 1
    number = atoi(p1);                                                      // Convert from string to double
    if (number == 0)                                                        // Check if given number is 0, if it is 
        printf("0 is nothing");                                             // it shows a message and quits
    else if (number == 1 || number == 2 )                                   // Check if given number is 1 or 2, and prints the appropriate message
        printf("%d is a prime number\n", number);                           // Messages are in greek, because I am greek
    else{                                                                   // If the given number is =! 0,1 or 2 it enters this loop
        for(i=2; i<number; i++){                                            // The loop does the modulo operation of the given number against i,  
            if (number%i == 0){                                             // which increases by 1 each time, until i is given number - 1. 
                if (trip == false){                                         // If the first divisor is found, it prints the first message and divisor and trips the boolean.  
                printf("%d is not a prime number\n", number);       // When that happens, it just prints the subsequent divisors.
                printf("Oi diairetes tou einai:");                          // The loop doesn't check against 1 or the number itself, because it isn't necessary
                printf("  %d", i);                                          // and I'm lazy. It will show all other divisors though.
                trip = true;
                }
                else
                    printf("  %d", i);
            }
        }
    if (trip == false)                                                      // Check if the boolean has been tripped. If it hasn't, it means it hasn't found any  
        printf("%d is a prime number\n", number);                    // divisors, which means the number is a prime, and prints the aprropriate message.
    }

}