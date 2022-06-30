/*
    Day 6 of C++
    - simple text cipher
*/

#include <iostream>
#include <string>

std::string in;
int off;

char cipher_func(char in, int off)
{
    char r = (char)((in + off) % 254);
    return r > 0 ? r : -r;
}

int main()
{
    std::cout << "Please input a phrase to encrypt!" << std::endl;
    getline(std::cin, in);

    std::cout << "Please input an offset for the Caesar Cipher: " << std::endl;
    std::cin >> off;

    for (int i = 0; i < in.size(); i++)
        in[i] = cipher_func(in[i], off);

    std::cout << in << std::endl;

    // decrypt
    for (int i = 0; i < in.size(); i++)
        in[i] = cipher_func(in[i], -off);
    std::cout << "Decrypted: " << in << std::endl;

    return 0;
}
