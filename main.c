#include <string.h>
#include <stdio.h>
#include <SDL.h>

void SDL_ExitWithError(const char *message);

int main(int argc, char **argv)
{

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
//______________________________________________________________________________________________________


if(SDL_Init(SDL_INIT_VIDEO) !=0) SDL_ExitWithError("Initialisation SDL");
window = SDL_CreateWindow("Jeu obstacle",
                           SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

if(window == NULL) SDL_ExitWithError("Creation fenetre echouee");
//______________________________________________________________________________________________________

renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

if(renderer == NULL) SDL_ExitWithError("Creation rendu echouee");

//______________________________________________________________________________________________________

if(SDL_SetRenderDrawColor(renderer, 36, 29, 69, SDL_ALPHA_OPAQUE) != 0) SDL_ExitWithError("Impossible de charger la couleur du rendu");
SDL_Rect joueur;
joueur.x =375;
joueur.y =500;
joueur.w =50;
joueur.h =100;

if(SDL_RenderFillRect(renderer, &joueur) != 0) SDL_ExitWithError("Impossible de dessiner un trait");

//______________________________________________________________________________________________________

SDL_bool program_launched = SDL_TRUE;

while(program_launched)
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                        program_launched = SDL_FALSE;
                        break;
            default:
                break;
        }
    }

}


//______________________________________________________________________________________________________

SDL_RenderPresent(renderer);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return EXIT_SUCCESS;
}




void SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur : > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
