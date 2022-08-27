/*

Name: Shiva.K
Date: 27-07-2022
Description: Finding the second largest element in an array

Sample output: --> Enter the size of the array :5
                   Enter the elements into the array: 5 4 3 2 1
                   Second largest element of the array is 4


*/




#include <stdio.h>

int sec_largest(int [], int);      // Function declaration

int main()
{
    int size, ret, index;       // Declaring required variables


    printf("Enter the size of the array : ");      // Getting array size from the user
    scanf("%d", &size);

    int arr[size];        // Initializing array

    printf("Enter the elements into the array: ");


           for (index = 0; index < size; index++)      // Getting array elements from the user
           {
               scanf("%d", &arr[index]);
           }



          ret = sec_largest(arr, size);        // Calling the function (s_large is returned)

          printf("Second largest element of the array is %d\n", ret);     // Printing the final output
}



int sec_largest(int arr[], int size)      // Function definition
{

    int i, f_large = 0, s_large = 0;


               for (i = 0; i < size; i++)
               {

                     if (arr[i] > f_large)       // True if any element is larger than f_large
                     {
                         s_large = f_large;      // Assign f_large to s_large
                         f_large = arr[i];       // Assign array value to f_large
                     }


                     else if (arr[i] > s_large)     // True if any element is larger than s_large
                     {
                         s_large = arr[i];        // Assign array value to s_large
                     }

                }


      return s_large;           // Return the second largest element of the array

}
