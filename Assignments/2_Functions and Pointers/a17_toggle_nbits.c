/*

Name: Shiva.K
Date: 15-07-2022
Description: Toggle 'n' bits from given position of a number

Sample output: --> Enter the number: 78

                   Enter number of bits: 2

                   Enter the pos: 5

                   Result = 126


*/


#include <stdio.h>

int toggle_nbits_from_pos(int, int, int);     // Function declaration

int main()
{
    int num, n, pos, res = 0;       // Declaring required variables

    printf("Enter num, n and val:");     // Getting inputs from the user
    scanf("%d%d%d", &num, &n, &pos);

    res = toggle_nbits_from_pos(num, n, pos);     // Calling the function

    printf("Result = %d\n", res);
}

int toggle_nbits_from_pos(int num, int n, int pos)     // Function definition
{

    return ((((1 << n) - 1) << (pos - n + 1)) ^ num);  // Step 1: '1' is left shifted "n" times followed by subtraction with '1'
                                                       // Step 2: The above value is left shifted by (pos - n + 1)
}                                                      // Step 3: Perform 'XOR' operation with "num"
