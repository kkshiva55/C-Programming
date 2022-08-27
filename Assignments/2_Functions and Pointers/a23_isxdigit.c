/*

Name: Shiva.K
Date: 21-07-2022
Description: Implementation of "isxdigit" function

Sample output: --> Enter a character: D
                   Entered character is an hexadecimal digit

               --> Enter a character: s
                   Entered character is not an hexadecimal digit


*/



#include <stdio.h>

int is_xdigit(int);      // Function declaration

int main()
{
    char ch;        // Declaring required variables
    short ret;

    printf("Enter a character: ");   // Getting input from the user
    scanf("%c", &ch);

    ret = is_xdigit(ch);     // Calling the function

    (ret != 0) ? printf("Entered character is an hexadecimal digit") : printf("Entered character is not an hexadecimal digit");

                             // Ternary operator to print whether entered input is HEXADECIMAL or not
    return 0;
}

int is_xdigit(int ch)       // Function definition
{

    return (((ch >= '0') && (ch <= '9')) || ((ch >= 'A') && (ch <= 'F')) || ((ch >= 'a') && (ch <= 'f')));

}               // Condition is checked according to their ASCII values
                // Returns non zero value if entered input is Hexadecimal digit
                // Returns zero if entered input is not a Hexadecimal digit


