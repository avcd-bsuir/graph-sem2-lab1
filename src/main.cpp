// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 * This file should be used as a template file.
 *
 * Written by AlexeyFilich
 * 24 feb 2020
 */

#include <iostream>

#include "Engine.hpp"
#include "MakeString.hpp"

int main(int argc, char* args[]) {
    Engine engine("Template", 1280, 720, Color(0, 0, 0));

    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (SDL_KEYDOWN == event.type) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_KP_PLUS:
                        printf("SDL_SCANCODE_KP_PLUS have been presssed\n");
                        break;
                    case SDL_SCANCODE_KP_MINUS:
                        printf("SDL_SCANCODE_KP_MINUS have been presssed\n");
                        break;
                    default:
                        break;
                }
            }
        }

        engine.clear();

        for (int i = 30; i < 100; i++)
            for (int j = 30; j < 100; j++)
                engine.setPixel(i, j, Color(255, 0, 0));

        for (int i = 100; i < 200; i++)
            for (int j = 100; j < 180; j++)
                engine.setPixel(i, j, Color(0, 255, 0));

        engine.draw();
    }
    return 0;
}
