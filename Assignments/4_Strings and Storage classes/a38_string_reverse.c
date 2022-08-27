/*

Name: Shiva.K
Date: 30-07-2022
Description: String reversal using iterative method

Sample output: --> Enter any string : ExtremE
                   Reversed string is EmertxE


*/


#include <stdio.h>

void reverse_iterative(char str[]);       // Function declaration

int main()
{
    char str[30];

    printf("Enter any string : ");       // Getting input string from the user
    scanf("%[^\n]", str);

    reverse_iterative(str);        // Calling the function

    printf("Reversed string is %s\n", str);        // Printing the final output
}


void reverse_iterative(char str[])      // Function definition
{
    int i, len_str, temp;

       for (len_str = 0; str[len_str] != '\0'; len_str++);       // Computing the string length


            for (i = 0; i < len_str / 2; i++)         // Swapping the characters from last to first
             {
                 temp = str[i];
                 str[i] = str[len_str - i - 1];
                 str[len_str - i - 1] = temp;
             }


}

