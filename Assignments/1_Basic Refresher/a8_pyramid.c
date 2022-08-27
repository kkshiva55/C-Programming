/*

Name: Shiva.K
Date: 07-07-2022
Description: Printing pyramid pattern of numbers

Sample output: --> Enter the number: 4
                   4
                   3 4
                   2 3 4
                   1 2 3 4
                   2 3 4
                   3 4
                   4

*/




#include <stdio.h>

int main()
{

    int row, col, input, inc, dec;          // Declaring required variables


    printf("Enter the number: ");       // Getting input from the user

    scanf("%d", &input);          // Storing input value at the address of variable "input"


    inc = input;          // Storing the starting value of pattern



    // Increasing pattern of numbers


    for(row = 1; row <= input; row++)          // Outer loop will be executed upto the given input
    {

           for(col = 1; col <= row; col++)       // Inner loop will be executed upto present row value
           {

               printf("%d ", inc);       // Printing the number


               inc ++;          // Incrementing the number

           }


             inc = input - row;      // Storing starting value for next row


             printf("\n");

    }



    // Decreasing pattern of numbers



    for(row = 0; row < input; row++)          // Outer loop will be executed upto the given input
    {

        dec = row + 2;       // Storing starting value of the present row


           for(col = input - row - 1; col >= 1; col--)      // Inner loop will be executed as decreasing pattern
           {

              printf("%d ", dec);        //  Printing the number


              dec++;        // Incrementing the number

           }


              printf("\n");

    }

    return 0;

}
