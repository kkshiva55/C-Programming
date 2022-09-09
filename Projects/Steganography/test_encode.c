#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{

   //checking for the argc
   if (argc >= 3)
   {

    // Function call for check operation type
    if (check_operation_type(argv) == e_encode)
    {
        printf("Selected encoding .....\n");

        // Declare structure variable
        EncodeInfo encInfo;
        // Read and validate encode arguments
        if (read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("Read and validate encode arguments is a success\n");


            // Function call for encoding
            if (do_encoding(&encInfo) == e_success)
            {
                printf("Encoding has been successfully Completed\n");
            }
            else
            {
                printf("Error: Failed to encode\n");
            }
        }
        else
        {
            printf("Error: Failed to Read and Validate Encode Arguments\n");
        }
    }
    // Function call for check operation type
    else if (check_operation_type(argv) == e_decode)
    {
        printf("Selected decoding .....\n");

        // Declare structure variables
        DecodeInfo decInfo;
         if (read_and_validate_decode_args(argv, &decInfo) == d_success)
         {
            printf("INFO: Arguments has been read and validated Successfully\n");

                // Function call for do decoding
                if (do_decoding(&decInfo) == d_success)
                {
                    printf("INFO: ## Decoding Done Successfully ##\n");
                }
                else
                {
                    printf("Error: Failed to decode\n");
                }

          }
          else
          {
              printf("Error: Failed to Read and Validate decode arguments\n");
          }
     }
     else
     {
         printf("Error: Invalid option\nKindly pass for\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
     }
  }
  else
  {
      printf("Error: Invalid Operation Type\nUsage : \nEncoding : ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding : ./a.out -d stego.bmp decode.txt\n");
  }

 return 0;

}


/* Function definition for check operation type */
OperationType check_operation_type(char *argv[])
{
    if (strcmp(argv[1], "-e") == 0)
    {
        return e_encode;
    }
    if (strcmp(argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}
