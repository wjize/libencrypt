# libencrypt

## C

```c
// 不使用-llib链接动态库，让main.cpp可以调用动态库中接口的使用方法
// C++ 编译器在编译类的方法时会进行名称修饰（name mangling）,所以通过使用 extern "C" 来避免名称修饰。
// 修改代码如c目录中所示
cd build
// 1.生成动态库
g++ -shared -fPIC -o libencrypt.so ../c/Encrypt.cpp
// 2.编译main.cpp 
g++ -o main ../c/main.cpp -ldl
// 3.运行main ./main
./main
// 4.结果
Encrypted: Hello World (Length: 11)
Decrypted: Hello World (Length: 11)
Size: 11
```

## C++

```c++
// 若不使用 extern "C" 来避免名称修饰
// 修改代码如cpp目录中所示
cd build
// 1.生成动态库
g++ -shared -fPIC -o libencryptcpp.so ../cpp/EncryptCpp.cpp
// 2.使用命令查看libencryptcpp.so中的方法名称 nm libencryptcpp.so
nm libencryptcpp.so
...
00000000000007ba T _ZN7Encrypt22gbase_aes_decrypt_testEPKciPcS1_i
0000000000000786 T _ZN7Encrypt22gbase_aes_encrypt_testEPKciPcS1_i
00000000000007ee T _ZN7Encrypt23gbase_aes_get_size_testEi
...
// 3.在mainCpp.cpp按输出中的内容修改函数名
my_aes_encrypt_test = (encrypt_func)dlsym(handle, "_ZN7Encrypt22gbase_aes_encrypt_testEPKciPcS1_i");
...
my_aes_decrypt_test = (decrypt_func)dlsym(handle, "_ZN7Encrypt22gbase_aes_decrypt_testEPKciPcS1_i");
...
my_aes_get_size_test = (get_size_func)dlsym(handle, "_ZN7Encrypt23gbase_aes_get_size_testEi");
// 4.编译mainCpp.cpp
g++ -o main ../cpp/mainCpp.cpp -ldl
// 5.运行mainCpp ./mainCpp
./main
// 6.结果
Encrypted: Hello World (Length: 11)
Decrypted: Hello World (Length: 11)
Size: 11
```
