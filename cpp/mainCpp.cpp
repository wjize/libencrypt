#include <iostream>
#include <dlfcn.h>
#include <cstring>  // For strlen

typedef int (*encrypt_func)(const char*, int, char*, const char*, int);
typedef int (*decrypt_func)(const char*, int, char*, const char*, int);
typedef int (*get_size_func)(int);

int main() {
    void* handle;
    encrypt_func my_aes_encrypt_test;
    decrypt_func my_aes_decrypt_test;
    get_size_func my_aes_get_size_test;

    handle = dlopen("./libencryptcpp.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot load dynamic library: " << dlerror() << std::endl;
        return 1;
    }

    my_aes_encrypt_test = (encrypt_func)dlsym(handle, "_ZN7Encrypt22gbase_aes_encrypt_testEPKciPcS1_i");
    if (!my_aes_encrypt_test) {
        std::cerr << "Cannot find symbol: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    my_aes_decrypt_test = (decrypt_func)dlsym(handle, "_ZN7Encrypt22gbase_aes_decrypt_testEPKciPcS1_i");
    if (!my_aes_decrypt_test) {
        std::cerr << "Cannot find symbol: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    my_aes_get_size_test = (get_size_func)dlsym(handle, "_ZN7Encrypt23gbase_aes_get_size_testEi");
    if (!my_aes_get_size_test) {
        std::cerr << "Cannot find symbol: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    const char* source = "Hello World";
    char dest[50];
    const char* key = "Key";
    int source_length = strlen(source);
    int key_length = strlen(key);

    int enc_length = my_aes_encrypt_test(source, source_length, dest, key, key_length);
    std::cout << "Encrypted: " << dest << " (Length: " << enc_length << ")" << std::endl;

    int dec_length = my_aes_decrypt_test(dest, enc_length, dest, key, key_length);
    std::cout << "Decrypted: " << dest << " (Length: " << dec_length << ")" << std::endl;

    int size = my_aes_get_size_test(source_length);
    std::cout << "Size: " << size << std::endl;

    dlclose(handle);
    return 0;
}
