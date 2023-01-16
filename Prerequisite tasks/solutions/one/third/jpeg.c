#include <stdio.h>
#include <memory.h>
#include <stdint.h>
#include <byteswap.h>
#include "jpeg.h"
 
JHeader header;
 
uint32_t slice(int start, int end, uint8_t *buffer){
    uint32_t a;
    unsigned int i = 0;
    uint8_t sl[16];
 
while(start <= end){
      sl[i] = buffer[start];
      start++;
      i++;
}
   memcpy(&a, sl, sizeof(unsigned int));
   return a;
}
 
JHeader parseHeader(uint8_t *buffer) {
 header.SIO = bswap_16(slice(0,2, buffer));
  header.APP0 = bswap_16(slice(2,3, buffer));
  header.Lenght = bswap_16(slice(4,5, buffer));
  header.ID = bswap_32(slice(6,9, buffer));
  header.VERSION = bswap_16(slice(11,13, buffer));
  header.Xdensity = bswap_16(slice(14,15, buffer));
  header.Ydensity = bswap_16(slice(16,17, buffer));
  header.XThumbnail = buffer[18];
  header.YThumbnail = buffer[19];
  printf("start of image %x\n", header.SIO);
  printf("APP0 marker %x\n", header.APP0);
  printf("Length %x\n", header.Lenght);
  printf("Identifier %x\n", header.ID);
  printf("Version %x\n", header.VERSION);
  printf("X density %x\n", header.Xdensity);
  printf("Y density %x\n", header.Ydensity);
  printf("X thumbnail %x\n", header.XThumbnail);
  printf("Y thumbnail %x\n", header.YThumbnail);
 
  return header;
}