/*

Name: Shiva.K
Date: 06-07-2022
Description: Printing 'X' pattern of numbers

Sample output: --> Enter the number: 6
                   1    6
                    2  5
                     34
                     34
                    2  5
                   1    6

               --> Enter the number: 7
                   1     7
                    2   6
                     3 5
                      4
                     3 5
                    2   6
                   1     7

*/




#include <stdio.h>

int main ()
{

    int row, col, num, dec, mid;      // Initialization of all required variables

    printf("Enter the number: ");     // Getting input from the user

    scanf("%d", &num);          // Storing input value at the address of variable 'num'

    dec = num;

    mid = (num / 2) + 1;    // Calculating middle value (For odd inputs)




    for(row = 0; row < num; row++)         // Loop will be executed upto the given input
    {
          for(col = 0; col < num; col++)
          {

                 if(row == col)         // Printing incrementing diagonal elements
                 {

                    printf("%d", row + 1);

                 }

                else if(col == num - row - 1)      // Printing decrementing diagonal elements
                {

                       if (row == col != mid)      // For odd inputs, the middle values appear only once
                       {

                          printf("%d", dec);

                       }

                }

                else         // Printing spaces
                {

                   printf(" ");

                }


          }

            dec--;       // Decrementing the previous value

            printf("\n");

    }

    return 0;

}
