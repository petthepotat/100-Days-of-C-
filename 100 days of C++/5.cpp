/*
    Day 5? i think
    - hangman :)
*/

#include <iostream>

// to clera the console
#include <stdlib.h>
#include <string>
#include <conio.h>

std::string chosen_word, guess;
int mistakes = 0;
bool running = true;

void update()
{
    // get input
    int i = 0;
    bool found = 0;
    std::cout << "Guess: " << std::endl;
    char in = getch();
    std::cout << in;
    if (in == ':')
    {
        if (getch() == 'q')
        {
            std::cout << 'q';
            running = false;
            return;
        }
    }
    for (; i < chosen_word.size(); i++)
        if (chosen_word[i] == in)
        {
            // is correct
            std::cout << "That is a valid character!" << std::endl;
            // update the guess string
            guess[i] = in;
            found = true;
        }
    if (!found)
    {
        // wrong word
        std::cout << "That is an incorrect character!" << std::endl;
        mistakes++;
    }
    // check if word is filled
    bool done = true;
    for (int i = 0; i < guess.size(); i++)
        if (guess[i] == '_')
        {
            done = false;
            break;
        }
    if (done)
        running = false;
}

void render(int mistakes)
{
    for (int i = 0; i < 6; i++)
        std::cout << '_';
    std::cout << "\n|";
    for (int i = 0; i < 4; i++)
        std::cout << ' ';
    // draw head
    if (mistakes > 0)
        std::cout << 'o';
    std::cout << std::endl;
    // torso
    std::cout << '|';
    for (int i = 0; i < 3; i++)
        std::cout << ' ';
    if (mistakes > 2)
        std::cout << '/';
    else
        std::cout << ' ';
    if (mistakes > 1)
        std::cout << '|';
    if (mistakes > 3)
        std::cout << '\\';
    else
        std::cout << ' ';
    std::cout << std::endl;
    // bottom half
    std::cout << '|';
    for (int i = 0; i < 3; i++)
        std::cout << ' ';
    if (mistakes > 4)
        std::cout << '/';
    else
        std::cout << ' ';
    if (mistakes > 5)
        std::cout << '\\';
    else
        std::cout << ' ';
    // render the guess word
    std::cout << '\t' << guess << std::endl;
}

/*
        o
       /|\
       /\
5 guesses
*/

int main()
{
    // get the word first
    std::cout << "Welcome to hangman!\nInput the word!" << std::endl
              << ">";
    std::cin >> chosen_word;
    guess.append(chosen_word);
    for (int i = 0; i < guess.size(); i++)
        guess[i] = '_';

    // now for guessing + ui
    while (running)
    {
        // now we clear
        system("cls");
        render(mistakes);
        update();
        system("cls");
        render(mistakes);
    }
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}
