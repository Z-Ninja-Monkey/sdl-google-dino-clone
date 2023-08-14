#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Dino.h"

const int legSpeed = 6;

SDL_Renderer renderer;

int texture = 0;

int y = 300;
bool falling = false;

SDL_Texture* dinoTexture1;
    SDL_Texture* dinoTexture2;
    SDL_Texture* dinoTexture3;
    SDL_Texture* dinoTexture4;
    SDL_Texture* dinoTexture5;
    SDL_Texture* dinoTexture6;
    SDL_Texture* dinoTexture7;
    SDL_Texture* dinoTexture8;

Dino::Dino(SDL_Renderer *inRenderer){
    std::cout << "initalizing dino" << std::endl;
    renderer = inRenderer;
    dinoTexture1 = IMG_LoadTexture(renderer, "assets/textures/dino1.PNG");
    dinoTexture2 = IMG_LoadTexture(renderer, "assets/textures/dino2.PNG");
    dinoTexture3 = IMG_LoadTexture(renderer, "assets/textures/dino3.PNG");
    dinoTexture4 = IMG_LoadTexture(renderer, "assets/textures/dino4.PNG");
    dinoTexture5 = IMG_LoadTexture(renderer, "assets/textures/dino5.PNG");
    dinoTexture6 = IMG_LoadTexture(renderer, "assets/textures/dino6.PNG");
    dinoTexture7 = IMG_LoadTexture(renderer, "assets/textures/dino7.PNG");
    dinoTexture8 = IMG_LoadTexture(renderer, "assets/textures/dino8.PNG");

}

void Dino::hi(){
    std::cout << "hi" << std::endl;
}

void Dino::update(){
    SDL_Rect dino = {70, 70, 100, y};
    
    switch (texture)
    {
    case 1:
        SDL_RenderCopy(renderer, dinoTexture1, NULL, &dino);
        break;
    case 2:
        SDL_RenderCopy(renderer, dinoTexture2, NULL, &dino);
        break;
    case 3:
        SDL_RenderCopy(renderer, dinoTexture3, NULL, &dino);
        break;
    default:
        break;
    }

}