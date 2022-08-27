/*

Name: Shiva.K
Date: 29-07-2022
Description: Implementing "getword" function

Sample output: --> Enter the string : Hello welcome
                   You entered Hello and the length is 5


*/



#include <stdio.h>

int getword(char str[]);       // Function declaration

int main()
{
        int len = 0;          // Declaring required variables
	    char str[100];

		printf("Enter the string : ");        // Getting input until user press the "ENTER" key
		scanf(" %[^\n]", str);

		len = getword(str);         // Calling the function

        printf("You entered %s and the length is %d\n", str, len);        // Printing the final output
}



int getword(char str[])         // Function definition
{

    int i, count = 0;


         for (i = 0; str[i] != '\0'; i++)        // Checking upto the last element
         {
               if (str[i] == ' ')       // True if string contains space
               {
                   str[i] = '\0';      // Assign last element as '\0'
                   break;
               }

               else
               {
                   count++;         // Counting the number of characters
               }

         }

         return count;        // Return the string length

}
