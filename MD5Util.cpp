#include "MD5Util.hpp"
#include "Md5.hpp"

// 十六进制数转为ASCII值
inline char HexNumToChar(unsigned int num) {
    if(num >= 0) {
        if(num <= 9) {
            return 48 + num;
        } else if (num <= 15) {
            return 87 + num;
        } else {
            return 0x00;
        }
    } else {
        return 0x00;
    }
}

// 十六进制MD5摘要转字符串
static bool _MD5HexToStr(unsigned char *pByteInDecrypt, unsigned int iByteDecryptLen, char *pStrOutDecrypt, unsigned int iStrDecryptLen)
{
    if (pByteInDecrypt && iByteDecryptLen == 0x10 && pStrOutDecrypt && iStrDecryptLen == 0x20)
    {
        for (unsigned int i = 0; i < iByteDecryptLen; i++)
        {
            unsigned int hiByte = (pByteInDecrypt[i] & 0xF0) >> 4;
            pStrOutDecrypt[i * 2] = HexNumToChar(hiByte);          
            unsigned int loByte = pByteInDecrypt[i] & 0x0F;
            pStrOutDecrypt[i * 2 + 1] = HexNumToChar(loByte);
        }
        return true;
    }
    return false;
}

bool MD5HexToStr(unsigned char *pByteInDecrypt, unsigned int iByteDecryptLen, char *pStrOutDecrypt, unsigned int iStrDecryptLen)
{
    return _MD5HexToStr(pByteInDecrypt, iByteDecryptLen, pStrOutDecrypt, iStrDecryptLen);
}

// 生成十六进制MD5摘要
static bool _md5_digest(unsigned char* inputEncrypt, unsigned int iLen, unsigned char* outputDecrypt)
{
    if (inputEncrypt && iLen > 0)
    {
        MD5_CTX md5;
        MD5Init(&md5);
        MD5Update(&md5, inputEncrypt, iLen);
        MD5Final(&md5, outputDecrypt);
        return true;
    }
    return false;
}

bool md5_digest(unsigned char* inputEncrypt, unsigned int iLen, unsigned char* outputDecrypt)
{
    return _md5_digest(inputEncrypt, iLen, outputDecrypt);
}