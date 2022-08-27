#include <stdio.h>

int main()
{
    int power,limit,value=1;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    for(power=1; power<=limit; power++)
    {
        value=2 * value;
        printf("2^%d= %d\n", power,value);
    }
    return 0;
}


