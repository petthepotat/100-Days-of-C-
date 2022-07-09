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
    SDL_Renderer *renderer;

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
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        printf("Failed to create renderer!!!\n");
        return 1;
    }

    // ----------------- day 12 -------------- //
    SDL_Rect _1x1_size = {0, 0, 1, 1};
    SDL_Surface *player_image = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
    SDL_FillRect(player_image, &_1x1_size, SDL_MapRGB(player_image->format, 255, 0, 0));

    SDL_Texture *player = SDL_CreateTextureFromSurface(renderer, player_image);
    SDL_Rect pos = {0, 0, 100, 100};

    // ---------------- end ----------------- //

    SDL_Event event;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    while (running)
    {
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, player, &_1x1_size, &pos);

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
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_a)
                    pos.x -= 5;
                if (event.key.keysym.sym == SDLK_d)
                    pos.x += 5;
                if (event.key.keysym.sym == SDLK_w)
                    pos.y -= 5;
                if (event.key.keysym.sym == SDLK_s)
                    pos.y += 5;
            }
            else if (event.type == SDL_KEYUP)
            {
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(FRAME_TIME);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
