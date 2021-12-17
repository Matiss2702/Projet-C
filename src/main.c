#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <stdio.h>


void SDL_ExitWithError(const char *message);


int main(int argc, char **argv) {
 SDL_Window *window =NULL;
 SDL_Renderer *renderer =NULL;


 if(SDL_Init(SDL_INIT_VIDEO)!=0) {
     SDL_ExitWithError("initialisation SDL");
 }
 //execution du programme...
if (SDL_CreateWindowAndRenderer(800,600,SDL_WINDOW_FULLSCREEN_DESKTOP,&window,&renderer)!=0)
SDL_ExitWithError("impossible de crée la fenetre et le rendu");

if (SDL_SetRenderDrawColor(renderer,255,255,255, SDL_ALPHA_OPAQUE)!=0)
    SDL_ExitWithError("impossible de charger la couleur du rendu");
SDL_Rect menu1;
menu1.x=600;
menu1.y=200;
menu1.w=300;
menu1.h=100;
SDL_Rect menu2;
menu2.x=600;
menu2.y=350;
menu2.w=300;
menu2.h=100;
SDL_Rect menu3;
menu3.x=600;
menu3.y=500;
menu3.w=300;
menu3.h=100;
    if(SDL_RenderFillRect(renderer,&menu1)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");

    if(SDL_RenderFillRect(renderer,&menu2)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");

    if(SDL_RenderFillRect(renderer,&menu3)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");

    if(SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE)!=0)
    SDL_ExitWithError("impossible de charger la couleur du rendu");


if(SDL_RenderDrawRect(renderer, &menu1)!=0)
    SDL_ExitWithError("impossible de dessiner un rectangle");
    if(SDL_RenderDrawRect(renderer, &menu2)!=0)
        SDL_ExitWithError("impossible de dessiner un rectangle");
    if(SDL_RenderDrawRect(renderer, &menu3)!=0)
        SDL_ExitWithError("impossible de dessiner un rectangle");
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);


         SDL_DestroyWindow(window);
         SDL_Quit();
    return EXIT_SUCCESS; //return 0;
}
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s >\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
//gcc src/main.c -o bin/prog -I include -L lib  -lmingw32 -lSDL2main -lSDL2