#include <stdio.h>
#include <SDL.h>

int renderWindow(width, height) {
  int err = 0;

  if((err = SDL_Init(SDL_INIT_VIDEO)) < 0) {
    return err;
  }

  SDL_Window *window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  if(window == NULL) {
      return -1;
  }

  SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
  if(screenSurface == NULL) {
      return -1;
  }

  SDL_Surface *image = SDL_LoadBMP("../assets/animal-chihuahua-cute.bmp");
  if(image == NULL) {
    return -1;
  }
  
  SDL_BlitSurface(image, NULL, screenSurface, NULL);
  if((err = SDL_UpdateWindowSurface(window)) < 0) {
    return err;
  }

  SDL_Delay(40000);

  SDL_FreeSurface(image);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

int main(int argc, const char * argv[]) {
  int error = 0;
  if ((error = renderWindow(800, 800)) < 0) {
    fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return error;
  }

  return 0;
}