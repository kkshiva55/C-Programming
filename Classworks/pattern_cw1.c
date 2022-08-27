

#include <stdio.h>

int main()
{
    int row,col,range;

    printf("Enter the value: ");
    scanf("%d", &range);

    for(row=range;row>=1;row--)
    {
        for(col=1;col<=row;col++)
        {
          printf("* ");

        }

        printf("\n");
    }

    return 0;
}
