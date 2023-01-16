#include <stdint.h>

#ifndef FILE_DECODER_JPEG_H
#define FILE_DECODER_JPEG_H

#endif // FILE_DECODER_JPEG_H
typedef struct JHeader
{
    uint16_t SIO;
    uint16_t APP0;
    uint16_t Lenght;
    uint32_t ID;
    uint16_t VERSION;
    uint16_t Xdensity;
    uint16_t Ydensity;
    uint16_t XThumbnail;
    uint16_t YThumbnail;
} JHeader;

JHeader parseHeader(uint8_t *buffer);
uint32_t slice(int start, int end, uint8_t *buffer);