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

            printf("%d", first);      // Printing the first element

               while(sum > num)       // Fibonacci series upto the given range
               {

                   first = second;      // Storing previous two values
                   second = sum;

                   sum = first - second;    // Subtracting previous two values



                   /* Negative Fibonacci series consists of alternative plus and minus terms, so we have to
                      check sum in two ways to ensure the output is within the range */


                      if(sum < 0)      // True if sum is negative
                      {


                            if(-sum <= -num)       // Checking if sum is within the given range
                            {


                                printf(", %d", sum);    // Printing the sum value which is separated by commas

                            }

                      }

                      else      // Sum is positive
                       {


                            if(sum <= -num)         // Checking if sum is within the given range
                            {

                                 printf(", %d", sum);     // Printing the sum value which is separated by commas

                            }

                       }

               }

        }

    return 0;
}
