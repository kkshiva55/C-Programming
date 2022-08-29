/*

Name: Shiva.K
Date: 30-06-2022
Description: Positive Fibonacci series

Sample output:  --> Enter a number: 6

                    0, 1, 1, 2, 3, 5

                --> Enter a number: -11

                    Invalid input

*/


#include <stdio.h>

int main ()
{
    int num, sum = 0, first = 0, second = 1;   // Initialisation of required variables
    printf("Enter a number: ");    // Getting input from the user
    scanf("%d", &num);    // Storing the value at the address of variable "num"
    printf("\n");       // Printing output on a new line

        if(num < 0)       // True if user has given negative value
        {
            printf("Invalid input");     // Printing Error message
        }

        else
        {
            do     // Fibonacci series upto the given range
            {
                if (sum != 0)
                {
                    printf(", ");
                }

                  printf("%d", sum);    // Printing the Fibonacci series which is separated by commas
                  first = second;      // Storing previous two values
                  second = sum;
                  sum = first + second;    // Adding previous two values

             } while (sum <= num);
         }

    return 0;
}
