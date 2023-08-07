#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HIGHT 500


int main(int argc, char *argv[]){

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Google Dino", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Color bg = {255,255,255,255};

    SDL_Texture* smileyFace = IMG_LoadTexture(renderer, "assets/textures/smileyface.jpg");

    //load all the sprite textures
    SDL_Texture* dinoTexture1 = IMG_LoadTexture(renderer, "assets/textures/dino1.PNG");
    SDL_Texture* dinoTexture2 = IMG_LoadTexture(renderer, "assets/textures/dino2.PNG");
    SDL_Texture* dinoTexture3 = IMG_LoadTexture(renderer, "assets/textures/dino3.PNG");
    SDL_Texture* dinoTexture4 = IMG_LoadTexture(renderer, "assets/textures/dino4.PNG");
    SDL_Texture* dinoTexture5 = IMG_LoadTexture(renderer, "assets/textures/dino5.PNG");
    SDL_Texture* dinoTexture6 = IMG_LoadTexture(renderer, "assets/textures/dino6.PNG");
    SDL_Texture* dinoTexture7 = IMG_LoadTexture(renderer, "assets/textures/dino7.PNG");
    SDL_Texture* dinoTexture8 = IMG_LoadTexture(renderer, "assets/textures/dino8.PNG");
    SDL_Texture* cactusTexture1 = IMG_LoadTexture(renderer, "assets/textures/cactus1.PNG");
    SDL_Texture* cactusTexture2 = IMG_LoadTexture(renderer, "assets/textures/cactus2.PNG");
    SDL_Texture* cactusTexture3 = IMG_LoadTexture(renderer, "assets/textures/cactus3.PNG");
    SDL_Texture* cactusTexture4 = IMG_LoadTexture(renderer, "assets/textures/cactus4.PNG");
    SDL_Texture* cactusTexture5 = IMG_LoadTexture(renderer, "assets/textures/cactus5.PNG");
    SDL_Texture* cactusTexture6 = IMG_LoadTexture(renderer, "assets/textures/cactus6.PNG");
    SDL_Texture* groundTexture = IMG_LoadTexture(renderer, "assets/textures/ground.PNG");

    const int legSpeed = 6;


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

        if(spaceBarDown && !falling && dinoY >200){
            falling = false;
            dinoY -= 14;
            SDL_Rect dinoRun3;
            dinoRun3.w = 70;
            dinoRun3.h = 70;
            dinoRun3.x = 100;
            dinoRun3.y = dinoY;
            SDL_RenderCopy(renderer, dinoTexture1, NULL, &dinoRun3);
        } else if (dinoY < 290){
            falling = true;
            if(gravity < 20){gravity *= 1.2;}
            dinoY -= 5 - gravity;
            SDL_Rect dinoRun3;
            dinoRun3.w = 70;
            dinoRun3.h = 70;
            dinoRun3.x = 100;
            dinoRun3.y = dinoY;
            SDL_RenderCopy(renderer, dinoTexture1, NULL, &dinoRun3);
        } else {
            dinoY = 300;
            gravity = 1;
            falling = false;

            if(frameCount1 < legSpeed){
                SDL_Rect dinoRun1;
                dinoRun1.w = 70;
                dinoRun1.h = 70;
                dinoRun1.x = 100;
                dinoRun1.y = dinoY;
                SDL_RenderCopy(renderer, dinoTexture2, NULL, &dinoRun1);
            } else {
                SDL_Rect dinoRun2;
                dinoRun2.w = 70;
                dinoRun2.h = 70;
                dinoRun2.x = 100;
                dinoRun2.y = dinoY;
                SDL_RenderCopy(renderer, dinoTexture3, NULL, &dinoRun2);
            }
        }

    

        if(frameCount1 == legSpeed * 2){
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
