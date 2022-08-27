/*

Name: Shiva.K
Date: 27-07-2022
Description: Finding the Third largest element in an array

Sample output: --> Enter the size of the array : 5
                   Enter the elements into the array: 12 3 2 6 8
                   Third largest element of the array is 6


*/



#include <stdio.h>

int third_largest(int [], int);        // Function declaration

int main()
{
    int size, ret, index;        // Declaring the required variables


    printf("Enter the size of the array : ");       // Getting input from the user
    scanf("%d", &size);

    int arr[size];       // Initializing array

    printf("Enter the elements into the array: ");



             for (index = 0; index < size; index++)       // Getting array elements from the user
             {
                 scanf("%d", &arr[index]);
             }



    ret = third_largest(arr, size);        // Calling the function

    printf("Third largest element of the array is %d\n", ret);      // Printing the final output
}


int third_largest(int arr[], int size)       // Function definition
{

    int i, max1 = 0, max2 = 0, max3 = 0;

         for (i = 0; i < size; i++)
         {

               if (max1 < arr[i])      // True if any element is less than max1
               {
                   max3 = max2;      // Assign max2 to max3
                   max2 = max1;      // Assign max1 to max2
                   max1 = arr[i];    // Assign array value to max1
               }

               else if ((max2 <= arr[i]) && (max1 > arr[i]))    // True if any element is greater than or equal to max2 and less than max1
               {
                   max3 = max2;        // Assign max2 to max3
                   max2 = arr[i];      // Assign array value to max2
               }

               else if ((max3 < arr[i]) && (max1 > arr[i]))    // True if any element is greater than max3 and less than max1
               {
                   max3 = arr[i];      // Assign array value to max3
               }

         }


    return max3;        // Return third largest value of the array

}
