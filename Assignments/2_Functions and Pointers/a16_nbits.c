/*

Name: Shiva.K
Date: 15-07-2022
Description: Get 'n' bits from given position of a number

Sample output: --> Enter the number: 125

                   Enter number of bits: 5

                   Enter the pos: 4

                   Result = 29


*/


#include <stdio.h>

int get_nbits_from_pos(int, int, int);     // Function declaration

int main()
{
    int num, n, pos, res = 0;        // Declaring required variables

    printf("Enter num, n and val:");      // Getting inputs from the user
    scanf("%d%d%d", &num, &n, &pos);

    res = get_nbits_from_pos(num, n, pos);     // Calling the function

    printf("Result = %d\n", res);
}

int get_nbits_from_pos(int num, int n, int pos)      // Function definition
{

    return ((num >> (pos - n + 1)) & ((1 << n) - 1));  // Step 1: Right shift "num" by (pos - n + 1)
                                                       // Step 2: '1' is left shifted by "n" times and subtract with '1'
}                                                      // Step 3: Perform 'AND' operation
