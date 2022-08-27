



#include <stdio.h>

int main()
{
    int row,col,range,inc=1;

    printf("Enter the value: ");
    scanf("%d", &range);

    for(row=1;row<=range;row++)
    {
        for(col=1;col<=row;col++)
        {
            printf("%d ",inc);

            inc=inc + 1;



        }

        printf("\n");
    }

    return 0;
}
