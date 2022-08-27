/*

Name: Shiva.K
Date: 23-07-2022
Description: Removing duplicate elements in an array

Sample output: --> Enter the size: 5

                   Enter elements into the array: 2 3 2 5 3

                   After removing duplicates: 2 3 5


*/


#include <stdio.h>

void fun(int arr1[], int size, int arr2[], int *new_size);     // Function declaration

int main()
{
    int index, size;      // Declaring required variables

    printf("Enter the size: ");     // Getting array size from the user
    scanf("%d", &size);

    int arr1[size], arr2[size], arr_len = size, *new_size = &size;   // Declaring array of user specified size


    printf("\nEnter elements into the array: ");

      for (index = 0; index < size; index++)      // Getting array elements from the user
      {
          scanf("%d", &arr1[index]);
      }


       fun(arr1, size, arr2, new_size);       // Calling the function

       printf("\nAfter removing duplicates: ");


             for (index = 0; index < (arr_len - *new_size); index++)     // Printing the array elements after removing the duplicates
             {
                 printf("%d ", arr2[index]);
             }


}



void fun(int arr1[], int size, int arr2[], int *new_size)       // Function definition
{
    int count = 0, i, j;

    arr2[0] = arr1[0];       // Copying the first element

          for (i = 1; i < size; i++)           // Outer loop will be executed upto the array size
          {
               for(j = 0; j < (i - count); j++)      // Inner loop will run depending on the number of duplicates
               {

                     if (arr2[j] == arr1[i])       // True if there is a duplicate element
                     {
                         count++;       // Increment count
                         break;         // Exit from the loop
                     }

                     else if (j == (i - count - 1))       // True if there are no duplicates
                     {
                         arr2[j + 1] = arr1[i];      // Storing the non duplicate element
                     }

               }

           }


      *new_size = count;     // Pointer value to print the final output

}
