/*

Name: Shiva.K
Date: 26-08-2022
Description: Product of two given matrices

Sample output: --> Enter number of rows : 2
                   Enter number of columns : 3
                   Enter values for 2 x 3 matrix :
                   1 2 3
                   3 2 1
                   Enter number of rows : 3
                   Enter number of columns : 2
                   Enter values for 3 x 2 matrix :
                   1 2
                   3 4
                   1 1
                   Product of two matrix :
                   10      13

                   10      15


              --> Enter number of rows : 2
                  Enter number of columns : 2
                  Enter values for 2 x 2 matrix :
                  1 2
                  2 1
                  Enter number of rows : 1
                  Enter number of columns : 2
                  Matrix multiplication is not possible


*/


#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **, int, int);     // Function declaration

int main()
{
    int **mat_a, **mat_b, **result;
    int row_a, col_a, row_b, col_b, row_r, col_r, i, j;

    printf("Enter number of rows : ");        // Getting matrix A row
	scanf("%d", &row_a);
    printf("Enter number of columns : ");      // Getting matrix A column
	scanf("%d", &col_a);

	mat_a = malloc(row_a * sizeof(int *));     // Dynamic memory allocation of row of matrix A

	   for (i = 0; i < row_a; i++)
	   {
	       mat_a[i] = malloc(col_a * sizeof(int));     // Dynamic memory allocation of column of matrix A
       }

	printf("Enter values for %d x %d matrix : \n", row_a, col_a);

	   for (i = 0; i < row_a; i++)
	   {
	       for (j = 0; j < col_a; j++)
		   {
		       scanf("%d", &mat_a[i][j]);     // Reading matrix A elements
		   }
	   }

    printf("Enter number of rows : ");     // Getting matrix B row
	scanf("%d", &row_b);
    printf("Enter number of columns : ");    // Getting matrix B column
	scanf("%d", &col_b);

	mat_b = malloc(row_b * sizeof(int *));    // Dynamic memory allocation of row for matrix B

	   for (i = 0; i < row_b; i++)
	   {
	       mat_b[i] = malloc(col_b * sizeof(int));   // Dynamic memory allocation of column for matrix B
	   }


	      if (col_a == row_b)     // Matrix multiplication is only possible when column of Matrix A and Row of Matrix B are same
	      {
	          row_r = row_a;     // Row and column values for resultant Matrix
		      col_r = col_b;

	           printf("Enter values for %d x %d matrix : \n", row_b, col_b);

	            for (i = 0; i < row_b; i++)
	            {
	                for (j = 0; j < col_b; j++)
		            {
		                scanf("%d", &mat_b[i][j]);    // Reading elements for matrix B
		            }
	            }

                result = malloc(row_r * sizeof(int *));     // Dynamically allocating memory for resultant matrix row

	            for (i = 0; i < row_r; i++)
	            {
	                result[i] = malloc(col_r * sizeof(int));    // Dynamically allocating memory for resultant matrix column
	            }

	    	  matrix_mul(mat_a, row_a, col_a, mat_b, row_b, col_b, result, row_r, col_r);    // Calling the function

	  	      for (i = 0; i < row_r; i++)
                free(result[i]);           // Freeing the DMA for columns of Resultant matrix

            free(result);                  // Freeing the DMA for rows of Resultant matrix
	      }

	      else
          {
              printf("Matrix multiplication is not possible\n");      // If user has entered invalid row and column values
          }


    for (i = 0; i < row_a; i++)
        free(mat_a[i]);              // Freeing the DMA for columns of Matrix A

    for (i = 0; i < row_b; i++)
        free(mat_b[i]);              // Freeing the DMA for columns of Matrix B

    free(mat_a);
	free(mat_b);         // Freeing DMA for rows of Matrix A and Matrix B

	mat_a = NULL;
	mat_b = NULL;      // Making dangling pointers as NULL
	result = NULL;

  return 0;

}


int matrix_mul(int **mat_a, int row_a, int col_a, int **mat_b, int row_b, int col_b, int **result, int row_r, int col_r)    // Function definition
{
	int i, j, k, sum = 0;

	for (i = 0; i < row_a; i++)
    {
        for (j = 0; j < col_b; j++)
        {
            for (k = 0; k < col_a; k++)
            {
                sum = sum + (mat_a[i][k] * mat_b[k][j]);       // Performing matrix multiplication
            }

       result[i][j] = sum;       // Storing the output value at the resultant matrix
       sum = 0;

        }
    }

    printf("Product of two matrix :");
    printf("\n");

        for (i = 0; i < row_r; i++)         // Printing the final output
        {
            for(j = 0; j < col_r; j++)
            {
                printf("%d      ", result[i][j]);
            }
            printf("\n\n");
        }

}

