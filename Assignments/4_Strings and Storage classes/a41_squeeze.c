/*

Name: Shiva.K
Date: 03-08-2022
Description: Squeeze the character in String1 that matches any character in the String2

Sample output: --> Enter string1: Hello world
                   Enter string2: low
                   After squeeze s1 : He rd


*/



#include <stdio.h>
#include <stdio_ext.h>

void squeeze(char [], char []);        // Function declaration

int main()
{
    char str1[30], str2[30];

    printf("Enter string1: ");        // Getting input String1
    scanf("%[^\n]", str1);

    __fpurge(stdin);                // Discarding the input buffer
    printf("Enter string2: ");
    scanf("%[^\n]", str2);          // Getting input String2

    squeeze(str1, str2);           // Calling the function

    printf("After squeeze s1 : %s\n", str1);       // Printing the final output

}



void squeeze(char str1[], char str2[])      // Function definition
{

    int index1, index2, shift;

    for (index1 = 0; str1[index1] != '\0'; index1++)        // Checking for every character in string 2
    {
        for (index2 = 0; str2[index2] != '\0'; index2++)
        {
            if (str1[index1] == str2[index2])           // True if character is matched
            {
                for (shift = index1; str1[shift] != '\0'; shift++)     // Shifting characters of string 1 to the left
                {
                    str1[shift] = str1[shift + 1];
                }

                index1--;         // Repeat the same process until all matched characters are squeezed
            }
        }
    }

    str1[index1] = '\0';
}

