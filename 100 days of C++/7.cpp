/*
    Day 8 of C++
    - file reader :)
*/

#include <iostream>
#include <fstream>
#include <string>

std::string filename;
std::ifstream file;

int main()
{
    // get filepath
    std::cout << "Input the file path relative to this program~ \n>";
    getline(std::cin, filename);

    // open file
    file.open(filename);

    // check if not opened
    if (!file || !file.is_open())
    {
        std::cout << "Failed to open file at |" << filename << "|" << std::endl;
        file.close();
        return 0;
    }

    std::string line;
    int i = 0;
    while ((bool)getline(file, line))
        std::cout << "[Line " << i++ << "] " << line << std::endl;

    file.close();

    return 0;
}
