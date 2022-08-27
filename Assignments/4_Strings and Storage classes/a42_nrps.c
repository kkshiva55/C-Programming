/*

Name: Shiva.K
Date: 10-08-2022
Description: Generate consecutive NRPS of length n using k distinct character

Sample output: --> Enter the number characters C : 4
                   Enter the Length of the string N : 12
                   Enter 4 distinct characters : s d p a
                   Possible NRPS is sdpadpaspasd


*/


#include <stdio.h>

void nrps(char [], int, int);         // Function declaration

int main()
{
    int len, chars, i, j;


    printf("Enter the number characters C : ");         // Getting the number of characters from the user
    scanf("%d", &chars);



    printf("Enter the Length of the string N : ");        // Getting NRPS length from the user
    scanf("%d", &len);
    char str[chars + 1];

    printf("Enter %d distinct characters : ", chars);

    for (i = 0; i < chars; i++)
    {
          scanf("\n%c", &str[i]);         // Getting the characters one by one from the user
    }


        for (i = 0; i < chars; i++)           // Checking if all characters are distinct
        {
            for (j = i + 1; j < chars; j++)
            {
                if(str[j] == str[i])
                {
                    printf("Error: values are not distinct.\n");
                    return 0;
                }
            }
        }

    printf("Possible NRPS is ");
    nrps(str, len, chars);          // Calling the function

    return 0;
}



void nrps(char str[] , int len, int chars)          // Function definition
{
    int i, inc = 0;

    for (i = 0; i < len; i++)               // Generating the NRPS Pattern
    {
        if ((i % chars == 0) && (i != 0))
		{
			inc++;
		}

       str[i] = *(str + ((i + inc) % chars));
    }

    str[i] = '\0';         // Placing NULL at the last element

    printf("%s", str);      // Printing the NRPS Pattern
}
