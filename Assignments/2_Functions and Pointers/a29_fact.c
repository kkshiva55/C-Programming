/*

Name: Shiva.K
Date: 26-07-2022
Description: Factorial of a given number using Recursion

Sample output: --> Enter the value of N : 5
                   Factorial of the given number is 120

               --> Enter the value of N : -25
                   Invalid Input


*/



#include <stdio.h>

int main()
{
    static int num;
    static unsigned long long int fact = 1;        // Declaring required variables


       if (num == 0)           // True because "static int num" stores zero by default
       {
           printf("Enter the value of N : ");      // Getting input from the user
           scanf("%d", &num);


                if (num < 0)        // True if user entered negative value
                {
                    printf("Invalid Input");
                    return 0;
                }

                else if (num == 0)       // True if user entered input as '0'
                {
                    printf("Factorial of the given number is %llu", fact);
                    return 0;
                }

        }



       if (num != 1)          // Terminates when fact = 1
       {
           fact = (fact * (num--));        // Calculating the factorial value

           main();         // Calling the main function Recursively
       }


       else        // Printing the final output
       {
           printf("Factorial of the given number is %llu", fact);
       }


  return 0;

}
