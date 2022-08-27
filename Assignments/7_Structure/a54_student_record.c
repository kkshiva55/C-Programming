/*

Name: Shiva.K
Date: 27-08-2022
Description: Student Record using array of structures

Sample output: -->


Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Physics

----------Enter the student details-------------
Enter the student Roll no. : 1
Enter the student 1 name : Siemens
Enter Maths mark : 92
Enter Physics mark : 97

----------Enter the student details-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bosch
Enter Maths mark : 76
Enter Physics mark : 82


----Display Menu----

1. All student details
2. Particular student details

Enter your choice : 1


Roll No.      Name          Maths         Physics       Average       Grade


 1            Siemens        92            97            94.5           A
 2            Bosch          76            82            79             C

Do you want to continue to display(Y/n) : y


----Display Menu----

1. All student details
2. Particular student details

Enter your choice : 2


----Menu for Particular student----
1. Name.
2. Roll no.

Enter you choice : 1

Enter the name of the student : Bosch


Roll No.      Name          Maths         Physics       Average       Grade


2            Bosch          76            82            79             C

Do you want to continue to display(Y/n) : y


----Display Menu----

1. All student details
2. Particular student details

Enter your choice : 2


----Menu for Particular student----
1. Name.
2. Roll no.

Enter you choice : 2

Enter the Roll no. of the student : 1


Roll No.      Name          Maths         Physics       Average       Grade


1            Siemens        92            97            94.5           A

Do you want to continue to display(Y/n) : n


*/


#include <stdio.h>
#include <stdio_ext.h>

void my_strcpy(char *, const char *);             // Function declaration for string copy and string compare
int my_strcmp(const char *, const char *);


struct student        // Defining structure to store student information
{
    int id;
    char name[15];
    int marks[50];
    float average;
    char grade;
};


struct subject_name   // Defining structure to store subject names
{
    char sub[20];
};



