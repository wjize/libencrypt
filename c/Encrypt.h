#ifndef ENCRYPT_H
#define ENCRYPT_H

/**
要在动态库中导出类的静态方法，并确保在主程序中正确找到这些方法，需要特别注意符号的名称和导出方式。
C++ 编译器在编译类的方法时会进行名称修饰（name mangling），这可能导致动态链接失败。
所以通过使用 extern "C" 来避免名称修饰。
*/

#ifdef __cplusplus
extern "C" {
#endif

int gbase_aes_encrypt_test(const char* input, int input_len, char* output, const char* key, int key_len);
int gbase_aes_decrypt_test(const char* input, int input_len, char* output, const char* key, int key_len);
int gbase_aes_get_size_test(int input_len);

#ifdef __cplusplus
}
#endif

#endif // ENCRYPT_H
