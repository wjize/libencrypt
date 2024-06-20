#ifndef ENCRYPT_H
#define ENCRYPT_H

class Encrypt {
public:
    static int gbase_aes_encrypt_test(const char* input, int input_len, char* output, const char* key, int key_len);
    static int gbase_aes_decrypt_test(const char* input, int input_len, char* output, const char* key, int key_len);
    static int gbase_aes_get_size_test(int input_len);
};

#endif // ENCRYPT_H

