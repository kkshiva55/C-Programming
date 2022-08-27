/*

Name: Shiva.K
Date: 12-08-2022
Description: Variance calculation using Dynamic Arrays

Sample output: --> Enter the no.of elements : 5

                   Enter the 5 elements:
                   [0] -> 10
                   [1] -> 5
                   [2] -> 2
                   [3] -> 8
                   [4] -> 4
                   Variance is 8.160000


*/



#include <stdio.h>
#include <stdlib.h>

float variance(int *, int);         // Function declaration

int main()
{
    int index, len, *arr;
    float result;

    printf("Enter the no.of elements : ");           // Getting array length from the user
    scanf("%d", &len);

    arr = (int *) malloc(len * sizeof(int));         // Dynamically declaring the array

    printf("\nEnter the %d elements:\n", len);

    for (index = 0; index < len; index++)         // Getting array elements from the user
    {
        printf("[%d] -> ", index);
        scanf("%d", &arr[index]);
    }

    result = variance(arr, len);            // Calling the function

    printf("Variance is %f", result);       // Printing the final output

    free(arr);          // Deleting the dynamic memory
    arr = NULL;         // Making dangling pointer as NULL

    return 0;

}


float variance(int *arr, int len)         // Function definition
{
    int index, sum = 0;
    float mean, deviation_sum, *deviation, *deviation_sqr;

    deviation = (float *) malloc(len * sizeof(float));             // Dynamically declaring arrays
    deviation_sqr = (float *) malloc(len * sizeof(float));


       for (index = 0; index < len; index++)        // Calculating the Mean
       {
           sum = sum + arr[index];
       }

    mean = (float) sum / len;

             for (index = 0; index < len; index++)
             {
                 deviation[index] = arr[index] - mean;                            // Computing the deviation
                 deviation_sqr[index] = deviation[index] * deviation[index];      // Finding square of deviation
                 deviation_sum = deviation_sum + deviation_sqr[index];            // Adding deviation square values
             }

       free(deviation);            // Deleting the dynamic memory
       free(deviation_sqr);

       deviation = NULL;           // Making dangling pointer as NULL
       deviation_sqr = NULL;

  return (deviation_sum / len);      // Returning the variance value

}

