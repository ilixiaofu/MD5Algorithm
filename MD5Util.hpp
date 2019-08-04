#ifndef MD5UTIL_HPP
#define MD5UTIL_HPP

/**
 *
 * 生成十六进制MD5摘要
 */
bool md5_digest(unsigned char* inputEncrypt, unsigned int iLen, unsigned char* outputDecrypt);

/**
 *
 * 十六进制MD5摘要转字符串
 */
bool MD5HexToStr(unsigned char *pByteInDecrypt, unsigned int iByteDecryptLen, char *pStrOutDecrypt, unsigned int iStrDecryptLen);
#endif //MD5UTIL_HPP

