#ifndef DINO_H
#define DINO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Dino{
private:
    SDL_Renderer *renderer;
public:
    int y;
    bool falling;
    const int legSpeed;
    int texture;

    Dino(SDL_Renderer *inRenderer);
    void hi();
    void update();

};

#endif 