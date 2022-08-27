/*

Name: Shiva.K
Date: 21-07-2022
Description: Implementation of "ispunct" function

Sample output: --> Enter the character: ~
                   Entered character is punctuation character

               --> Enter the character: 5
                   Entered character is not punctuation character


*/


#include <stdio.h>

int my_ispunct(int);      // Function declaration

int main()
{
    char ch;       // Declaring required variables
    int ret;

    printf("Enter the character:");       // Getting input from the user
    scanf("%c", &ch);

    ret = my_ispunct(ch);       // Calling the function

    (ret != 0) ? printf("Entered character is punctuation character") : printf("Entered character is not punctuation character");

                             // Ternary operator which prints whether the input character is "Punctuation" or not
}


int my_ispunct(int ch)     // Function definition
{

    return (((ch >= '!') && (ch <= '/')) || ((ch >= ':') && (ch <= '@')) || ((ch >= '[') && (ch <= '`')) || ((ch >= '{') && (ch <= '~')));

}             // Condition to check according to their ASCII values
              // Returns non zero value when the input character is Punctuation character
              // Returns zero when the input character is not Punctuation character

