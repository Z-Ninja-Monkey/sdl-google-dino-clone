#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Dino.h"

#define SCREEN_WIDTH 800
#define SCREEN_HIGHT 500

SDL_Renderer *renderer;

int main(int argc, char *argv[]){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Google Dino", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Color bg = {255,255,255,255};

    SDL_Texture* smileyFace = IMG_LoadTexture(renderer, "assets/textures/smileyface.jpg");

    //load all the sprite textures

    SDL_Texture* cactusTexture1 = IMG_LoadTexture(renderer, "assets/textures/cactus1.PNG");
    SDL_Texture* cactusTexture2 = IMG_LoadTexture(renderer, "assets/textures/cactus2.PNG");
    SDL_Texture* cactusTexture3 = IMG_LoadTexture(renderer, "assets/textures/cactus3.PNG");
    SDL_Texture* cactusTexture4 = IMG_LoadTexture(renderer, "assets/textures/cactus4.PNG");
    SDL_Texture* cactusTexture5 = IMG_LoadTexture(renderer, "assets/textures/cactus5.PNG");
    SDL_Texture* cactusTexture6 = IMG_LoadTexture(renderer, "assets/textures/cactus6.PNG");
    SDL_Texture* groundTexture = IMG_LoadTexture(renderer, "assets/textures/ground.PNG");


    Dino dino(renderer);
    dino.hi();

    int frameCount1 = -1;

    int groundX = 0;
    int groundX2 = 0;

    int dinoY = 300;
    bool spaceBarDown = false;
    bool falling = false;
    float gravity = 1;

    bool gameRunning = true;
    while(gameRunning){
        //do stuff
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT){
                gameRunning = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                spaceBarDown = true;
            } else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE) {
                spaceBarDown = false;
            }
        }
        SDL_RenderClear(renderer);

        if(groundX <= -1600 && groundX2 <= -1600){
            groundX2 = 800;
        }
        
        if(groundX <= -2400){
            groundX = groundX2;
        }

        SDL_Rect ground;
        ground.w = 2400;
        ground.h = 24;
        ground.x = groundX;
        ground.y = 350;
        SDL_RenderCopy(renderer, groundTexture, NULL, &ground);
        groundX -= 8;

        SDL_Rect ground2;
        ground2.w = 2400;
        ground2.h = 24;
        ground2.x = groundX2;
        ground2.y = 350;
        SDL_RenderCopy(renderer, groundTexture, NULL, &ground2);
        groundX2 -= 8;        
        //std::cout << groundX2 << std::endl;

        if(spaceBarDown && !dino.falling && dino.y > 200){
            dino.falling = false;
            dino.y -= 14;
            dino.texture = 1;
        } else if (dino.y < 290){
            dino.falling = true;
            if(gravity < 20){gravity *= (gravity * 0.2);}
            dino.y -= 5 - gravity;
            dino.texture = 1;
        } else {
            dino.y = 300;
            gravity = 1;
            dino.falling = false;

            if(frameCount1 < dino.legSpeed){
                dino.texture = 2;
            } else {
                dino.texture = 3;
            }
        }

    

        if(frameCount1 == dino.legSpeed * 2){
            frameCount1 = 0;
        }

        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / 60);
        frameCount1++;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
