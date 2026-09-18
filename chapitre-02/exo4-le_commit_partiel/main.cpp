
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

#include<iostream>

int main()

{

   SDL_Init(SDL_INIT_VIDEO);

   SDL_Window* fenetre = nullptr;
   SDL_Renderer* rendu = nullptr;

  fenetre = SDL_CreateWindow("ken", 640, 480, 0);
   rendu = SDL_CreateRenderer( fenetre, nullptr);

   SDL_Texture* ken = IMG_LoadTexture(rendu , "ken.png");

   int totalframe = 14;
   float frameheight = 110.0f;
   float framewidth = 115.0f;
    int currentframe = 0;
    float x = 0.0f ,y = 0.0f, w = 0.0f, h = 0.0f;
    

    Uint64 lasttime = SDL_GetTicks64();


   bool run = true;

   while (run)
   {
      SDL_Event e;

      while (SDL_PollEvent(&e))
      {
        if (e.type == SDL_EVENT_QUIT)
        {
            run = false;
        }
        
      }

      Uint64 currentTime = SDL_GetTicks64();

      if (currentTime - lasttime >= 120)
      {
        currentframe = currentframe + 1;

        if(currentframe >= totalframe)
        {
            currentframe = 1;
        } 

        lasttime = currentTime;

      }

      if (currentframe == 1) {x=25.0f ;y=22.0f ;w=55.0f ;h=100.0f ;};
      if (currentframe == 2) {x=90.0f ;y=22.0f ;w=55.0f ;h=100.0f ;};
      if (currentframe == 3) {x=150.0f ;y=22.0f ;w=55.0f ;h=100.0f ;};
      if (currentframe == 4) {x=215.0f ;y=33.0f ;w=55.0f ;h=89.0f ;};
      if (currentframe == 5) {x=275.0f ;y=33.0f ;w=55.0f ;h=89.0f ;};
      if (currentframe == 6) {x=335.0f ;y=22.0f ;w=55.0f ;h=100.0f ;};
      if (currentframe == 7) {x=410.0f ;y=22.0f ;w=55.0f ;h=100.0f ;};
      if (currentframe == 8) {x=30.0f ;y=133.0f ;w=55.0f ;h=144.0f ;};
      if (currentframe == 9) {x=90.0f ;y=133.0f ;w=55.0f ;h=144.0f ;};
      if (currentframe == 10) {x=155.0f ;y=133.0f ;w=55.0f ;h=133.0f ;};
      if (currentframe == 11) {x=220.0f ;y=133.0f ;w=55.0f ;h=133.0f ;};
      if (currentframe == 12) {x=280.0f ;y=133.0f ;w=55.0f ;h=133.0f ;};
      if (currentframe == 13) {x=340.0f ;y=144.0f ;w=50.0f ;h=122.0f ;};
      if (currentframe == 14) {x=400.0f ;y=144.0f ;w=50.0f ;h=122.0f ;};
      

      SDL_FRect srcRect = {x ,y ,w ,h};

      SDL_FRect srcdst = {100.0f , 100.0f , 100.0f , 100.0f};




      SDL_SetRenderDrawColor(rendu, 50, 50,50 ,255);
      SDL_RenderClear(rendu);
      SDL_RenderTexture(rendu, ken, &srcRect , &srcdst);
      SDL_RenderPresent(rendu);
      
      
   }
   


   SDL_DestroyTexture(ken);
   SDL_DestroyRenderer(rendu);
   SDL_DestroyWindow(fenetre);
   SDL_Quit();

   return 0;

}
