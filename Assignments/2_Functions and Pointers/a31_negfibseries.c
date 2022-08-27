/*

Name: Shiva.K
Date: 22-07-2022
Description: Negative Fibonacci series using Recursion function

Sample output: --> Enter the limit : -25
                   0, 1, -1, 2, -3, 5, -8, 13, -21

               --> Enter the limit : 5
                   Invalid input


*/


#include <stdio.h>

void negative_fibonacci(int, int, int, int);      // Function declaration

int main()
{
    int limit;

    printf("Enter the limit : ");       // Getting limit from the user
    scanf("%d", &limit);

    negative_fibonacci(limit, 0, 1, 0);    // Calling the function
}


void negative_fibonacci(int limit, int sub, int second, int first)    // Function definition
{

    if (limit > 0)     // Checking if user has entered a valid limit
    {

        printf("Invalid input");

    }


    else if (sub == 0)       // Printing first element without comma
    {
        printf("%d", sub);

        negative_fibonacci(limit, sub = first - second, second = sub, first = second);    // Calling the function recursively
    }


    else if ((sub < 0) && (-sub <= -limit))      // Checking if negative number of the series is within the limit
    {
        printf(", %d", sub);

        negative_fibonacci(limit, sub = first - second, second = sub, first = second);    // Calling the function recursively

    }


    else if ((sub > 0) && (sub <= -limit))     // Checking if positive number of the series is within the limit
    {
        printf(", %d", sub);

        negative_fibonacci(limit, sub = first - second, second = sub, first = second);    // Calling the function recursively

    }

}

