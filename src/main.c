#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <audio.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <sqlite3.h>
#include <time.h>


#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768
#define  LIMIT_FRAME 16

void SDL_ExitWithError(const char *message);

void SDL_ExitTexture(const char *message, SDL_Window **screen, SDL_Renderer **renderer, SDL_Texture **texture);

void SDL_LimitedFPS(unsigned int limit);

void SDL_Fenetre2();
void hello();
void SDL_game();
unsigned int lastTime = 0, currentTime;
SDL_Renderer *renderer = NULL;
SDL_Surface *fenetre = NULL;
SDL_Surface *fond = NULL;
SDL_Texture *texture = NULL;
SDL_Surface *fond2 = NULL;
SDL_Surface *Z = NULL;
SDL_Surface *S = NULL;
SDL_Surface *Q = NULL;
SDL_Surface *D = NULL;
SDL_Window *window = NULL;

int score = 0;
SDL_Texture *texture2 = NULL;

int main(int argc, char **argv) {
    SDL_Renderer *renderer = NULL;
/*
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
}
*/

    int volume = SDL_MIX_MAXVOLUME;
//les evenements
    SDL_bool program_launched = SDL_TRUE;
    TTF_Init();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_ExitWithError("initialisation SDL");
    }
    //execution du programme...
    const Uint64 timeout = SDL_GetTicks64()+5000;


    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0)
        SDL_ExitWithError("impossible de crée la fenetre et le rendu");

//..........................................................................//


//..................................................//

//image fond principal + texture



    fond = IMG_Load("src/fond_principal.png");

    if (fenetre == NULL) {
        SDL_ExitTexture;

    }
    texture = SDL_CreateTextureFromSurface(renderer, fenetre);
    SDL_FreeSurface(fenetre); //liberation de l'espace
    texture = SDL_CreateTextureFromSurface(renderer, fond);
    SDL_FreeSurface(fond); //liberation de l'espace

    if (texture == NULL) {
        SDL_ExitTexture;
    }
    SDL_Rect rectangle;
    if (SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) {
        SDL_ExitTexture;
    }
    rectangle.x = 0;
    rectangle.y = 0;


    if (SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) {
        SDL_ExitTexture;
    }

