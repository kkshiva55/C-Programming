
#include <stdio.h>

int main()
{
    int row,col,value;

    printf("Enter the value: ");
    scanf("%d", &value);

    for(row=1;row<=value;row++)
    {
        for(col=1;col<=row;col++)
        {
            printf("* ");
        }

        printf("\n");

    }
}
