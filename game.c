#define _USE_MATH_DEFINES
#include <SDL2/SDL.h> 
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define FPS 16 // in msec

SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
SDL_Surface *kot, *scr;
int win_width = 640;
int win_height = 480;


void deinit(int error) {
	if (rend != NULL) SDL_DestroyRenderer(rend);
	if (win != NULL) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
} 

void init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("init error: %s\n", SDL_GetError());
		deinit(1);
	}

	win = SDL_CreateWindow(
		"Xex", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		640, 480, SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN 
	);

	if (win == NULL) {
		printf("Error in create win: %s\n", SDL_GetError());
		deinit(1);
	}
	scr = SDL_GetWindowSurface(win);

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (rend == NULL) {
		printf("Error in create renderer: %s\n", SDL_GetError());
		deinit(1);
	}
}

int load(char *image_name) 
{
	kot = SDL_LoadBMP(image_name);

	if (kot == NULL) {
		printf("Cant load bmp: %s", SDL_GetError());
		return 1;
	}
	return 0;	
}

void player_move(SDL_Event evnt, struct player) {
	switch (evnt.key.keysym.sym) {
		case SDLK_a:
			return;
		case SDL_s:
			return;
		case SDL_w:
			return;
		case SDL_d:
			return;
		case SDL_w:
			return;
		defaut:
			return;
	}
}
	
void math_to_screen(double x, double y, double scale, int *sx, int *sy) {
	*sx = x * scale + win_width / 2;
	*sy = win_height / 2 - y * scale;
}	

int main(int argc, char *argv[]) 
{
	init();
	
	bool run = true;
	bool rising = true;
	int point_count = 3;
	int radius = 100;

	SDL_Event evnt;

	while (run) {
		while (SDL_PollEvent(&evnt) != 0) {
			switch (evnt.type) {
				case SDL_QUIT:
					run = false;
					break;
				case SDL_KEYDOWN:
					player_move();
					break;
				default:
					break;
			}
		}
		SDL_Delay(FPS * 2);
	}

	deinit(0);
	return 0;
}
