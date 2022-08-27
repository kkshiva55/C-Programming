/*

Name: Shiva.K
Date: 01-08-2022
Description: Implementing "ATOI" function

Sample output: --> Enter a numeric string : 2505AO
                   String to integer is 2505

               --> Enter a numeric string : Bcd25
                   String to integer is 0

               --> Enter a numeric string : -525
                   String to integer is -525


*/


#include <stdio.h>

int my_atoi(const char []);       // Function declaration

int main()
{
    char str[20];

    printf("Enter a numeric string : ");       // Getting input string from the user
    scanf("%s", str);

    printf("String to integer is %d\n", my_atoi(str));       // Calling the function and the final output is printed
}


int my_atoi(const char str[])         // Function definition
{
    int result = 0, neg = 0, digit;

     if (*str == '+')        // True if the first character is '+'
     {
         str++;        // Increment the pointer
     }

     else if (*str == '-')        // True if the first character is '-'
     {
         neg--;          // Storing neg = -1
         str++;          // Increment the pointer
     }

          while (*str)                // Checking the elements upto NULL
          {
              digit = (*str++) - '0';              // Subtracting from 48 to get equivalent integer value

                   if ((digit >= 0) && (digit <= 9))        // Checking if digit is within the range
                   {
                       result = digit + (result * 10);       // Storing the character as an integer
                   }

                   else
                   {
                       break;              // If digit is not within the range, exit from the loop
                   }

         }

    return (neg < 0) ? result * neg : result;       // If input is negative then multiply the result with -1 and return, else return the result
}
