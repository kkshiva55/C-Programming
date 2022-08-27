/*

Name: Shiva.K
Date: 30-06-2022
Description: Given number is even or odd

Sample output: --> Enter the value of 'n' : 32

                   32 is positive even number

               --> Enter the value of 'n' : -7

                   -7 is positive odd number

               --> Enter the value of 'n' : 0

                   0 is neither odd nor even

*/


#include <stdio.h>

int main()
{
    int num;    // Initialising the required variables

    printf("Enter the value of 'n' : ");    // Getting the input from user
    scanf("%d", &num);   // Storing the value of input at the address of variable "num"

        if(num > 0)    // Checking if given number is positive
        {
            if( num % 2 == 0)   // True if number is even
            {
                printf("\n%d is positive even number", num);

            }

               else   // Given number is odd
               {
                   printf("\n%d is positive odd number", num);
               }

        }

        else if(num == 0)   // User entered the number 0
        {
            printf("\n%d is neither odd nor even", num);
        }

        else   // User entered the negative number
        {
           if( num % 2 == 0)   // True if number is even
            {
                printf("\n%d is negative even number", num);

            }

               else   // Number is odd

               {
                   printf("\n%d is negative odd number", num);
               }
        }

   return 0;

}
