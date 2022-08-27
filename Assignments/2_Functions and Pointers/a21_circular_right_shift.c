/*

Name: Shiva.K
Date: 15-07-2022
Description: Circular Right Shift

Sample output: --> Enter the num:-22
                   Enter n:4
                   Result in Binary: 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0


*/



#include <stdio.h>

int circular_right(int, int);      // Function declaration for Circular Right Shift
void print_bits(int);              // Function declaration for printing the bits

int main()
{
    int num, n, ret;       // Declaring the required variables

    printf("Enter the num:");     // Getting decimal value ( +ve (or) -ve ) from the user
    scanf("%d", &num);

    printf("Enter n:");        // Getting the shift value from the user
    scanf("%d", &n);

    ret = circular_right(num, n);        // Calling the function to perform Circular Right Shift

    print_bits(ret);         // Calling the function to print Circularly Right Shifted bits
}


int circular_right(int num, int n)     // Function definition for performing Circular Right Shift
{

    return (((num >> n) & ((1 << ((sizeof (int) * 8) - n)) - 1)) | (num << ((sizeof (int) * 8) - n)));

}                                     // Right shifted by 'n' times and the lost LSB's are placed as MSB's

void print_bits(int ret)      // Function definition for printing Circularly Right Shifted bits
{
    int bits;

    printf("Result in Binary: ");


          for (bits = ((sizeof (int) * 8) - 1); bits >= 0; bits--)    // Printing 32 bits
          {

              printf("%d ", ((ret >> bits) & 1));

          }

}
