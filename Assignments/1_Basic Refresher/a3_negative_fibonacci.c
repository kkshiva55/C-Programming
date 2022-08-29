/*

Name: Shiva.K
Date: 03-07-2022
Description: Negative Fibonacci series

Sample output:  --> Enter a number: -20

                    0, 1, -1, 2, -3, 5, -8, 13

                --> Enter a number: 18

                    Invalid input

*/



#include <stdio.h>

int main ()
{
    int num, sum = 0, first = 0, second = 1;   // Initialization of required variables
    printf("Enter a number: ");    // Getting input from the user
    scanf("%d", &num);    // Storing the value at the address of variable "num"
    printf("\n");       // Printing output on a new line

        if(num > 0)       // True if user has given positive value
        {
            printf("Invalid input");     // Printing Error message
        }

        else
        {
            while(sum >= num && -sum >= num)       // Fibonacci series upto the given range
            {
                if (sum != 0)
                {
                    printf(", ");
                }

                  printf("%d", sum);
                  first = second;      // Storing previous two values
                  second = sum;
                  sum = first - second;    // Subtracting previous two values
            }
         }

    return 0;
}
