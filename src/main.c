#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <audio.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>




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
    TTF_Init();

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0) {
        SDL_ExitWithError("initialisation SDL");
    }
    //execution du programme...



    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE,&window,&renderer)!=0)
        SDL_ExitWithError("impossible de crée la fenetre et le rendu");

//..........................................................................//


//..................................................//

//image fond principal + texture

    SDL_Surface *fenetre = NULL;
    SDL_Surface *fond =NULL;
    SDL_Texture *texture = NULL;
        //    fond = IMG_Load("src/fond_principal.png");

    if(fenetre == NULL)
    {
        SDL_ExitTexture;

    }
    texture = SDL_CreateTextureFromSurface(renderer, fenetre);
    SDL_FreeSurface(fenetre); //liberation de l'espace
    texture = SDL_CreateTextureFromSurface(renderer, fond);
    SDL_FreeSurface(fond); //liberation de l'espace

    if(texture == NULL)
    {
        SDL_ExitTexture;
    }
    SDL_Rect rectangle;
    if(SDL_QueryTexture(texture, NULL , NULL, &rectangle.w,&rectangle.h)!=0)
    {
        SDL_ExitTexture;
    }
    rectangle.x =400;
    rectangle.y = 600;


    if(SDL_RenderCopy(renderer,texture,NULL,&rectangle)!=0)
    {
        SDL_ExitTexture;
    }

//cree police
    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
    }
    TTF_Font * font1;
    font1 = TTF_OpenFont("JOUER.ttf", 72 );
    TTF_CloseFont(font1);
    int iW, iH;
    SDL_Color     couleur  = {255, 255, 255};
    SDL_Surface * surf     = TTF_RenderText_Blended(font1, "PLAY!", couleur);
    SDL_Texture * texttext = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_QueryTexture(texttext, NULL, NULL, &iW, &iH);
    SDL_RenderCopy(renderer, texttext, NULL, &rectangle);/*
TTF_Font *fontJOUER;
fontJOUER= TTF_OpenFont("JOUER.ttf",22);
SDL_Color fontColor ={0,0,0};


//.....................................//

//zone de text

    SDL_Surface *JOUER;
    SDL_Rect JOUERPosition;
    printf("le text :%s\n",JOUER);
    JOUER= TTF_RenderText_Solid(fontJOUER,"PLAY !",fontColor);

    JOUERPosition.x=600;
    JOUERPosition.y=200;
    SDL_BlitSurface(fenetre,NULL,JOUER,&JOUERPosition);
   SDL_FreeSurface(JOUER);
     int SDL_UpdateWindowSurface(SDL_Window *window);*/

SDL_RenderPresent(renderer);
while(program_launched)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {

            case SDL_MOUSEBUTTONDOWN:
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
                // resume music playback
                Mix_ResumeMusic();
                        printf("clic gauche effectué\n");

                if(event.button.button== SDL_BUTTON_RIGHT)
                    printf("clic droit effectué\n");

                     // pause music playback
                    //Mix_PauseMusic();
                continue;

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
                        // set the music volume to 1/2 maximum, and then check it
                        printf("volume was    : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME/2));
                        printf("volume is now : %d\n", Mix_VolumeMusic(-1));
                        continue;
                    case SDL_SCANCODE_UP:
// set the music volume to 1/2 maximum, and then check it
                        printf("volume was    : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME*2));
                        printf("volume is now : %d\n", Mix_VolumeMusic(+1));

                    case SDL_SCANCODE_B:

                        // resume music playback
                        Mix_ResumeMusic();
                        continue;
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
    TTF_Quit();
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
//gcc src/main.c -o bin/prog -I include -L lib  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf