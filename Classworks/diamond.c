#include <stdio.h>

int main()
{
    int range,row,col,gap;

    printf("Enter the range: ");
    scanf("%d", &range);

      for(row=1;row<=range;row++)
      {
          for(gap=1;gap<=range-row;gap++)
          {
              printf("  ");

          }

              for(col=1;col<=(2*row) -1;col++)
              {
                  printf("* ");
              }

              printf("\n");
      }

      for(row=range-1;row>=1;row--)
      {
          for(gap=1;gap<=range-row;gap++)
          {
              printf("  ");

          }

              for(col=1;col<=(2*row) -1;col++)
              {
                  printf("* ");
              }

              printf("\n");
      }
return 0;
}
