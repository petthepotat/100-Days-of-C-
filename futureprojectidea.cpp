// mini advanture game :)

#include <iostream>
#include <string>

const char WALL = 'w', PATH = ' ', PLAYER = 'p';
const int MAP_WIDTH = 100, MAP_HEIGHT = 100;
bool running = true;
char in;

char map[MAP_HEIGHT][MAP_WIDTH];

void update()
{
    in = getchar();
}

void render()
{
}

int main()
{
    // reset map
    for (int i = 0; i < MAP_HEIGHT; i++)
        for (int j = 0; j < MAP_WIDTH; j++)
            map[j][i] = PATH;

    // we can generate map using perlin noise

    running = true;
    return 0;
}
