/*

Name: Shiva.K
Date: 24-08-2022
Description: Define a macro swap (t, x, y) that swaps 2 arguments of type t

Sample output: --> 1. Int
                   2. char
                   3. short
                   4. float
                   5. double
                   6. string
                   Enter you choice : 1
                   Enter the num1 : 25
                   Enter the num2 : 5
                   After Swapping :
                   num1 : 5
                   num2 : 25


              --> 1. Int
                  2. char
                  3. short
                  4. float
                  5. double
                  6. string
                  Enter you choice : 6
                  Enter the string1 : Hello
                  Enter the string2 : How
                  After Swapping :
                  string1 : How
                  string2 : Hello


*/



#include <stdio.h>
#include <stdio_ext.h>

// Defining a Macro which swaps two arguments of any datatypes

#define SWAP(t, x, y)        \
{                            \
    t temp = x;              \
    x = y;                   \
    y = temp;                \
}                            \


int main ()
{
    int choice, num1, num2;
    char char1, char2;
    short short1, short2;
    float float1, float2;                    // Declaring required variables
    double double1, double2;
    char string1[100], string2[100];
    char *ptr1 = string1;
    char *ptr2 = string2;
    printf("1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter you choice : ");     // Displaying the menu
    scanf("%d", &choice);

          switch (choice)
          {
              case 1:         // Swapping two integer datatypes

                  printf("Enter the num1 : ");
                  scanf("%d", &num1);
                  printf("Enter the num2 : ");
                  scanf("%d", &num2);

                  SWAP(int, num1, num2);          // Macro swap

                  printf("After Swapping :");
                  printf("\nnum1 : %d", num1);      // Displaying the final output
                  printf("\nnum2 : %d", num2);
                  break;

              case 2:         // Swapping two Character datatypes

                  __fpurge(stdin);
                  printf("Enter the char1 : ");
                  scanf("%c", &char1);
                  __fpurge(stdin);
                  printf("Enter the char2 : ");
                  scanf("%c", &char2);

                  SWAP(char, char1, char2);        // Macro swap

                  printf("After Swapping :");
                  printf("\nchar1 : %c", char1);   // Displaying the final output
                  printf("\nchar2 : %c", char2);
                  break;

              case 3:           // Swapping two short datatypes

                  printf("Enter the short1 : ");
                  scanf("%hd", &short1);
                  printf("Enter the short2 : ");
                  scanf("%hd", &short2);

                  SWAP(short, short1, short2);         // Macro swap

                  printf("After Swapping :");
                  printf("\nshort1 : %hd", short1);   // Displaying the final output
                  printf("\nshort2 : %hd", short2);
                  break;

              case 4:          // Swapping two float datatypes

                  printf("Enter the float1 : ");
                  scanf("%f", &float1);
                  printf("Enter the float2 : ");
                  scanf("%f", &float2);

                  SWAP(float, float1, float2);       // Macro swap

                  printf("After Swapping :");
                  printf("\nfloat1 : %f", float1);   // Displaying the final output
                  printf("\nfloat2 : %f", float2);
                  break;

              case 5:         // Swapping two double datatypes

                  printf("Enter the double1 : ");
                  scanf("%lf", &double1);
                  printf("Enter the double2 : ");
                  scanf("%lf", &double2);

                  SWAP(double, double1, double2);       // Macro swap

                  printf("After Swapping :");
                  printf("\ndouble1 : %lf", double1);    // Displaying the final output
                  printf("\ndouble2 : %lf", double2);
                  break;

              case 6:        // Swapping two strings

                  printf("Enter the string1 : ");
                  __fpurge(stdin);
                  scanf("%[^\n]", string1);
                  printf("Enter the string2 : ");
                  __fpurge(stdin);
                  scanf("%[^\n]", string2);


                  SWAP(char *, ptr1, ptr2);           // Macro swap

                  printf("After Swapping :");
                  printf("\nstring1 : %s", ptr1);      // Displaying the final output
                  printf("\nstring2 : %s", ptr2);
                  break;

         }

    return 0;

}

