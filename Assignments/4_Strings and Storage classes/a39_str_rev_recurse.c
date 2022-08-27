/*

Name: Shiva.K
Date: 30-07-2022
Description: Reversing the string using Recursion function

Sample output: --> Enter any string : EmertxE
                   Reversed string is ExtremE


*/


#include <stdio.h>

void reverse_recursive(char str[], int ind, int len);      // Function declaration

int main()
{
    char str[30];
    int len;

    printf("Enter any string : ");       // Getting the input string from the user
    scanf("%[^\n]", str);


       for (len = 0; str[len] != '\0'; len++);     // Finding the string length

           reverse_recursive(str, 0, len);       // Calling the function

           printf("Reversed string is %s\n", str);       // Printing the final output
}

void reverse_recursive(char str[], int ind, int len)    // Function definition
{
    int temp;

    if (ind != (len / 2))        // True only if the index value of the string is not equal to half of the string length
    {
        temp = str[ind];
        str[ind] = str[len - ind - 1];       // Swapping the character from first to last
        str[len - ind - 1] = temp;

        reverse_recursive(str, ind + 1, len);      // Calling the function Recursively

    }
}
