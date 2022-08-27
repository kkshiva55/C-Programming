/*

Name: Shiva.K
Date: 06-08-2022
Description: Implementation of "strtok" function

Sample output: --> Enter the string : Hello:;.Hi":.'Bye
                   Enter the delimeter : :;."'
                   Tokens :
                   Hello
                   Hi
                   Bye


*/


#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[]);      // Function declaration

int main()
{
    char str[50], delim[50];

    printf("Enter the string : ");        // Getting input string from the user
    scanf("%s", str);

    __fpurge(stdout);       // Discarding the buffer
    printf("Enter the delimeter : ");        // Getting delimiter from the user
    scanf("\n%s", delim);
    __fpurge(stdout);       // Discarding the buffer

    char *token = my_strtok(str, delim);      // Calling the function
    printf("Tokens :\n");

    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);        // Generating tokens by calling the funnction
    }
}


char *my_strtok(char *str, const char delim[])       // Function definition
{
    static int pos = 0;

    static char *ptr;
    int index , start;

    start = pos;


    if (str != NULL)       // Copying string to the character pointer
    {
        ptr = str;
    }


       while (ptr[pos] != '\0')
       {

             for (index = 0; delim[index] != '\0'; index++)      // Checking for match with delimiter
             {
                 if (ptr[pos] == delim[index])       // True if character is matched with delimiter
                 {
                     ptr[pos] = '\0';     // Replace delimiter character with '\0'
                     pos++;               // Increment pointer

                      if (ptr[start] != '\0')
                      {
                          return (&ptr[start]);     // Return the string after replacing with '\0'
                      }

                      else
                      {
                          start = pos;         // Checking for next string (token)
                          pos--;
                          break;
                      }

                }

             }

           pos++;
       }

    ptr[pos] = '\0';

    if (ptr[start] == '\0')         // Return token or NULL
    {
        return NULL;
    }

    else
    {
        return &ptr[start];
    }

}
