/*

Name: Shiva.K
Date: 29-07-2022
Description: Replacing string of one or more blanks by a single blank

Sample output: --> Enter the string with more spaces in between two words
                   Hello     how    are you
                   Hello how are you


*/



#include <stdio.h>

void replace_blank(char []);        // Function declaration

int main()
{
    char str[];

    printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);       // Getting the input until user press the "ENTER" key

    replace_blank(str);         // Calling the function

    printf("%s\n", str);        // Printing the final output
}


void replace_blank(char str[])        // Function definition
{
    int i = 0, j = 0, check;


         while (str[i] != '\0')        // Checking the elements upto the NULL
         {
             check = 0;          // Assigning a temporary variable to zero


                  if ((str[i] == ' ') && (str[i + 1] == ' '))     // True only if the present and next element contains space
                  {

                          for (j = i + 1; str[j] != '\0'; j++)    // Shifting all elements one by one to the left
                          {
                              str[j] = str[j + 1];
                          }

                     check = 1;      // Assigning temporary variable to one, after performing the shifting
                  }


                  if (check == 0)      // True only if shifting is not performed
                  {
                      i++;         // Checking for next element
                  }

         }

      str[i] = '\0';         // Assigning last character as NULL

}
