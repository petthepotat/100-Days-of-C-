/*
    Day 3 of 100 days of C++
    - random number gen :)
*/

#include <iostream>

const int ARRAY_SIZE = 10;

int main()
{
    /*
        VERY IMPORTANT
        DO NOT DO THIS AT HOME
        not good practice and never smort
        not consistent
    */

    // allocate array of values
    int nums[ARRAY_SIZE];

    std::cout << "Mem allocated! - Checking first value..." << std::endl;

    std::cout << nums[0] << std::endl;

    std::cout << "Run again to check for different values!" << std::endl;

    return 0;
}
