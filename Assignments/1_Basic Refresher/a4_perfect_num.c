/*

Name: Shiva.K
Date: 03-07-2022
Description: Check if given number is perfect or not

Sample output: --> Enter a number: 496

                   Yes, entered number is perfect number

               --> Enter a number: 12

                   No, entered number is not a perfect number

               --> Enter a number: -5

                   Error : Invalid Input, Enter only positive number

*/



#include <stdio.h>

int main()
{

    int num, factor, sum = 0;      //Initialization of all required variables

    printf("Enter a number: ");    // Getting input from the user

    scanf("%d", &num);            // Storing the input at the address of variable "num"


    if(num < 0)       // Checking if user has entered negative number
    {

       printf("\nError : Invalid Input, Enter only positive number");

    }

    else
    {


         for(factor = 1; factor < num; factor++)    // Loop will be executed from 1 to given number
         {

              if(num % factor == 0)     // Checking if a number is a factor of given number
              {

                 sum = sum + factor;    // Adding factors of given number one by one

              }

         }


        if(num == sum)      // Checking if given number is a perfect number
        {

            printf("\nYes, entered number is perfect number");

        }

        else
       {

           printf("\nNo, entered number is not a perfect number");

       }

    }
        return 0;
}
