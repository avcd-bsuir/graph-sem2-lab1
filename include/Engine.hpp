#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

#include "utils.hpp"

struct Color {
    uint8_t b, g, r, a;
    Color() : r(0), g(0), b(0), a(255) {}
    Color(uint32_t c) : r((c & 0x00FF0000) >> 16), g((c & 0x0000FF00) >> 8), b((c & 0x000000FF)), a((c & 0xFF000000) >> 24) {}
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(255) {}
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
};

class Engine {
    private:
        int width, height;
        bool should_exit;

        SDL_Event event;

        SDL_Renderer * renderer;
        SDL_Surface * surface;
        SDL_Texture * texture;
        SDL_Window * window;
    public:
        Engine(std::string, int, int, Color);
        ~Engine();

        bool shouldExit();

        bool pollEvent(SDL_Event * event);

        void setPixel(int, int, Color);
        Color getPixel(int, int);

        void draw();
        void clear();
};

#endif
