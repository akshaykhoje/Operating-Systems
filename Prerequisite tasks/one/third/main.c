#include <stdio.h>
#include <stdlib.h>
#include <byteswap.h>
#include <stdint.h>
#include <stdint.h>
#include "jpeg.h"

enum types
{
    PDF,
    JPEG,
    PNG,
    GIF,
    INVALID
};

typedef enum types format;

format checkFormat(FILE *fd, const uint8_t buffer[])
{
    if (fd == NULL)
    {
        printf("Invalid file format");
    }
    switch (buffer[0])
    {
    case 0x25:
        printf(" PDF \n");
        return PDF;
    case 0x89:
        printf(" PNG \n");
        return PNG;
    case 0x47:
        printf(" GIF \n");
        return GIF;
    case 0xFF:
        printf(" JPEG \n");
        return JPEG;
    default:
        return INVALID;
    }
}

int main(int argc, char *argv[])
{
    FILE *fd;
    long fdSize;
    uint8_t *buffer;

    printf("Enter file path:");

    fd = fopen(argv[1], "rb");
    if (fd == NULL)
    {
        perror("Unable to open the file");
        exit(EXIT_FAILURE);
    }
    fseek(fd, 0L, SEEK_END);
    fdSize = ftell(fd);

    /* reset the file position indicator to the beginning of the file */
    fseek(fd, 0L, SEEK_SET);

    buffer = (uint8_t *)calloc((size_t)fdSize, sizeof(uint8_t));
    /* memory error */
    if (buffer == NULL)
        return 1;

    /* copy all the text into the buffer */
    fread(buffer, sizeof(uint8_t), (size_t)fdSize, fd);
    fclose(fd);
    /* fm for later use*/
    format fm = checkFormat(fd, (const uint8_t *)buffer);
    parseHeader(buffer);
    free(buffer);
    printf("\n__WORDSIZE : %d\n", __WORDSIZE);
    return 0;
}