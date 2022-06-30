/*
    Day 4 of 100 days of C++?
    - mini calculator!
*/

#include <iostream>
#include <string>

int var1, var2, section, result;
char op, c;
std::string input, buffer;

bool running;

int main()
{
    std::cout << "Welcome to the TikTok Calculator!" << std::endl;
    running = true;
    while (running)
    {
        // get user input
        std::cout << "Please input a simple mathematical equation! (num [+ - / *] num)" << std::endl;

        // no need for complicated parser
        // all we need is cin
        std::cin >> var1 >> op >> var2;

        // get result
        if (op == '+')
            result = var1 + var2;
        else if (op == '-')
            result = var1 - var2;
        else if (op == '*')
            result = var1 * var2;
        else if (op == '/')
            result = var1 / var2;
        else
        {
            std::cout << "Invalid operation type!" << std::endl;
            return 0;
        }

        std::cout << "Var1: " << var1 << " | Op: " << op << " | Var2: " << var2 << std::endl;

        std::cout << "Answer: " << result << std::endl;

        std::cout << "Another? [Y/N]" << std::endl;
        std::cin >> op;
        if (std::tolower(op) == 'n')
            running = false;
    }

    std::cout << "Thanks for using this calculator!" << std::endl;

    return 0;
}
