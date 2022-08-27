/*

Name: Shiva.K
Date: 06-07-2022
Description: Printing triangle pattern of numbers

Sample output: --> Enter the number: 4
                   1 2 3 4
                   5   6
                   7 8
                   9

*/




#include <stdio.h>

int main()
{

    int input, row, col, inc = 1;       // Initializing all variables

    printf("Enter the number: ");          // Getting input from the user

    scanf("%d", &input);



      for(row = 1; row <= input; row++)        // Loop will be executed upto given number
      {

            for(col = input - row; col >= 0; col--)      // Loop will be executed (input - row) times
            {

                     if(row == 1)        // Printing the first row elements
                     {

                        printf("%d ", inc);

                        inc++;

                     }

                     else if((col == input - row) || (col == 0))     // Checking condition to print numbers to obtain the desired pattern
                     {

                        printf("%d ", inc);

                        inc++;

                     }


                     else          // Adding spaces
                     {

                       printf("  ");

                     }


            }

               printf("\n");

      }

      return 0;

}
