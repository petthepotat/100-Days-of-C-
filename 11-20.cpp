/*
    Day 11
    - making an SDL window
*/

#include <SDL2/SDL.h>
#include <stdio.h>

const int WIDTH = 1280, HEIGHT = 720;
const int FPS = 60;
const long FRAME_TIME = 1000 / FPS;

bool running = true;

int main(int argc, char *args[])
{
    SDL_Window *window;
    SDL_Surface *surface;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! [$s]\n", SDL_GetError());
        return 1;
    }

    // create the window
    window = SDL_CreateWindow("TikTok Coding :)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("The window could not be created! [%s]\n", SDL_GetError());
        return 0;
    }

    // get the window surface
    surface = SDL_GetWindowSurface(window);
    // fill window white
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
    // update surface!
    SDL_UpdateWindowSurface(window);
    // wait 2 seconds then close :)

    SDL_Event event;
    while (running)
    {
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_WINDOWEVENT)
            {
                switch (event.window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                    running = false;
                    break;
                }
            }
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(FRAME_TIME);
    }

    return 0;
}
