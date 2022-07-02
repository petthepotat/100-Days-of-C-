/*
    Day 2 of 100 days of C++
    - input from the console!!!
*/

#include <iostream>

int main()
{
    std::cout << "Please input a number!" << std::endl;
    std::cout << ">";

    // get the number
    int number;
    std::cin >> number;

    std::cout << "The number you inputted was: " << number << std::endl;

    return 0;
}
