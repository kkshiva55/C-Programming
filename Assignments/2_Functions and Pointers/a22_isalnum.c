/*

Name: Shiva.K
Date: 21-07-2022
Description: Implementation of "isalnum" function

Sample output: --> Enter the character: 8
                   The character '8' is an alnum character.

               --> Enter the character: *
                   The character '*' is not an alnum character.


*/



#include <stdio.h>

int my_isalnum(char);      // Function declaration

int main()
{
    char ch;         // Declaring required variables
    int ret;

    printf("Enter the character:");      // Getting input from the user
    scanf("%c", &ch);

    ret = my_isalnum(ch);      // Calling the function

    (ret != 0) ? printf("The character '%c' is an alnum character.", ch) : printf("The character '%c' is not an alnum character.", ch);

             // Ternary operator to print whether entered character is "alnum" or not
}



int my_isalnum(char ch)
{

    return (((ch >= '0') && (ch <= '9')) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')));

}
            // Condition is checked with respect to their "ASCII" values
            // Returns zero if entered character is not "alnum"
            // Returns non zero value if entered character is "alnum"
