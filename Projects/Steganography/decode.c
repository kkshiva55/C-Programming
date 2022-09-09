#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
#include <stdlib.h>

// Function to read and validate arguments
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if (argv[2] != NULL && strcmp(strstr(argv[2], "."), ".bmp") == 0)
    {
        decInfo->d_src_image_fname = argv[2];   // Assign Encoded image
    }
    else
    {
        return d_failure;
    }
    if (argv[3] != NULL)
    {
        decInfo->d_secret_fname = argv[3];    // If user mentions output file name
    }
    else
    {
        decInfo->d_secret_fname = "decoded.txt";  // Default output file name
    }
    return d_success;
}

// Function to open files for decoding
Status open_files_dec(DecodeInfo *decInfo)
{
    //Stego Image file
    decInfo->fptr_d_src_image = fopen(decInfo->d_src_image_fname, "r");

    //Do Error handling
    if (decInfo->fptr_d_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_src_image_fname);
        return d_failure;
    }
    //Dest file
    decInfo->fptr_d_secret = fopen(decInfo->d_secret_fname, "w");

    //Do Error handling
    if (decInfo->fptr_d_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_secret_fname);
        return d_failure;
    }

    // If no failure then return d_success
    return d_success;
}

// Function to decode magic string
Status decode_magic_string(DecodeInfo *decInfo)
{
    fseek(decInfo->fptr_d_src_image, 54, SEEK_SET);    // Moving file pointer where magic string is encoded
    int i = strlen(MAGIC_STRING);

    decInfo->magic_data = malloc(strlen(MAGIC_STRING) + 1);
    decode_data_from_image(strlen(MAGIC_STRING), decInfo->fptr_d_src_image, decInfo);

    decInfo->magic_data[i] = '\0';

    if (strcmp(decInfo->magic_data, MAGIC_STRING) == 0)  // Comparing magic string
    {
        free(decInfo->magic_data);     // Freeing the dynamic memory
        decInfo->magic_data = NULL;    // Assign NULL for dangling pointer
        return d_success;
    }
    else
    {
        free(decInfo->magic_data);
        decInfo->magic_data = NULL;
        return d_failure;
    }

}

// Function to decode data from image
Status decode_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo)
{
    int i;
    char str[8];
    for (i = 0; i < size; i++)
    {
        fread(str, 8, sizeof(char), fptr_d_src_image);
        decode_byte_from_lsb(&decInfo->magic_data[i], str);
    }
    return d_success;
}

// Function to decode a byte from LSB
Status decode_byte_from_lsb(char *data, char *image_buffer)
{
    unsigned char ch = 0;
    for (int i = 0; i < 8; i++)
    {
        ch = ((image_buffer[i] & 0x01) << (7 - i)) | ch;
    }
     *data = ch;
}

// Function to decode file extension size
Status decode_file_extn_size(int size, FILE *fptr_d_src_image)
{
    char str[32];
    int length;

    fread(str, 32, sizeof(char), fptr_d_src_image);
    decode_size_from_lsb(str, &length);

    if (length == size)
    {
        return d_success;
    }
    else
    {
        return d_failure;
    }
}

// Function to decode size from LSB
Status decode_size_from_lsb(char *buffer, int *size)
{
    unsigned int num = 0;
    for (int i = 0; i < 32; i++)
    {
        num = ((buffer[i] & 0x01) << (31 - i)) | num;
    }
    *size = num;
}

// Function to decode secret file extension
Status decode_secret_file_extn(char *file_ext, DecodeInfo *decInfo)
{
    file_ext = ".txt";
    int i = strlen(file_ext);
    decInfo->d_extn_secret_file = malloc(i + 1);
    decode_extension_data_from_image(strlen(file_ext), decInfo->fptr_d_src_image, decInfo);

    decInfo->d_extn_secret_file[i] = '\0';

    if (strcmp(decInfo->d_extn_secret_file, file_ext) == 0)
    {
        free(decInfo->d_extn_secret_file);
        decInfo->d_extn_secret_file = NULL;
        return d_success;
    }
    else
    {
        free(decInfo->d_extn_secret_file);    // Freeing the Dynamic memory
        decInfo->d_extn_secret_file = NULL;   // Assign NULL for dangling pointer
        return d_failure;
    }
}

// Function to decode extension data from image
Status decode_extension_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo)
{
    for (int i = 0; i < size; i++)
    {
        fread(decInfo->d_src_image_fname, 8, 1, fptr_d_src_image);
        decode_byte_from_lsb(&decInfo->d_extn_secret_file[i], decInfo->d_src_image_fname);
    }
    return d_success;
}

// Function to decode secret file size
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), decInfo->fptr_d_src_image);
    decode_size_from_lsb(str, &file_size);
    decInfo->size_secret_file = file_size;
    return d_success;
}

// Function to decode secret file data
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char ch;
    for (int i = 0; i < decInfo->size_secret_file; i++)
    {
        fread (decInfo->d_src_image_fname, 8, sizeof(char), decInfo->fptr_d_src_image);
        decode_byte_from_lsb(&ch, decInfo->d_src_image_fname);
        fputc(ch, decInfo->fptr_d_secret);
    }
    return d_success;
}

// Function for decoding
Status do_decoding(DecodeInfo *decInfo)
{
     printf("INFO: ## Decoding Procedure Started ##\n");
     printf("INFO: Opening required files\n");
    if (open_files_dec(decInfo) == d_success)
    {
        printf("INFO: Opened stegged file\n");
        printf("INFO: Decoding Magic String Signature\n");
        if (decode_magic_string(decInfo) == d_success)
        {
            printf("INFO: Done\n");
            printf("INFO: Decoding Output File Extension\n");
            if (decode_file_extn_size(strlen(".txt"), decInfo->fptr_d_src_image) == d_success)
            {
                printf("INFO: Done\n");
                printf("INFO: Output File has been Created Successfully\n");
                if (decode_secret_file_extn(decInfo->d_extn_secret_file, decInfo) == d_success)
                {
                    printf("INFO: Decoded Secret File Extension Successfully\n");
                    if (decode_secret_file_size(decInfo->size_secret_file, decInfo) == d_success)
                    {
                        printf("INFO: Decoded Secret File Size Successfully\n");
                        if (decode_secret_file_data(decInfo) == d_success)
                        {
                            printf("INFO: Decoded Secret File Data Successfully\n");
                        }
                        else
                        {
                            printf("Error: Failed to Decode secret file data\n");
                        }
                    }
                    else
                    {
                        printf("Error: Failed to Decode secret file size\n");
                        return d_failure;
                    }
                }
                else
                {
                    printf("Error: Failed to Decode secret file extension\n");
                    return d_failure;
                }
            }
            else
            {
                printf("Error: Failed to Decode file extension size\n");
                return d_failure;
            }
        }
        else
        {
            printf("Error: Failed to Decode magic string\n");
            return d_failure;
        }
    }
    else
    {
        printf("Error: Failed to open files\n");
        return d_failure;
    }
    return d_success;
}
