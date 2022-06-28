#include <iostream>

int main()
{
    int num = 100;
    long big_num = 100L;
    long long bigger_num = 1000000000000000000L;
    double dec = 1000.13901;
    float small_dec = 123.0942f;
    char letter_or_256num = 'c';
    char other_256num = 200; // max is 255
    short smoll = 2049;

    // std::cout = the console output
    // << pushes stuff into console
    // very simplified explanation
    std::cout << "A number: " << num << std::endl;
    std::cout << "A Long number: " << bigger_num << std::endl;
    std::cout << "A decimal number: " << dec << std::endl;

    // converting datatypes
    int long_to_int = (int)bigger_num;
    // some data will be lost
    // long long = 8 bytes im pretty sure
    // int = 4 bytes
    // 4 bytes of data lost when converting
    // maybe make a video on this?

    return 0;
}
