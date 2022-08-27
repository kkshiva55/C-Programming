/*

Name: Shiva.K
Date: 22-07-2022
Description: Positive Fibonacci series using Recursion function

Sample output: --> Enter the limit : 25
                   0, 1, 1, 2, 3, 5, 8, 13, 21


*/


#include <stdio.h>


void positive_fibonacci(int, int, int, int);    // Function declaration

int main()
{
    int limit;

    printf("Enter the limit : ");       // Getting the limit from the user
    scanf("%d", &limit);

    positive_fibonacci(limit, 0, 1, 0);     // Calling the function
}



void positive_fibonacci(int limit, int sum, int second, int first)     // Function definition
{

     if(limit < 0)       // Checking if user has entered a valid input
     {

         printf("Invalid input");

     }

     else if(sum == 0)       // Printing the first element without comma
     {
         printf("%d", sum);

         positive_fibonacci(limit, sum = first + second, second = sum, first = second);      // Recursive function call

     }


     else if (sum <= limit)     // Fibonacci series should be within the given limit
     {
         printf(", %d", sum);

         positive_fibonacci(limit, sum = first + second, second = sum, first = second);     // Recursive function call

     }

}
