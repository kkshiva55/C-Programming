/*

Name: Shiva.K
Date: 14-07-2022
Description: Printing 'n' bits from LSB of a number

Sample output: --> Enter the number: 7

                   Enter number of bits: 8

                   Binary form of 7: 0 0 0 0 0 1 1 1


*/



#include <stdio.h>

void print_bits(int, int);    // Declaring function

int main()
{
    int num, n;     // Declaring local variables

    printf("Enter num, n :\n");    // Getting inputs from the user
    scanf("%d%d", &num, &n);

    printf("Binary form of %d:", num);
    print_bits(num, n);      // Calling the function
 }


 void print_bits(int num, int n)     // Function Definition
 {
     int bits;

       if (n > (sizeof (int) * 8))     // True if user enters more than 32 bits
       {
           n = sizeof (int) * 8;      // n value is modified as 32 bits
       }


             for (bits = n - 1; bits >= 0; bits--)       // Printing the required bits one by one
            {

                printf("%d ", ((num >> bits) & 1));     // Step 1: Right shift is performed so that the bit goes to the last
                                                        // Step 2: AND operation is performed to get the last bit
            }


 }
