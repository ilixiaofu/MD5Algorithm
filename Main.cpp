#include <string.h>
#include <stdio.h>
#include "MD5Util.hpp"

int main(){
    
    int i;
    unsigned char encrypt[] = "adcbef";

    unsigned char hexDecrypt[16] = {0x00};
    char strDecrypt[33] = {0x00};

    md5_digest(encrypt, (int)strlen((char *)encrypt), hexDecrypt);
    printf("msg:%s\n",encrypt);
    printf("hexDecrypt:");
    for (i = 0; i<16; i++){
        printf("%02x", hexDecrypt[i]);
    }
    MD5HexToStr(hexDecrypt, 16, strDecrypt, 32);
    printf("\nstrDecrypt:%s\n", strDecrypt);

    getchar();

    return 0;
}
