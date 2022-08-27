




#include <stdio.h>

int main()
{
    int row,col,range,col_loop;

    printf("Enter the value: ");
    scanf("%d", &range);


     col_loop=range - 1;

    for(row=1;row<=range;row++)
    {
        col_loop=col_loop + 1;

        for(col=1;col<=col_loop;col++)
              {
                  if(row + col >= range + 1)
                  {

                    printf("* ");

                  }

                  else
                  {
                      printf("  ");
                  }


            }

              printf("\n");
    }



    return 0;
}
