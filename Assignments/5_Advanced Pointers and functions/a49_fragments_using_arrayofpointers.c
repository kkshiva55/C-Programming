/*

Name: Shiva.K
Date: 26-08-2022
Description: Implementing fragments using Array of Pointers

Sample output: --> Enter no.of rows : 3
                   Enter no of columns in row[0] : 3
                   Enter no of columns in row[1] : 2
                   Enter no of columns in row[2] : 4
                   Enter 3 values for row[0] : 8 3 2
                   Enter 2 values for row[1] : 6 3
                   Enter 4 values for row[2] : 3 7 2 1


                   Before sorting output is:

                   8.000000 3.000000 2.000000 4.333333

                   6.000000 3.000000 4.500000

                   3.000000 7.000000 2.000000 1.000000 3.250000



                   After sorting output is:

                   3.000000 7.000000 2.000000 1.000000 3.250000

                   8.000000 3.000000 2.000000 4.333333

                   6.000000 3.000000 4.500000


*/


#include <stdio.h>
#include <stdlib.h>

int fragments(int, float *[]);      // Function declaration

int main()
{
    int size;
    printf("Enter no.of rows : ");     // Getting number of rows from the user
    scanf("%d", &size);
    float *ptr[size];          // Initializing rows as static memory (ptr holds the addresses of float array)

    fragments(size, ptr);     // Calling the function

    return 0;

}


int fragments(int size, float *ptr[size])      // Function definition
{
   int i, j, temp_int;
   float *temp_float;
   float sum = 0;
   int arr[size];       // Array to store number of columns + 1 (Last element to store average)

    for (i = 0; i < size; i++)
    {
        printf("Enter no of columns in row[%d] : ", i);
        scanf("%d", &arr[i]);
        arr[i] = arr[i] + 1;        // Adding 1 so that last element to store average value
        ptr[i] = malloc((arr[i]) * sizeof(float));    // Dynamic memory allocation for float arrays(column of ptr)
    }

           for (i = 0; i < size; i++)
           {
               printf("Enter %d values for row[%d] : ", arr[i] - 1, i);

               for (j = 0; j < (arr[i] - 1); j++)
               {
                   scanf("%f", &ptr[i][j]);         // Getting column values from the user
                   sum += ptr[i][j];                // Adding array elements one by one
               }

              ptr[i][j] = sum / (arr[i] - 1);        // Storing average value at the last column value
              sum = 0;
            }

          printf("\nBefore sorting output is:\n\n");      // Printing values before sorting

             for (i = 0; i < size; i++)
             {
                 for (j = 0; j < arr[i]; j++)
                 {
                     printf("%f ", ptr[i][j]);
                 }
                 printf("\n\n");
             }



             for (i = 0; i < size; i++)        // Sorting arrays using Bubble sort technique
             {
                 for(j = 0; j < size - i - 1; j++)
                 {
                     if (ptr[j][arr[j] - 1] > ptr[j + 1][arr[j + 1] - 1])   // Arranging arrays so that average values will be in ascending order
                     {
                         temp_float = ptr[j];
                         ptr[j] = ptr[j + 1];         // Swapping pointer address so that average value should be in ascending order
                         ptr[j + 1] = temp_float;

                         temp_int = arr[j];
                         arr[j] = arr[j + 1];        // Swapping array(contains column size) according to average value in ascending order
                         arr[j + 1] = temp_int;
                     }
                 }
              }

  printf("\nAfter sorting output is:\n\n");         // Printing the sorted output

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < arr[i]; j++)
        {
            printf("%f ", ptr[i][j]);
        }
    printf("\n\n");
    }

    for (i = 0; i < size; i++)
    {
        free(ptr[i]);           // Freeing Dynamically allocated column memory
    }

       ptr = NULL;           // Making dangling pointer as NULL

}

