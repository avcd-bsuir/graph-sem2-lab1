// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 *
 *
 * Written by AlexeyFilich
 * 24 feb 2020
 */

#include <iostream>
#include <math.h>

#include "Engine.hpp"
#include "MakeString.hpp"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* args[]) {
    Engine engine("Lab 1", WIDTH, HEIGHT, Color(0x0));

    float a = 150.0f, l = 150.0f;

    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (SDL_KEYDOWN == event.type) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_Q: printf("a (inc) = %f\n", a++); break;
                    case SDL_SCANCODE_A: printf("a (dec) = %f\n", a--); break;
                    case SDL_SCANCODE_E: printf("l (inc) = %f\n", l++); break;
                    case SDL_SCANCODE_D: printf("l (dec) = %f\n", l--); break;
                    default:
                        break;
                }
            }
        }

        engine.clear();

        for (int x = 0; x < WIDTH; x++) engine.setPixel(x, HEIGHT / 2, Color(0, 255, 0));
        for (int y = 0; y < HEIGHT; y++) engine.setPixel(WIDTH / 2, y, Color(0, 255, 0));

        for (float t = 0; t < 2 * 3.14159; t += 0.001) {
            float x = (a * cos(t) * cos(t) + l * cos(t)) + WIDTH / 2,
                  y = (a * cos(t) * sin(t) + l * sin(t)) + HEIGHT / 2;
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
                engine.setPixel((int)x, (int)y, Color(255, 0, 0));
        }

        engine.draw();
    }
    return 0;
}
