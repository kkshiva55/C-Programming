/*

Name: Shiva.K
Date: 15-07-2022
Description: Circular Left Shift

Sample output: --> Enter the num:-13
                   Enter n:4
                   Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 1


*/



#include <stdio.h>

int circular_left(int, int);     // Function declaration for Circular left shift
void print_bits(int);       // Function declaration for printing the bits

int main()
{
    int num, n, ret;       // Declaring the required variables

    printf("Enter the num:");    // Getting decimal value ( +ve (or) -ve ) from the user
    scanf("%d", &num);

    printf("Enter n:");      // Getting the shift value from the user
    scanf("%d", &n);

    ret = circular_left(num, n);      // Calling the Circular left shift function

    print_bits(ret);       // Calling the function to print Circularly left shifted bits
}

int circular_left(int num, int n)        // Function definition for Circular left shift
{

    return ((num << n) | ((num >> ((sizeof (int) * 8) - n)) & ((1 << n) - 1)));     // Left shifted by 'n' bits and lost LSB's are placed as MSB's
                                                                                    // Output consists of 32 bits
}

void print_bits(int ret)      // Function definition for printing the Circularly left shifted bits
{
    int bits;

    printf("Result in Binary: ");

        for (bits = ((sizeof (int) * 8) - 1); bits >= 0; bits--)       // Printing 32 bits
        {

            printf("%d ", ((ret >> bits) & 1));

        }

}
