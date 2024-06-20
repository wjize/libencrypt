#include "Encrypt.h"
#include <cstring>  // For strcpy

int gbase_aes_encrypt_test(const char* input, int input_len, char* output, const char* key, int key_len) {
    // 简单的模拟加密操作(copy模拟)
    strcpy(output, input);
    return input_len;
}

int gbase_aes_decrypt_test(const char* input, int input_len, char* output, const char* key, int key_len) {
    // 简单的模拟解密操作(copy模拟)
    strcpy(output, input);
    return input_len;
}

int gbase_aes_get_size_test(int input_len) {
    // 返回大小
    return input_len;
}
