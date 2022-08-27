/*

Name: Shiva.K
Date: 03-07-2022
Description: Generating AP, GP and HP series

Sample output: --> Enter the First Number 'A': 5
                   Enter the Common Difference / Ratio 'R': 4
                   Enter the number of terms 'N': 5
                   AP = 5, 9, 13, 17, 21
                   GP = 5, 20, 80, 320, 1280
                   HP = 0.200000, 0.111111, 0.076923, 0.058824, 0.047619

               --> Enter the First Number 'A': 3
                   Enter the Common Difference / Ratio 'R': 4
                   Enter the number of terms 'N': -5
                   Invalid input

*/



#include <stdio.h>

int main()
{

    int first, common, terms, series, ap, gp;     // Declaring all required variables
    float hp, start;

    printf("Enter the First Number 'A': ");

    scanf("%d", &first);       // Storing the first term


    printf("Enter the Common Difference / Ratio 'R': ");

    scanf("%d", &common);      // Storing the common difference (AP) or common ratio (GP)


    printf("Enter the number of terms 'N': ");

    scanf("%d", &terms);      // Storing the number of terms



    if((first < 0) || (common < 0) || (terms < 0))     // True if any one of the three inputs is negative
    {

        printf("Invalid input");

    }

    else        // User has entered valid inputs
    {

          printf("AP = %d", first);     // Printing the first term of AP
          ap = first;


              for(series = 1; series < terms; series++)     // Loop will run upto number of terms
              {

                 ap = ap + common;      // Adding by common difference

                 printf(", %d", ap);    // Printing AP series values separated by commas

              }


          printf("\nGP = %d", first);    // Printing the first term of GP
          gp = first;


             for(series = 1; series < terms; series++)    // Loop will run upto number of terms
             {

                 gp = gp * common;      // Multiplying by common ratio

                 printf(", %d", gp);    // Printing GP series values separated by commas

             }



          start = (float) 1 / first;     // Storing the first term of HP

          printf("\nHP = %f", start);
          ap = first;


            for(series = 1; series < terms; series++)    // Loop will run upto number of terms
            {

                 ap = ap + common;       // Adding by common difference

                 hp = (float) 1 / ap;    // Computing HP series


                 printf(", %f", hp);    // Printing HP series separated by commas

            }
    }

   return 0;

}
