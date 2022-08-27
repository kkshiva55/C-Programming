/*

Name: Shiva.K
Date: 30-07-2022
Description: Counting number of characters, words and lines

Sample output: --> Hi   Hello
                   How  are you
                   Character count : 24
                   Line count : 2
                   Word count : 5

               --> (If User pressed the "ENTER" key 3 times)



                   Character count : 3
                   Line count : 3
                   Word count : 0


*/



#include<stdio.h>

int main()
{
    char ch, pre = '\0';
    int chars = 0, lines = 0, words = 0;       /* Declaring required variables */


       while (ch != EOF)       /* Reading the input until user press CTRL + D */
       {
           ch = getchar();     /* Reading a character */
           chars++;            /* Incrementing character */

                if(ch == '\n')     /* If there is a new line, increment lines */
                {
                    lines++;
                }


                if(((ch == ' ') && ((pre != ' ') && (pre != '\n') && (pre != '\t'))) || ((ch == '\n') && ((pre != '\n') && (pre != ' ') && (pre != '\t')))|| ((ch == '\t') && ((pre != '\t') && (pre != ' ') && (pre != '\n'))))
                {
                                                /* If present character is a space, then previous character should not contain space, newline and tab */
                    if (pre != '\0')            /* If present character is a new line, then previous character should not contain newline, space and tab */
                    {                           /* If present character is a tab, then previous character should not contain tab, newline and space */
                        words++;                /* Until user enters a character apart from next line */
                    }                           /* "Words" is incremented only if all the above four conditions are true */

                }

          pre = ch;
        }

    printf("Character count : %d", --chars);    /* Printing the count of characters, lines and words */
    printf("\nLine count : %d", lines);
    printf("\nWord count : %d", words);

    return 0;

}
