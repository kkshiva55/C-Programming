/*

Name: Shiva.K
Date: 10-08-2022
Description: Printing all possible combinations of given string

Sample output: --> Enter a string: sdp

                   All possible combinations of given string :
                   sdp
                   spd
                   dsp
                   dps
                   pds
                   psd


               --> Enter a string: aab

                   Error: please enter distinct characters.


*/


#include<stdio.h>

void combination(char [],int ,int );      // Declaring all required functions
int my_strlen(char []);
void swap(char *, char *);

int main()

{
        char str[100];
        int n, i, j;
        int res;
        printf("Enter a string: ");         // Getting input string from the user
        scanf("%100[^\n]",str);
        n = my_strlen(str);             // Computing the string length

        for (i = 0; i < n - 2; i++)         // Checking for distinct string characters
        {
            for (j = i + 1; j < n; j++)
            {
                if (str[i] == str[j])
                {
                    printf("\nError: please enter distinct characters.");
                    return 0;
                }
            }
        }
        printf("\nAll possible combinations of given string : \n");

        combination(str,0,n-1);       // Calling the function
        return 0;
}


int my_strlen(char str[])        // Function definition for calculating the string length
{
    int len_str;

    for (len_str = 0; str[len_str] != '\0'; len_str++);

         return len_str;        // Returning the length of the string
}


void combination(char str[], int l, int r)       // Function definition to find the combinations
{
    int i;

    if (l == r)
    {
        printf("%s\n", str);
    }

    else
    {
        for (i = l; i <= r; i++)
        {
            swap((str + l), (str + i));      // Swapping the adjacent characters
            combination(str, l + 1, r);      // Recursive function call
            swap((str + l), (str + i));      // Swapping the adjacent characters
        }
    }
}


void swap(char *x, char *y)       // Function definition for swapping adjacent characters
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

