
#include <stdio.h>

int main()
{
    int power,limit,base,value=1;

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("\nEnter the limit: ");
    scanf("%d", &limit);


    for(power=1; power<=limit; power++)
    {
        value=base * value;
        printf("%d^%d= %d\n",base, power,value);
    }
    return 0;
}
