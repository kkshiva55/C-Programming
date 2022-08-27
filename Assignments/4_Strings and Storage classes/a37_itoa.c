/*

Name: Shiva.K
Date: 02-08-2022
Description: Implementation of "ITOA" function

Sample output: --> Enter the number:+252
                   Integer to string is 252

               --> Enter the number:-525
                   Integer to string is -525

               --> Enter the number:2505sD
                   Integer to string is 2505

               --> Enter the number:sh255
                   Integer to string is 0


*/



#include <stdio.h>

int itoa(int num, char str[]);       // Function declaration

int main()
{
    int num, inputs;
    char str[10];

    printf("Enter the number:");       // Getting integer input from the user
    inputs = scanf("%d", &num);

       if (inputs != 1)     // True if no input has been read
       {
           num = 0;
       }

   itoa(num, str);         // Calling the function

   printf("Integer to string is %s", str);      // Printing the final output
}



int itoa(int num, char str[])        // Function definition
{
    int len_str, index = 0, temp, neg = num, digit;


      if (num == 0)           // When user enters a non-integer value as the first element
      {
          str[index++] = '0';       // Zero is printed
          str[index] = '\0';
      }

      else
      {
          num = (num < 0) ? -num : num;          // If user enters a negative value, change it as positive

             for (index = 0; num != 0; index++)
             {
                 digit = (num % 10) + '0';

                    if ((digit >= '0') && (digit <= '9'))       // True if digits are integer in ASCII
                    {
                        str[index] = digit;         // Storing digits one by one
                        num = num / 10;
                    }


             }


              if (neg < 0)          // True if user has entered a negative value
              {
                  str[index++] = '-';
              }

            str[index] = '\0';        // Storing last element as NULL

              for (len_str = 0; str[len_str] != '\0'; len_str++);       // Calculating the string length


                    for (index = 0; index < len_str / 2; index++)           // Swapping the characters from last to first (String reversal)
                    {
                        temp = str[index];
                        str[index] = str[len_str - index - 1];
                        str[len_str - index - 1] = temp;
                    }

    }

}

