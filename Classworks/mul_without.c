#include <stdio.h>

int main()
{
    int first,second,add,sum=0;

    printf("Enter the first number: ");
    scanf("%d", &first);
    printf("Enter the second number: ");
    scanf("%d", &second);

      for(add=1;add<=second;add++)
      {
          sum = sum + first;
      }

      printf("%d x %d= %d", first, second, sum);

      return 0;
}
