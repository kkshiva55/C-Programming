/*

Name: Shiva.K
Date: 07-07-2022
Description: Counting number of set bits and printing parity

Sample output: --> Enter the number : 34

                   Number of set bits = 2

                   Bit parity is Even


               --> Enter the number : 8

                   Number of set bits = 1

                   Bit parity is Odd

*/




#include <stdio.h>

int main ()
{

    unsigned int num, inc = 0;             // To perform bitwise operation, unsigned variables are declared


    printf("Enter the number : ");      // Getting input from the user

    scanf("%u", &num);        // Storing the input at the address of variable "num"



    while(num != 0)      // Loop will terminate when "num" is equal to zero
    {

           if(num & 01)     // True if last bit value is one
           {

               inc++;    // Increment when bit value is one

           }


        num >>= 1;    // Right shift to check bits one by one

    }


        printf("\nNumber of set bits = %d\n", inc);       // Printing number of 1's present in the given input



   if(inc & 01)       // True if last bit of "inc" is one
   {

       printf("\nBit parity is Odd");     // If last bit is one, the parity is odd


   }

   else
   {

       printf("\nBit parity is Even");    // If last bit is zero, the parity is even


   }

    return 0;

}