//cree police
    if (TTF_Init() != 0) {
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
    }
    int w, h;
    TTF_Font *font1;
    font1 = TTF_OpenFont("JOUER.ttf", 111);

    int iW, iH;
    SDL_Color couleur = {255, 255, 255};
    SDL_Surface *surf = TTF_RenderText_Blended(font1, "PLAY", couleur);
    rectangle.x = 600;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 100;
    SDL_Texture *texttext = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_QueryTexture(texttext, NULL, NULL, &iW, &iH);
    if (SDL_RenderCopy(renderer, texttext, NULL, &rectangle)) {
        SDL_ExitTexture;
    }
    TTF_CloseFont(font1);

    SDL_RenderPresent(renderer);

    while (program_launched) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                        printf("%d/%d\n", event.motion.x, event.motion.y);
                    if (event.motion.x >= 600 && event.motion.x <= 800 && event.motion.y >= 300 &&
                        event.motion.y <= 400) {
                        fond2 = IMG_Load("src/image-fond.png");

                        if (fenetre == NULL) {
                            SDL_ExitTexture;

                        }
                        texture2 = SDL_CreateTextureFromSurface(renderer, fenetre);
                        SDL_FreeSurface(fenetre); //liberation de l'espace
                        texture2 = SDL_CreateTextureFromSurface(renderer, fond2);
                        SDL_FreeSurface(fond2); //liberation de l'espace

                        if (texture2 == NULL) {
                            SDL_ExitTexture;
                        }
                        SDL_Rect rectangle2;
                        if (SDL_QueryTexture(texture2, NULL, NULL, &rectangle2.w, &rectangle2.h) != 0) {
                            SDL_ExitTexture;
                        }
                        rectangle2.x = 0;
                        rectangle2.y = 0;
                        rectangle2.h = 800;
                        rectangle2.w = 1366;


                        if (SDL_RenderCopy(renderer, texture2, NULL, &rectangle2) != 0) {
                            SDL_ExitTexture;
                        }
                        while (SDL_GetTicks64() < timeout) {
                        Z = IMG_Load("src/Z.jpg");

                        if (fenetre == NULL) {
                            SDL_ExitTexture;

                        }
                        texture2 = SDL_CreateTextureFromSurface(renderer, fenetre);
                        SDL_FreeSurface(fenetre); //liberation de l'espace
                        texture2 = SDL_CreateTextureFromSurface(renderer, Z);
                        SDL_FreeSurface(Z); //liberation de l'espace

                        if (texture2 == NULL) {
                            SDL_ExitTexture;
                        }
                        SDL_Rect rectangle3;
                        if (SDL_QueryTexture(texture2, NULL, NULL, &rectangle3.w, &rectangle3.h) != 0) {
                            SDL_ExitTexture;
                        }
                        rectangle3.x = 200;
                        rectangle3.y = 500;
                        rectangle3.h = 100;
                        rectangle3.w = 100;


                        if (SDL_RenderCopy(renderer, texture2, NULL, &rectangle3) != 0) {
                            SDL_ExitTexture;
                        }

                        SDL_RenderPresent(renderer);
                        }
                        fond2 = IMG_Load("src/image-fond.png");

                        if (fenetre == NULL) {
                            SDL_ExitTexture;

                        }
                        texture2 = SDL_CreateTextureFromSurface(renderer, fenetre);
                        SDL_FreeSurface(fenetre); //liberation de l'espace
                        texture2 = SDL_CreateTextureFromSurface(renderer, fond2);
                        SDL_FreeSurface(fond2); //liberation de l'espace

                        if (texture2 == NULL) {
                            SDL_ExitTexture;
                        }
                        if (SDL_RenderCopy(renderer, texture2, NULL, &rectangle2) != 0) {
                            SDL_ExitTexture;
                        }
                        SDL_RenderPresent(renderer);
                       while (SDL_GetTicks64() < timeout){
                        case SDL_SCANCODE_Z:

                            printf("ok");
                            score = score + 200;
                         }
                        if (SDL_GetTicks64() > timeout) {
                            printf("%d le score est de : ", score);
                            score = score - 100;
                            printf("%d trop tard ! le score est de:", score);
                        }


                        continue;
                        case SDL_SCANCODE_S:
                            score = score - 50;
                        printf("%d le score est de : ", score);
                        continue;

                        case SDL_SCANCODE_Q:
                            score = score - 50;
                        printf("%d le score est de :", score);
                        continue;
                        case SDL_SCANCODE_D:
                            score = score - 50;
                        printf("%d le score est de : ", score);
                        continue;

                    }



                    //SDL_Fenetre2();
                    //SDL_game();
                    continue;


                    if (SDL_Init(SDL_INIT_AUDIO) == -1) {
                        printf("SDL_Init: %s\n", SDL_GetError());
                        exit(1);
                    }
                    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
                        printf("Mix_OpenAudio: %s\n", Mix_GetError());
                        exit(2);
                    }
                    int flags = MIX_INIT_OGG | MIX_INIT_MOD;
                    int initted = Mix_Init(flags);
                    if (initted & flags != flags) {
                        printf("Mix_Init: Failed to init required ogg and mod support!\n");
                        printf("Mix_Init: %s\n", Mix_GetError());
                        // handle error
                    }
                    Mix_Music *music;
                    music = Mix_LoadMUS("src/music.mp3");
                    if (!music) {
                        printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
                        // this might be a critical error...
                    }
                    if (Mix_PlayMusic(music, -1) == -1) {
                        printf("Mix_PlayMusic: %s\n", Mix_GetError());
                    }
                    // resume music playback
                    Mix_ResumeMusic();
                    printf("clic gauche effectué\n");

                    if (event.button.button == SDL_BUTTON_RIGHT)
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
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_UP:
                            // set the music volume to 1/2 maximum, and then check it
                            printf("volume est a    : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME * 2));
                            printf("volume passe a  : %d\n", Mix_VolumeMusic(+1));
                            volume <<= 1;
                            Mix_VolumeMusic(volume);

                            continue;
                        case SDL_SCANCODE_DOWN:
                            printf("vous avez appuye sur la fleche du bas \n");
                            // set the music volume to 1/2 maximum, and then check it
                            printf("volume est a   : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME / 2));
                            printf("volume passe a: %d\n", Mix_VolumeMusic(-1));
                            volume >>= 1;
                            Mix_VolumeMusic(volume);
                            continue;

                        case SDL_SCANCODE_B:

                            // resume music playback
                            Mix_ResumeMusic();
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
    unsigned int frame_limited = 0;
    frame_limited = SDL_GetTicks() + LIMIT_FRAME; //debut
    SDL_LimitedFPS(frame_limited); // pour controle la limite
    frame_limited = SDL_GetTicks() + LIMIT_FRAME;// fin pour s assurer de la syncronisation

//...................................................................//
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS; //return 0;
}

void SDL_LimitedFPS(unsigned int limit) {
    unsigned int ticks = SDL_GetTicks();
    if (limit < ticks)
        return;
    else if (limit > ticks + LIMIT_FRAME)
        SDL_Delay(LIMIT_FRAME);
    else
        SDL_Delay(limit - ticks);
}

void SDL_ExitTexture(const char *message, SDL_Window **screen, SDL_Renderer **renderer, SDL_Texture **texture) {
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*screen);
    SDL_DestroyTexture(*texture);
    SDL_ExitWithError(message);
}

