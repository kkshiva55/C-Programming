/*

Name: Shiva.K
Date: 19-08-2022
Description: Provide a menu to manipulate or display the value of variable of type t

Sample output: -->

                   Menu :

                   1.Add element
                   2.Remove element
                   3.Display element
                   4.Exit from the program

                   Choice ---> 1

                   Enter the type you have to insert:
                   1.int
                   2.char
                   3.float
                   4.short
                   5.double

                   Choice ---> 2
                   Enter the char: S

                   1.Add element
                   2.Remove element
                   3.Display element
                   4.Exit from the program

                   Choice ---> 1

                   Enter the type you have to insert:
                   1.int
                   2.char
                   3.float
                   4.short
                   5.double

                   Choice ---> 1
                   Enter the int: 25

                   1.Add element
                   2.Remove element
                   3.Display element
                   4.Exit from the program

                   Choice ---> 3

                   -------------------------
                   0 -> (char) S

                   4 -> (int) 25

                   -------------------------

                   1.Add element
                   2.Remove element
                   3.Display element
                   4.Exit from the program

                   Choice ---> 2
                   0 -> (char) S
                   4 -> (int) 25
                   Enter the index value to be deleted : 4
                   index 4 successfully deleted.

                   1.Add element
                   2.Remove element
                   3.Display element
                   4.Exit from the program

                   Choice ---> 4


*/


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int choice, choice1, index;
	void *ptr = malloc(8);       // Dynamically initializing 8 bytes of memory
	int char_flag1 = 0, char_flag2 = 0, int_flag = 0, float_flag = 0, double_flag = 0, short_flag = 0;
	printf("Menu :\n");

	do
	{
		 // Display the choices
		printf("\n1.Add element\n");
		printf("2.Remove element\n");
		printf("3.Display element\n");
		printf("4.Exit from the program\n");
		__fpurge(stdin);
		printf("\nChoice ---> ");     // Getting the choice from the user
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:     // Adding element into the memory

				printf("\nEnter the type you have to insert:\n");         // Displaying the datatype menu
				printf("1.int\n2.char\n3.float\n4.short\n5.double\n");
				printf("\nChoice ---> ");
				scanf("%d", &choice1);

				      switch (choice1)
				      {
					      case 1:      // Storing integer into the memory

                             if (int_flag == 0 && float_flag == 0 && double_flag == 0)
						     {
						         printf("Enter the int: ");
							     scanf("%d", (int *)(ptr + 4));
							     int_flag = 1;    // Making int flag as '1'
						     }

						     else
                                printf("\nInsufficient space\n");  // If memory is occupied already
						        break;

                           case 2:     // Storing Character into the memory

						      if (char_flag1 == 0 && double_flag == 0)
						      {
						          __fpurge(stdin);
							      printf("Enter the char: ");
                                  scanf("%c", (char *)ptr);
						 	      char_flag1 = 1;   // Making char flag as '1'
						      }

						      else if (char_flag2 == 0 && double_flag == 0)
						      {
						          __fpurge(stdin);
						          printf("Enter the char: ");
							      scanf("%c", (char *)(ptr + 1));
							      char_flag2 = 1;     // Making char flag as '1'
						      }

						      else
                                printf("\nInsufficient space\n");      // If memory is occupied already
						        break;

					      case 3:    // Storing float value into the memory

						      if (float_flag == 0 && int_flag == 0 && double_flag == 0)
						      {
						          printf("Enter the float: ");
				   			      scanf("%f", (float *)(ptr + 4));
							      float_flag = 1;        // Making float flag as '1'
						      }

						    else
                                printf("\nInsufficient space\n");        // If memory is occupied already
					    	    break;

					     case 4:   // Storing short value into the memory

						     if (double_flag == 0 && short_flag == 0)
						     {
						         printf("Enter the short: ");
							     scanf("%hd", (short *)(ptr + 2));
						    	 short_flag = 1;      // Making short flag as '1'
						     }

						    else
                                printf("\nInsufficient space\n");       // If memory is occupied already
						        break;

					     case 5:    // Storing double value into the memory

						     if (char_flag1 == 0 && char_flag2 == 0 && short_flag == 0 && int_flag == 0 && float_flag == 0 && double_flag ==0)
						     {
						         printf("Enter the double: ");
							     scanf("%lf", (double *)ptr);
							     double_flag = 1;        // Making double flag as '1'
						     }

						     else
                                printf("\nInsufficient space\n");        // If memory is occupied already
						break;

				    	  default:
				    	      printf("\nInvalid choice\n");     // If user has entered an invalid choice

			    	 }

				continue;
				break;


			case 3:      // Displaying the entered values

			    printf("\n-------------------------");

				if (char_flag1 == 1)
                {
                    printf("\n0 -> (char) %c\n", *(char *)ptr);
                }

				if (char_flag2 == 1)
                {
                    printf("\n1 -> (char) %c\n", *(char *)(ptr+1));
                }

				if (int_flag == 1)
                {
                    printf("\n4 -> (int) %d\n", *(int *)(ptr+4));
                }

				if (float_flag == 1)
                {
                    printf("\n4 -> (float) %f\n", *(float *)(ptr+4));
                }

				if (double_flag == 1)
                {
                    printf("\n0 -> (double) %lf\n", *(double *)ptr);
                }

			    if (short_flag == 1)
                {
                    printf("\n2 -> (short) %hd\n", *(short *)(ptr+2));
                }

                   printf("\n-------------------------");
                   printf("\n");

				continue;
				break;

			case 2:     // Removing the values from the memory

				if (char_flag1 == 1)
					printf("0 -> (char) %c\n", *(char *)ptr);

				if (char_flag2 == 1)
					printf("1 -> (char) %c\n", *(char *)(ptr+1));

				if (int_flag == 1)
					printf("4 -> (int) %d\n", *(int *)(ptr+4));

				if (float_flag == 1)
					printf("4 -> (float) %f\n", *(float *)(ptr+4));

				if (double_flag == 1)
					printf("0 -> (double) %lf\n", *(double *)ptr);

			    if (short_flag == 1)
					printf("2 -> (short) %hd\n", *(short *)(ptr+2));
				    printf("Enter the index value to be deleted : ");
			   	    scanf("%d", &index);   //Based on index position removing the element

				if (index == 0 || index == 1 || index == 2 || index == 4)
                {
                    if (index == 0 && char_flag1 == 1)
                    {
                        printf("index %d successfully deleted.", index);
					    char_flag1 = 0;    // Making char flag as '0' after removing from the memory
                    }
				    else if (index == 1)
			     	{
			     	    printf("index %d successfully deleted.", index);
					    char_flag2 = 0;     // Making char flag as '0' after removing from the memory
			     	}
				    else if (index == 4 && int_flag == 1)
				    {
				        printf("index %d successfully deleted.", index);
					    int_flag = 0;       // Making int flag as '0' after removing from the memory
				    }
				    else if (index == 4 && float_flag == 1)
				    {
				        printf("index %d successfully deleted.", index);
					    float_flag = 0;     // Making float flag as '0' after removing from the memory
				    }
				    else if (index == 2)
				    {
				        printf("index %d successfully deleted.", index);
					    short_flag = 0;     // Making float flag as '0' after removing from the memory
				    }
                    else if (index == 0 && double_flag == 1)
                    {
                        printf("index %d successfully deleted.", index);
					    double_flag = 0;     // Making double flag as '0' after removing from the memory
                    }
                    printf("\n");

				continue;
				break;
                }

		}

	} while (choice != 4);    // Displaying the menu until user enters option '4'

    free(ptr);    // Free the Dynamic memory
    ptr = NULL;   // Making dangling pointer as NULL

	return 0;

}
