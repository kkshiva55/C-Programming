/*

Name: Shiva.K
Date: 05-07-2022
Description: Finding which day of the year

Sample output: --> Enter the value of 'n' : 4
                   Choose First Day :
                   1. Sunday
                   2. Monday
                   3. Tuesday
                   4. Wednesday
                   5. Thursday
                   6. Friday
                   7. Saturday
                   Enter the option to set the first day : 2
                   The day is Thursday

               --> Enter the value of 'n' : 4
                   Choose First Day :
                   1. Sunday
                   2. Monday
                   3. Tuesday
                   4. Wednesday
                   5. Thursday
                   6. Friday
                   7. Saturday
                   Enter the option to set the first day : 10
                   Error: Invalid input, first day should be > 0 and <= 7

               --> Enter the value of 'n' : 400
                   Error: Invalid Input, n value should be > 0 and <= 365


*/



#include <stdio.h>


int main ()
{

    int first_day, nth_day;

    printf("Enter the value of 'n' : ");       // Getting which day of the year

    scanf("%d", &nth_day);


    if((nth_day > 0) && (nth_day <= 365))       // Checking if the day is within 0 and 365
    {

        printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");

        printf("Enter the option to set the first day : ");         // Getting starting day of the year

        scanf("%d", &first_day);



                if((first_day > 0) && (first_day <= 7))        // Checking if starting day is within 0 and 7

                {

                    nth_day = (nth_day + (first_day - 2)) % 7;      // Computing which day in a week



                       switch (nth_day)       // According to the calculated value(nth_day), the day is printed
                       {

                           case 0:

                                  printf("The day is Sunday");

                                  break;


                           case 1:

                                  printf("The day is Monday");

                                  break;


                           case 2:

                                  printf("The day is Tuesday");

                                  break;


                           case 3:

                                  printf("The day is Wednesday");

                                  break;


                           case 4:

                                  printf("The day is Thursday");

                                  break;


                           case 5:

                                  printf("The day is Friday");

                                  break;


                           case 6:

                                  printf("The day is Saturday");

                                  break;

                       }

                }


               else       // If user has entered starting day less than '1' (or) greater than '7'
               {

                   printf("Error: Invalid input, first day should be > 0 and <= 7");

               }

    }


   else         // If user has entered day number less than '1' (or) greater than '365'
   {

       printf("Error: Invalid Input, n value should be > 0 and <= 365");

   }

   return 0;

}
