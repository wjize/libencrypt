#include "EncryptCpp.h"
#include <cstring>  // For strcpy

int Encrypt::gbase_aes_encrypt_test(const char* input, int input_len, char* output, const char* key, int key_len) {
    // Example implementation: just copy input to output
    strcpy(output, input);
    return input_len;
}

int Encrypt::gbase_aes_decrypt_test(const char* input, int input_len, char* output, const char* key, int key_len) {
    // Example implementation: just copy input to output
    strcpy(output, input);
    return input_len;
}

int Encrypt::gbase_aes_get_size_test(int input_len) {
    // Example implementation: return input length
    return input_len;
}

