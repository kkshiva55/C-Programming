


#include <stdio.h>

int main()
{
    int row,col,range;

    printf("Enter the value: ");
    scanf("%d", &range);

    for(row=1;row<=range;row++)
    {
        for(col=1;col<=range;col++)
        {

            if(col>=row)
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
