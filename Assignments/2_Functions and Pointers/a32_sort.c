/*

Name: Shiva.K
Date: 30-07-2022
Description: Sorting array in ascending order without modifying or copying array

Sample output: --> Enter the size of the array : 5
                   Enter the 5 elements
                   12 4 1 5 8
                   After sorting: 1 4 5 8 12
                   Original array values 12 4 1 5 8


*/


#include <stdio.h>

void print_sort(int [], int);       // Function declaration

int main()
{
    int size, iter;

    printf("Enter the size of the array : ");     // Getting array size from the user
    scanf("%d", &size);

    int arr[size];

    printf("Enter the %d elements\n");

       for (iter = 0; iter < size; iter++)     // Getting the array elements one by one
       {
           scanf("%d", &arr[iter]);
       }

    print_sort(arr, size);       // Calling the function

    printf("\nOriginal array values ");


               for (iter = 0; iter < size; iter++)       // Printing the array before sorting
               {
                   printf("%d ", arr[iter]);
               }


}


void print_sort(int arr[], int size)        // Function definition
{
    int index, sec_small, value, large = arr[0], small = arr[0];


        for (index = 0; index < size; index++)       // Finding the largest and smallest element in the array
        {
             if (arr[index] > large)
             {
                 large = arr[index];
             }

             if (arr[index] < small)
             {
                 small = arr[index];
             }

        }

      sec_small = large;          // Assign large to second large

     printf("After sorting: ");


        for (value = 0; value < size; value++)
        {
            printf("%d ", small);         // Printing the elements in sorted order

                for (index = 0; index < size; index++)
                {
                      if ((arr[index] > small) && (arr[index] < sec_small))    // True only if any array element is greater than small and less than second small
                      {
                          sec_small = arr[index];       // Assign array element to second small
                      }

                }

               small = sec_small;      // Assign second small to small
               sec_small = large;      // Assign large to second small

        }

}
