#include <SDL2/SDL.h>
#include <map>

#include "keyboard.hpp"

static SDL_Event event;

static map<SDL_Keycode, uint8_t> ConversionMap = {
    {SDLK_1, 0x1},
    {SDLK_2, 0x2},
    {SDLK_3, 0x3},
    {SDLK_4, 0xC},
    {SDLK_q, 0x4},
    {SDLK_w, 0x5},
    {SDLK_e, 0x6},
    {SDLK_r, 0xD},
    {SDLK_a, 0x7},
    {SDLK_s, 0x8},
    {SDLK_d, 0x9},
    {SDLK_f, 0xE},
    {SDLK_z, 0xA},
    {SDLK_x, 0x0},
    {SDLK_c, 0xB},
    {SDLK_v, 0xF},
};

Keyboard::Keyboard()
{
    if (SDL_Init(SDL_INIT_EVENTS))
    {
        cout << "Unable to init keyboard." << endl;
        cout << SDL_GetError() << endl;
        SDL_Quit();
    }
}

void Keyboard::Clear()
{
    for (uint8_t keyIndex = 0; keyIndex < KeysNumber; keyIndex++)
        keys[keyIndex];
}

bool Keyboard::Poll()
{
    bool ret = true;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                ret = false;
                break;

            case SDL_KEYDOWN:
                if (ConversionMap.find(event.key.keysym.sym) != ConversionMap.end())
                    keys[ConversionMap[event.key.keysym.sym]] = true;

                break;

            case SDL_KEYUP:
                if (ConversionMap.find(event.key.keysym.sym) != ConversionMap.end())
                    keys[ConversionMap[event.key.keysym.sym]] = false;
                
                break;

            default:
                break;
        }
    }

    return ret;
}

bool Keyboard::IsKeyPressed(uint8_t key)
{
    return (key >= 0 && key < KeysNumber && keys[key]);
}

uint8_t Keyboard::WaitForKeyPress()
{
    bool shouldReturn = false;
    uint8_t returnKey = 0;

    while (!shouldReturn)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    returnKey UINT8_MAX;
                    break;

                case SDL_KEYDOWN:
                    returnKey = ConversionMap[event.key.keysym.sym];
                    shouldReturn = true;

                    break;

                default:
                    break;
            }
        }
    }

    return returnKey;
}