int main()
{
    int std_no, sub_no, subjects, title, details, choice, menu, search, match_id;
    char option, match_str[20];
    float sum = 0;

    printf("Enter no.of students : ");     // Getting number of students from the user
    scanf("%d", &std_no);

    struct student std[std_no - 1];       // Declaring structure std
    printf("Enter no.of subjects : ");
    scanf("%d", &sub_no);                 // Getting number of subjects from the user


    struct subject_name sub_name[sub_no + 4];   // Declaring structure sub_name
    my_strcpy(sub_name[0].sub, "Roll No.");
    my_strcpy(sub_name[1].sub, "Name");         // Storing heading into the structure (sub_name)

        for (subjects = 2; subjects < (sub_no + 2); subjects++)
        {
            __fpurge(stdin);
            printf("Enter the name of subject %d : ", subjects - 1);    // Getting subject names one by one from the user
            scanf("%s", sub_name[subjects].sub);
        }

     my_strcpy(sub_name[subjects].sub, "Average");     // Storing heading into the structure
     my_strcpy(sub_name[++subjects].sub, "Grade");


     title = subjects;

     for (details = 0; details < std_no; details++)
     {
         printf("\n----------Enter the student details-------------\nEnter the student Roll no. : ");
         scanf("%d", &std[details].id);                              // Getting student Roll number from the user and storing it into the structure(id)
         printf("Enter the student %d name : ", details + 1);
         scanf("%s", std[details].name);                             // Getting student name from the user and storing it into the structure(name)
         __fpurge(stdin);

               for (subjects = 0; subjects < sub_no; subjects++)
               {
                 printf("Enter %s mark : ", sub_name[subjects + 2].sub);     // Getting subject marks one by one and storing it into the structure(marks)
                 scanf("%d", &std[details].marks[subjects]);
                 sum += std[details].marks[subjects];                        // Calculating sum of all subject marks
               }

               std[details].average = sum / sub_no;     // Computing average value and storing it into the structure(average)
               sum = 0;

                   if (std[details].average >= 90)            // Assigning grades according to the average value and storing it into the structure(grade)
                   {
                       std[details].grade = 'A';
                   }

                     else if ((std[details].average >= 80) && (std[details].average < 90))
                     {
                         std[details].grade = 'B';
                     }

                         else if ((std[details].average >= 70) && (std[details].average < 80))
                         {
                             std[details].grade = 'C';
                         }

                             else if ((std[details].average >= 60) && (std[details].average < 70))
                             {
                                 std[details].grade = 'D';
                             }

                                 else if ((std[details].average >= 50) && (std[details].average < 60))
                                 {
                                     std[details].grade = 'E';
                                 }

                                     else
                                     {
                                         std[details].grade = 'F';
                                     }

     }


     do                       // Displaying the Menu
     {
         printf("\n\n----Display Menu----\n\n1. All student details\n2. Particular student details\n\nEnter your choice : ");
         scanf("%d", &choice);

              switch (choice)
              {
                  case 1:        // Displaying all student details

                     printf("\n\n");

                       for (details = 0; details <= title; details++)
                       {
                           printf("%-14s", sub_name[details].sub);
                       }

                         printf("\n");

                           for (details = 0; details < std_no; details++)
                           {
                               printf("\n");
                               printf(" %-13d%-15s", std[details].id, std[details].name);
                               fflush(stdout);

                                 for (subjects = 0; subjects < sub_no; subjects++)
                                 {
                                     printf("%-14d", std[details].marks[subjects]);
                                 }

                                   printf("%-15g", std[details].average);
                                   printf("%c", std[details].grade);

                           }

                       break;

                  case 2:

                      printf("\n\n----Menu for Particular student----\n1. Name.\n2. Roll no.\n\nEnter you choice : ");
                      scanf("%d", &menu);

                           switch (menu)
                           {
                                 case 1:           // Displaying student details according to their name

                                     printf("\nEnter the name of the student : ");
                                     scanf("%s", match_str);

                                        for (search = 0; search < std_no; search++)
                                        {
                                            if ((my_strcmp(std[search].name, match_str)) == 0)     // Comparing student names with user entered name
                                            {
                                                printf("\n\n");

                                                  for (details = 0; details <= title; details++)    // Displaying the concern student details
                                                  {
                                                      printf("%-14s", sub_name[details].sub);
                                                  }

                                                    printf("\n\n");
                                                    printf("%-13d%-15s", std[search].id, std[search].name);
                                                    fflush(stdout);

                                                       for (subjects = 0; subjects < sub_no; subjects++)
                                                       {
                                                           printf("%-14d", std[search].marks[subjects]);
                                                       }

                                                         printf("%-15g", std[search].average);
                                                         printf("%c", std[search].grade);
                                             }


                                         }

                                         break;


                                 case 2:            // Displaying student details according to their Roll number

                                     printf("\nEnter the Roll no. of the student : ");
                                     scanf("%d", &match_id);

                                        for (search = 0; search < std_no; search++)
                                        {
                                            if (std[search].id == match_id)     // Checking user entered ID with student Roll number
                                            {
                                                printf("\n\n");

                                                    for (details = 0; details <= title; details++)    // Displaying student details when ID is matched
                                                    {
                                                        printf("%-14s", sub_name[details].sub);
                                                    }

                                                      printf("\n\n");
                                                      printf("%-13d%-15s", std[search].id, std[search].name);
                                                      fflush(stdout);

                                                        for (subjects = 0; subjects < sub_no; subjects++)
                                                        {
                                                            printf("%-14d", std[search].marks[subjects]);
                                                        }

                                                         printf("%-15g", std[search].average);
                                                         printf("%c", std[search].grade);
                                            }


                                        }

                                        break;

                                 default :
                                     printf("\nError : Invalid Option");
                            }

                           break;

                  default :
                      printf("\nError : Invalid Option");
              }

            __fpurge(stdin);
            printf("\n\nDo you want to continue to display(Y/n) : ");     // Displaying the Menu again
            scanf("%c", &option);

      } while ((option == 'y' || option == 'Y'));

  return 0;

}



void my_strcpy(char *dest, const char *src)      // Function definition for string copy
{
    while(*dest++ = *src++);    // Copying character by character from source string(src) to destination string(dest)
    *dest = '\0';               // Placing NULL at the last element of destination string
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


