/*

Name: Shiva.K
Date: 14-07-2022
Description: Replacing 'n' bits of a given number

Sample output: --> Enter the number: 8
                   Enter number of bits: 2
                   Enter the value: 7
                   Result = 11


*/


#include <stdio.h>

int replace_nbits(int, int, int);    // Declaring the function

int main()
{
    int num, n, val, res = 0;     // Declaring the required variables

    printf("Enter num, n and val:");    // Getting inputs from the user
    scanf("%d%d%d", &num, &n, &val);

    res = replace_nbits(num, n, val);    // Calling the function and storing the value in a variable "res"

    printf("Result = %d\n", res);
}


int replace_nbits(int num, int n, int val)       // Function definition
{

    return ((~((1 << n) - 1) & num) | (((1 << n) - 1) & val));    // Step 1: Clear last 'n' bits of variable "num"
                                                                  // Step 2: Get the last 'n' bits of variable "val"
}                                                                 // Step 3: Perform OR operation and return the value
