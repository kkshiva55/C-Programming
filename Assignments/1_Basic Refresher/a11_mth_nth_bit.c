/*

Name: Shiva.K
Date: 07-07-2022
Description: Checking if N-th bit is set, if yes --> Clear the M-th bit

Sample output: --> Enter the number: 325

                   Enter 'N': 2

                   Enter 'M': 6

                   Updated value of num is 261


*/



#include <stdio.h>

int main ()
{
    unsigned int num, nth, mth;         // To perform bitwise operation, unsigned variables are declared

    printf("Enter the number: ");       // Getting the number

    scanf("%u", &num);

    printf("\nEnter 'N': ");        // Getting the N-th bit

    scanf("%u", &nth);

    printf("\nEnter 'M': ");        // Getting the M-the bit

    scanf("%u", &mth);


    nth = num >> nth;        // Right shifting until N-th bit appears at the last



    if(nth & 01)         // True if N-th bit is set
    {

        num = (~(1 << mth)) & num;     // Clearing M-th bit

    }


    printf("\nUpdated value of num is %d", num);     // Printing the updated decimal value


    return 0;

}