void SDL_ExitWithError(const char *message) {
    SDL_Log("ERREUR : %s >\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_Fenetre2() {

    printf("oui");




}

void SDL_game() {
    Z = IMG_Load("src/Z.png");

    if (fenetre == NULL) {
        SDL_ExitTexture;

    }
    texture2 = SDL_CreateTextureFromSurface(renderer, fenetre);
    SDL_FreeSurface(fenetre); //liberation de l'espace
    texture2 = SDL_CreateTextureFromSurface(renderer, Z);
    SDL_FreeSurface(fond2); //liberation de l'espace

    if (texture2 == NULL) {
        SDL_ExitTexture;
    }
    SDL_Rect rectangle2;
    if (SDL_QueryTexture(texture2, NULL, NULL, &rectangle2.w, &rectangle2.h) != 0) {
        SDL_ExitTexture;
    }
    rectangle2.x = 200;
    rectangle2.y = 500;
    rectangle2.h = 40;
    rectangle2.w = 40;


    if (SDL_RenderCopy(renderer, texture2, NULL, &rectangle2) != 0) {
        SDL_ExitTexture;
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_bool program_launched = SDL_TRUE;
    while (program_launched) {
        SDL_Event event;
        while (SDL_PollEvent(&event))
            switch (event.type) {
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_RIGHT)
                            printf("clic droit effectué\n");
                    case SDL_SCANCODE_Z:
                        if(0 < 5000)
                            score = score +200;
                    printf("%d le score est de : \n",score);
                        score = score -100;
                    printf("%d trop tard ! le score est de: \n",score);
                        continue;
                    case SDL_SCANCODE_S:
                        score =score -50;
                    printf("%d le score est de : \n",score);
                        continue;

                    case SDL_SCANCODE_Q:
                        score =score -50;
                    printf("%d le score est de : \n",score);
                        continue;
                    case SDL_SCANCODE_D:
                        score =score -50;
                    printf("%d le score est de : \n",score);
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
void hello()
{
    printf("hello world");
}




//gcc src/main.c -o bin/prog -I include -L lib  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lsqlite3
