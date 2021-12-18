#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768
#define  LIMIT_FRAME 16

void SDL_ExitWithError(const char *message);
void SDL_ExitTexture (const char *message, SDL_Window **screen, SDL_Renderer **renderer , SDL_Texture **texture);
void SDL_LimitedFPS(unsigned int limit);

int main(int argc, char **argv) {
 SDL_Window *window =NULL;
 SDL_Renderer *renderer =NULL;


 if(SDL_Init(SDL_INIT_VIDEO)!=0) {
     SDL_ExitWithError("initialisation SDL");
 }
 //execution du programme...
 // creation du rendu et windows
if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE,&window,&renderer)!=0)
    SDL_ExitWithError("impossible de crée la fenetre et le rendu");

//..........................................................................//

  //coloration du rendu (blanc)
if (SDL_SetRenderDrawColor(renderer,255,255,255, SDL_ALPHA_OPAQUE)!=0)
    SDL_ExitWithError("impossible de charger la couleur du rendu");
//..................................................//
//création de rectangle
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
//..................................................................//
//chargement de la couleur du rendu suivant les rectangle

    if(SDL_RenderFillRect(renderer,&menu1)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");

    if(SDL_RenderFillRect(renderer,&menu2)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");

    if(SDL_RenderFillRect(renderer,&menu3)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");

    if(SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE)!=0)
    SDL_ExitWithError("impossible de charger la couleur du rendu");
//...............................................................//
//insertion des different rectangle
if(SDL_RenderDrawRect(renderer, &menu1)!=0)
    SDL_ExitWithError("impossible de dessiner un rectangle");

    if(SDL_RenderDrawRect(renderer, &menu2)!=0)
        SDL_ExitWithError("impossible de dessiner un rectangle");

    if(SDL_RenderDrawRect(renderer, &menu3)!=0)
        SDL_ExitWithError("impossible de dessiner un rectangle");

//...................................................................//
//les evenements
SDL_bool program_launched = SDL_TRUE;

//image fond principal + texture

    SDL_Surface *image_principal = NULL;
    SDL_Texture *texture = NULL;
    image_principal = SDL_LoadBMP("src/fond_principal.bmp");

    if(image_principal == NULL)
    {
        SDL_ExitTexture;

    }
    texture = SDL_CreateTextureFromSurface(renderer, image_principal);
    SDL_FreeSurface(image_principal); //liberation de l'espace


    if(texture == NULL)
    {
        SDL_ExitTexture;
    }
    SDL_Rect rectangle;
    if(SDL_QueryTexture(texture, NULL , NULL, &rectangle.w,&rectangle.h)!=0)
    {
        SDL_ExitTexture;
    }
    rectangle.x =0;
    rectangle.y =0;


    if(SDL_RenderCopy(renderer,texture,NULL,&rectangle)!=0)
    {
        SDL_ExitTexture;
    }

    //........................................................//
    SDL_RenderPresent(renderer);
while(program_launched)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.clicks >=2)

                    break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_LEAVE)
                    printf(" la souris est sortie de la fenetre\n");
                    if (event.window.event == SDL_WINDOWEVENT_ENTER)
                        printf("la souris est rentre dans la fenetre");

            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_DOWN:
                        printf("vous avez appuye sur la fleche du bas \n");
                        continue;
                    default:
                        continue;
                }


            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
            default:
                break;
        }
    }
}
//.......................................//
//fps
unsigned  int frame_limited =0;
frame_limited = SDL_GetTicks()+LIMIT_FRAME; //debut
    SDL_LimitedFPS(frame_limited); // pour controle la limite
    frame_limited = SDL_GetTicks()+LIMIT_FRAME;// fin pour s assurer de la syncronisation

//...................................................................//

    SDL_Quit();
    return EXIT_SUCCESS; //return 0;
}
void SDL_LimitedFPS(unsigned int limit)
{
    unsigned int ticks = SDL_GetTicks();
    if (limit< ticks)
        return;
    else if(limit > ticks + LIMIT_FRAME)
        SDL_Delay(LIMIT_FRAME);
        else
        SDL_Delay(limit - ticks);
}
void SDL_ExitTexture (const char *message, SDL_Window **screen, SDL_Renderer **renderer , SDL_Texture **texture)
{
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*screen);
    SDL_DestroyTexture(*texture);
    SDL_ExitWithError(message);
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s >\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
//gcc src/main.c -o bin/prog -I include -L lib  -lmingw32 -lSDL2main -lSDL2