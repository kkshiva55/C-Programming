/*

Name: Shiva.K
Date: 14-07-2022
Description: Getting 'n' bits of a given number

Sample output: --> Enter the number: 15

                   Enter number of bits: 3

                   Result = 7


*/


#include <stdio.h>

int get_nbits(int, int);      // Declaring the function

int main()
{
    int num, n, res = 0;      // Declaring required variables

    printf("Enter num and n:");    // Getting inputs from the user
    scanf("%d%d", &num, &n);

    res = get_nbits(num, n);       // Calling the function and storing the value in the variable "res"

    printf("Result = %d\n", res);   // Printing the final decimal value
}

int get_nbits(int num, int n)     // Function definition
{

    return (((1 << n) - 1) & num);    // Returns the value of last 'n' bits

}
