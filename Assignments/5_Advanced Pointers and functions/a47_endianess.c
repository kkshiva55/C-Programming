/*

Name: Shiva.K
Date: 10-08-2022
Description: Convert Little Endian data to Big Endian data

Sample output: --> Enter the size: 2
                   Enter any number in Hexadecimal: cdab
                   After conversion abcd


*/


#include <stdio.h>

int main()
{
    int size;
    unsigned hex;

    printf("Enter the size: ");        // Getting data size from the user
    scanf("%d", &size);

    printf("Enter any number in Hexadecimal: ");       // Getting Hexadecimal number from the user
    scanf("%x", &hex);



    if (size == 2)           // User has entered 2 bytes data
    {
        unsigned byte0, byte1, result;
        char *ptr = &hex;

        byte0 = (0xFF) & (*ptr);
        byte1 = (0xFF) & (hex >> 8);         // Swapping the nibble
        result = (byte0 << 8) | (byte1);

        printf("After conversion %x", result);

    }

    else if (size == 4)       // User has entered 4 bytes data
    {
        unsigned int result, byte0, byte1, byte2, byte3;
        char *ptr = &hex;

          byte0 = ((0xFF) & (*ptr)) << 24;
          byte1 = ((hex & 0x0000FF00) >> 8) << 16;
          byte2 = ((hex & 0x00FF0000) >> 16) << 8;         // Swapping the nibbles from right to left
          byte3 = (hex & 0xFF000000) >> 24;

          result = (byte0 | byte1 | byte2 | byte3);

          printf("After conversion %x", result);

    }

}
