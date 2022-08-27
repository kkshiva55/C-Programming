/*

Name: Shiva.K
Date: 25-08-2022
Description: Define a macro SIZEOF(x), without using sizeof operator

Sample output: --> Size of int : 4 bytes
                   Size of char : 1 byte
                   Size of float : 4 bytes
                   Size of double : 8 bytes
                   Size of unsigned int : 4 bytes
                   Size of long int : 4 bytes

                   ----

                   ----

                   ----


*/


#include <stdio.h>

#define SIZEOF(x) (char *)(&x + 1) - (char *)(&x)

int main()
{
    int i = 5;
    char ch = 'D';
    float flo = 25.5;
    double doub = 5.25;
    unsigned int unint = 255;
    long int lint = 20;
    short int sint = 5;
    long long int llint = 12;
    long double ldoub = 205.5;

    printf("Size of int : %lu bytes", SIZEOF(i));
    printf("\nSize of char : %lu byte", SIZEOF(ch));
    printf("\nSize of float : %lu bytes", SIZEOF(flo));
    printf("\nSize of double : %lu bytes", SIZEOF(doub));
    printf("\nSize of unsigned int : %lu bytes", SIZEOF(unint));
    printf("\nSize of long int : %lu bytes", SIZEOF(lint));
    printf("\nSize of short : %lu bytes", SIZEOF(sint));
    printf("\nSize of long long int : %lu bytes", SIZEOF(llint));
    printf("\nSize of long double : %lu bytes", SIZEOF(ldoub));


    printf("\n\n----");
    printf("\n\n----");
    printf("\n\n----");

}
