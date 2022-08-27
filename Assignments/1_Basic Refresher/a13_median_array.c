/*

Name: Shiva.K
Date: 12-07-2022
Description: Finding Median of two unsorted arrays

Sample output: --> Enter the 'n' value for Array A: 4
                   Enter the 'n' value for Array B: 3

                   Enter the elements one by one for Array A: 12 7 5 8
                   Enter the elements one by one for Array B: 3 1 2

                   Median of array1 : 7.5
                   Median of array2 : 2
                   Median of both arrays : 4.75


*/


#include <stdio.h>

int main ()
{

    int arr1_len, arr2_len, index_a, index_b, i, j, var;    // Declaring variables
    float median_a, median_b;

    printf("Enter the 'n' value for Array A: ");    // Getting the size of Array A from the user
    scanf("%d", &arr1_len);

    printf("Enter the 'n' value for Array B: ");    // Getting the size of Array B from the user
    scanf("%d", &arr2_len);

    int arr_a[arr1_len], arr_b[arr2_len];          // Declaring Array A and Array B of size which is given by the user



    printf("\nEnter the elements one by one for Array A: ");

    for (index_a = 0; index_a <= arr1_len - 1; index_a++)      // Storing the elements of Array A one by one
    {

        scanf("%d", &arr_a[index_a]);

    }


    printf("\nEnter the elements one by one for Array B: ");

    for (index_b = 0; index_b <= arr2_len - 1; index_b++)      // Storing the elements of Array B one by one
    {

        scanf("%d", &arr_b[index_b]);

    }


            // Sorting Array A in Ascending order


           for (i = 0; i <= arr1_len - 1; i++)        // "For loops" for performing Bubble sort algorithm
           {

               for (j = 0; j < arr1_len - i - 1; j++)
               {

                   if (arr_a[j] > arr_a[j + 1])       // Comparing adjacent elements
                   {
                       var = arr_a[j];
                       arr_a[j] = arr_a[j + 1];       // Swapping numbers if adjacent element is smaller
                       arr_a[j + 1] = var;
                   }

               }

           }


            //Sorting Array B in ascending order


           for (i = 0; i <= arr2_len - 1; i++)          // "For loops" for performing Bubble sort algorithm
           {

               for (j = 0; j < arr2_len - i - 1; j++)
               {

                   if (arr_b[j] > arr_b[j + 1])         //  Comparing adjacent elements
                   {
                       var = arr_b[j];
                       arr_b[j] = arr_b[j + 1];        // Swapping numbers if adjacent element is smaller
                       arr_b[j + 1] = var;
                   }

               }

           }


        if (arr1_len % 2 == 0)          // Calculating median of Array A for even number of array elements
        {

            arr1_len = (arr1_len / 2) - 1;

            median_a = (float)(arr_a[arr1_len] + arr_a[arr1_len + 1]) / 2;     // Computing the median of Array A

            printf("\nMedian of array1 : %g", median_a);

        }

        else       // Calculating median of Array A for odd number of array elements
        {

            arr1_len = arr1_len / 2;

            median_a = arr_a[arr1_len];     // Computing the median of Array A

            printf("\nMedian of array1 : %g", median_a);

        }



        if (arr2_len % 2 == 0)    // Calculating median of Array B for even number of array elements
        {

            arr2_len = (arr2_len / 2) - 1;

            median_b = (float)(arr_b[arr2_len] + arr_b[arr2_len + 1]) / 2;    // Computing the median of Array B

            printf("\nMedian of array2 : %g", median_b);

        }

        else     // Calculating median of Array B for odd number of array elements
        {

            arr2_len = arr2_len / 2;

            median_b = arr_b[arr2_len];     // Computing the median of Array B

            printf("\nMedian of array2 : %g", median_b);

        }


       printf("\nMedian of both arrays : %g", ((median_a + median_b) / 2));  // Printing the median of both Array A and Array B


       return 0;

}
