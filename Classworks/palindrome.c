#include <stdio.h>

int main()
{
    int num,reverse=0,rem,given;

    printf("Enter the number: ");
    scanf("%d", &num);

    given=num;

    while(num > 0)
    {
        rem=num % 10;
        reverse=(reverse * 10) + rem;
        num=num / 10;
    }

       if(given == reverse)
       {
        printf("%d is palindrome", given);
       }
       else
       {
         printf("%d is not a palindrome", given);

       }

       return 0;
}
