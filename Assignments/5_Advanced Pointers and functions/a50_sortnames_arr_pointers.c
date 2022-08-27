/*

Name: Shiva.K
Date: 26-08-2022
Description: Read and sort the given strings of maximum length of 20

Sample output: Enter the size: 3

               Enter the 3 names of length max 20 characters in each
               [0] -> Madurai
               [1] -> Hyderabad
               [2] -> Mumbai

               The sorted names are:
               Hyderabad
               Madurai
               Mumbai


*/



#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>

void sort_names(char **, int);
int my_strcmp(const char *, const char *);       // Declaring required functions
void my_strcpy(char *, const char *);

int main()
{
	int size, i, j;
	char (*names)[20];          // Declaring static columns to store names
	printf("Enter the size: ");
	scanf("%d", &size);

	names = malloc(size * sizeof(*names));     // Declaring dynamically allocated memory for rows

	printf("\nEnter the %d names of length max 20 characters in each\n", size);
	char *ptr[size];     // Declaring array of pointers

	  for (i = 0; i < size; i++)      // Getting strings one by one from the user
	  {
	     fflush(stdin) ;   //__fpurge(stdin);
	      printf("[%d] -> ", i);
		  scanf("%20[^\n]", names[i]);
		  ptr[i] = names[i];              // Storing the corresponding base address of the string at the array of pointers
	  }

	sort_names(ptr, size);          // Calling the function

    free(names);    // Freeing Dynamic memory of rows
    names = NULL;   // Making dangling pointer as NULL

  return 0;

}


void sort_names(char **ptr, int size)         // Function definition for sorting names
{
	int i, j, k;
	char temp[21];      // Temp variable to swap strings

	for (i = 0; i < (size - 1) ; i++)       // Sorting the strings by checking character by character
	{
		for (j = i + 1; j < size; j++)
		{
			if (my_strcmp(ptr[i], ptr[j]) > 0)      // Comparing the strings
                 {
                     my_strcpy(temp, ptr[j]);
                     my_strcpy(ptr[j], ptr[i]);     // Swapping the strings
                     my_strcpy(ptr[i], temp);
                 }
        }
    }


	printf("\nThe sorted names are:\n");

	for (i = 0; i < size; i++)              // Printing the final output
	{
		printf("%s\n", ptr[i]);
	}

}


int my_strcmp(const char *str1, const char *str2)      // Function definition for string compare
{
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }

  return (*str1 - *str2);     // Returning positive value if str1 > str2
                              // Returning zero if str1 = str2
                              // Returning negative value if str1 < str2
}


void my_strcpy(char *dest, const char *src)      // Function definition for string copy
{
    while(*dest++ = *src++);    // Copying character by character from source string(src) to destination string(dest)
    *dest = '\0';               // Placing NULL at the last element of destination string
}
