/*

Name: Shiva.K
Date: 15-07-2022
Description: Replace (b - a + 1) LSB’s of "num" into val at given position

Sample output: --> Enter the value of 'num' : 47
                   Enter the value of 'a' : 2
                   Enter the value of 'b' : 3
                   Enter the value of 'val': 82
                   Result : 94


*/


#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);    // Function declaration

int main()
{
    int num, a, b, val, res = 0;        // Declaring required variables

    printf("Enter num, a, b, and val:");     // Getting inputs from the user
    scanf("%d%d%d%d", &num, &a, &b, &val);

    res = replace_nbits_from_pos(num, a, b, val);      // Calling the function

    printf("Result = %d\n", res);
}

int replace_nbits_from_pos(int num, int a, int b, int val)      // Function definition
{

    return (((((1 << (b - a + 1)) - 1) & num) << (b - a + 1)) | ((~((((1 << (b - a + 1)) - 1) << (b - a + 1))) & val)));

}

    // Step 1: Left shift '1' by (b - a + 1) times and subtract with '1'
    // Step 2: Perform 'AND' with "num" and left shift by (b - a + 1) times
    // Step 3: All bits are zero expect the position where the bits are to be replaced
    // Step 4: Clear the bits of "val" where the bits are to be replaced
    // Step 5: Perform 'OR' operation between modified "val" and "num"
    // Step 6: Return
