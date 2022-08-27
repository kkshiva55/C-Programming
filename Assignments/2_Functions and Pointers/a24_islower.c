/*

Name: Shiva.K
Date: 21-07-2022
Description: Implementation of "islower" function

Sample output: --> Enter the character: a
                   Entered character is lower case alphabet

               --> Enter the character: A
                   Entered character is not lower case alphabet


*/


#include <stdio.h>

int my_islower(int);      // Function declaration

int main()
{
    char ch;         // Declaring required variables
    int ret;

    printf("Enter the character:");      // Getting input from the user
    scanf("%c", &ch);

    ret = my_islower(ch);     // Calling the function

    (ret != 0) ? printf("Entered character is lower case alphabet") : printf("Entered character is not lower case alphabet");

                 // Ternary operator to print whether the entered character is lowercase or not

}

int my_islower(int ch)
{

    return ((ch >= 'a') && (ch <= 'z'));

}        // Returns non zero value when the input character is lowercase
         // Returns zero when input character is not lowercase
