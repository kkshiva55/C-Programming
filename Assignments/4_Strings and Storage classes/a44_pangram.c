/*

Name: Shiva.K
Date: 03-08-2022
Description: Checking if given string is "Pangram" or not

Sample output: --> Enter the string: The quick brown fox jumps over the lazy dog

                   The Entered String is a Pangram String


               --> Enter the string: Hello world

                   The Entered String is not a Pangram String


*/


#include <stdio.h>

int pangram(char []);        // Function declaration

int main()
{
    char str[50];
    int ret;

    printf("Enter the string: ");         // Getting input string from the user
    scanf("%[^\n]", str);

    ret = pangram(str);                  // Calling the function

    (ret == 26) ? printf("\nThe Entered String is a Pangram String") : printf("\nThe Entered String is not a Pangram String");

}                                         // Printing the final output



int pangram(char str[])         // Function definition
{
    int arr[26] = {0};          // Declaring array of twenty six zero's
    int index, count = 0;


       for (index = 0; str[index] != '\0'; index++)           // Checking character by character
       {
            if (((str[index] >= 'A') && (str[index] <= 'Z')) && (arr[str[index] - 'A'] != 1))     // True if the character is an uppercase letter and the corresponding array element is zero
            {
                arr[str[index] - 'A'] = 1;      // Replace the corresponding array element with '1'
                count++;
            }

            else if (((str[index] >= 'a') && (str[index] <= 'z')) && (arr[str[index] - 'a'] != 1))   // True if the character is an lowercase letter and the corresponding array element is zero
            {
                arr[str[index] - 'a'] = 1;      // Replace the corresponding array element with '1'
                count++;
            }

       }

    return count;          // Return the number of array elements that contains '1'
}

