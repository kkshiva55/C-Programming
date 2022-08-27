/*

Name: Shiva.K
Date: 26-08-2022
Description: Generate n*n Magic square

Sample output: --> Enter a number: 3

                   8      1      6

                   3      5      7

                   4      9      2


               --> Enter a number: 6
                   Error : Please enter only positive odd values


*/



#include <stdio.h>
#include <stdlib.h>

void magic_square(int **, int);     // Function declaration

int main()
{
    int size;
    printf("Enter a number: ");
    scanf("%d", &size);

    if (((size % 2) == 0) || (size < 0))       // True if user has entered negative or even number
    {
        printf("Error : Please enter only positive odd values");      // Printing error message
    }

    else
    {
        int **arr;
        magic_square(arr, size);      // Calling the function
    }

  return 0;

}


void magic_square(int **arr, int size)       // Function definition
{
    int value, row = 0, col, sqr;

    arr = calloc(size, sizeof(int *));      // Dynamic memory allocation for rows

    for (col = 0; col < size; col++)
    {
        arr[col] = calloc(size, sizeof(int));     // Dynamic memory allocation for columns
    }

    sqr = size * size;
    col = size / 2;

       for (value = 1; value <= sqr; ++value)      // Loop will run upto the last index value
       {
           arr[row][col] = value;      // Placing the value
           row--;
           col++;

             if (value % size == 0)   // If element is already placed, place the value on the next row
             {
                 row += 2;
                 --col;
             }

             else
             {
                 if (col == size)      // Placing at zeroth column if previous value was placed at (size - 1)th column
                 {
                     col -= size;
                 }

                 else if (row < 0)    // Placing value at (size - 1)th row if previous value was placed at zeroth row
                 {
                     row += size;
                 }
            }
       }

       printf("\n");

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            printf("%d      ", arr[row][col]);          // Printing the final output
        }
        printf("\n\n");
    }


          for (col = 0; col < size; col++)
          {
              free(arr[col]);       // Freeing Dynamically allocated memory for columns
          }

        free(arr);        // Freeing Dynamically allocated memory for rows
        arr = NULL;       // Making dangling as NULL

}
