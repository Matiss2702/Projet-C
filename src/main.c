#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <audio.h>
#include <SDL_mixer.h>



#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768
#define  LIMIT_FRAME 16

void SDL_ExitWithError(const char *message);
void SDL_ExitTexture (const char *message, SDL_Window **screen, SDL_Renderer **renderer , SDL_Texture **texture);
void SDL_LimitedFPS(unsigned int limit);

int main(int argc, char **argv) {
 SDL_Window *window =NULL;
 SDL_Renderer *renderer =NULL;


//les evenements
    SDL_bool program_launched = SDL_TRUE;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0) {
        SDL_ExitWithError("initialisation SDL");
    }
    //execution du programme...



    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE,&window,&renderer)!=0)
        SDL_ExitWithError("impossible de crée la fenetre et le rendu");

//..........................................................................//

    //coloration du rendu (blanc)
    if (SDL_SetRenderDrawColor(renderer,255,255,255, SDL_ALPHA_OPAQUE)!=0)
        SDL_ExitWithError("impossible de charger la couleur du rendu");
//..................................................//

//image fond principal + texture

    SDL_Surface *image_principal = NULL;
    SDL_Texture *texture = NULL;
    image_principal = IMG_Load("src/fond_principal.png");

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
                    if(event.button.button== SDL_BUTTON_LEFT)
                        // load the MP3 file "music.mp3" to play as music


// start SDL with audio support
                        if(SDL_Init(SDL_INIT_AUDIO)==-1) {
                            printf("SDL_Init: %s\n", SDL_GetError());
                            exit(1);
                        }
// open 44.1KHz, signed 16bit, system byte order,
//      stereo audio, using 1024 byte chunks
                if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
                    printf("Mix_OpenAudio: %s\n", Mix_GetError());
                    exit(2);
                }


// load support for the OGG and MOD sample/music formats
                int flags=MIX_INIT_OGG|MIX_INIT_MOD;
                int initted=Mix_Init(flags);
                if(initted&flags != flags) {
                    printf("Mix_Init: Failed to init required ogg and mod support!\n");
                    printf("Mix_Init: %s\n", Mix_GetError());
                    // handle error
                }
                Mix_Music *music;
                music=Mix_LoadMUS("src/music.mp3");
                if(!music) {
                    printf("Mix_LoadMUS(\"goku.mp3\"): %s\n", Mix_GetError());
                    // this might be a critical error...
                }


// play music forever
// Mix_Music *music; // I assume this has been loaded already
                if(Mix_PlayMusic(music, -1)==-1) {
                    printf("Mix_PlayMusic: %s\n", Mix_GetError());
                    // well, there's no music, but most games don't break without music...
                }
                        printf("clic gauche effectué\n");
                if(event.button.button== SDL_BUTTON_RIGHT)
                    printf("clic droit effectué\n");
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
    Mix_CloseAudio();
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
//gcc src/main.c -o bin/prog -I include -L lib  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer