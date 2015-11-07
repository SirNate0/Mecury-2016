#pragma once

#ifndef RASPI
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_video.h>
#include <string>
#include <iostream>
using namespace std;

#include "Joystick.hpp"

void Draw(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	SDL_Rect temp;
	temp.x = x;
	temp.y = y;
	SDL_BlitSurface(source, NULL, destination, &temp);
}

SDL_Texture* load_texture(SDL_Renderer* rend, std::string filename)
{
	return IMG_LoadTexture(rend, filename.c_str());
}

SDL_Surface* load_image(std::string filename)
{
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;
	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;
	//Load the image using SDL_image
//		   loadedImage = IMG_Load( filename.c_str() );
	loadedImage = IMG_Load(filename.c_str());
	//If the image loaded
	if (loadedImage != NULL)
	{
		return loadedImage;
		//Create an optimized image
//			optimizedImage = SDL_DisplayFormat(loadedImage);
//			optimizedImage = SDL_ConvertSurfaceFormat(loadedImage);
		//Free the old image
		SDL_FreeSurface(loadedImage);
	}
	//Return the optimized image
	return optimizedImage;
}

class DisplayJoystick
{
	///NOTE: http://www.regexr.com/
	SDL_Texture* bg;

	SDL_Texture* A;
	SDL_Texture* B;
	SDL_Texture* X;
	SDL_Texture* Y;

	SDL_Texture* L;
	SDL_Texture* R;

	SDL_Texture* LTrigger;
	SDL_Texture* RTrigger;

	SDL_Texture* LStick;
	SDL_Texture* RStick;

	SDL_Texture* Start;
	SDL_Texture* Back;

	SDL_Texture* XBox;
public:
	void Load(SDL_Renderer* rend)
	{
		bg = load_texture(rend,"Debug/img/Controller.png");
		A = load_texture(rend,"Debug/img/A.png");
		B = load_texture(rend,"Debug/img/B.png");
		X = load_texture(rend,"Debug/img/X.png");
		Y = load_texture(rend,"Debug/img/Y.png");

		L = load_texture(rend,"Debug/img/L.png");
		R = load_texture(rend,"Debug/img/R.png");

		LTrigger = load_texture(rend,"Debug/img/LTrigger.png");
		RTrigger = load_texture(rend,"Debug/img/RTrigger.png");

		LStick = load_texture(rend,"Debug/img/LStick.png");
		RStick = load_texture(rend,"Debug/img/RStick.png");

		Start = load_texture(rend,"Debug/img/Start.png");
		Back = load_texture(rend,"Debug/img/Back.png");

		XBox = load_texture(rend,"Debug/img/XBox.png");
	}
	SDL_Rect texr;
	void Display(Joystick& joy)
	{
		joy.Print();
		// clear the screen
		SDL_RenderClear(renderer);
		// copy the texture to the rendering context
		SDL_RenderCopy(renderer, bg, NULL, &texr);
		if (joy.buttons[0])
			SDL_RenderCopy(renderer, A, NULL, &texr);
		if (joy.buttons[1])
			SDL_RenderCopy(renderer, B, NULL, &texr);
		if (joy.buttons[2])
			SDL_RenderCopy(renderer, X, NULL, &texr);
		if (joy.buttons[3])
			SDL_RenderCopy(renderer, Y, NULL, &texr);
		if (joy.buttons[4])
			SDL_RenderCopy(renderer, L, NULL, &texr);
		if (joy.buttons[5])
			SDL_RenderCopy(renderer, R, NULL, &texr);
		if (joy.buttons[6])
			SDL_RenderCopy(renderer, Back, NULL, &texr);
		if (joy.buttons[7])
			SDL_RenderCopy(renderer, Start, NULL, &texr);
		if (joy.buttons[8])
			SDL_RenderCopy(renderer, XBox, NULL, &texr);
//		if (i / 50 % 3 == 0)
//			SDL_RenderCopy(renderer,A,NULL, &texr);
//			SDL_RenderDrawLine(renderer, 0, 1, 200, 300);
//			Draw(20,20,A,full);
		// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
		SDL_RenderPresent(renderer);
	}

	SDL_Window *win;
	SDL_Renderer *renderer;
	SDL_Texture *img;

	int InitWindow()
	{
		// variable declarations
		int w, h; // texture width & height
		win = NULL;
		renderer = NULL;
		img = NULL;
		// Initialize SDL.
//		if (SDL_Init(SDL_INIT_VIDEO) < 0)
//				return 1;
#define WIDTH 800
#define HEIGHT 600
#define IMG_PATH "Debug/img/Controller.png"
		// create the window and renderer
		// note that the renderer is accelerated
		win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, 0);
		if (win == NULL)
			return 1;
		renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
//		glEnable(GL_BLEND);
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//		SDL_GL_
		Load(renderer);

		// load our image
		img = IMG_LoadTexture(renderer, IMG_PATH);
		if (img == NULL)
			throw;
		SDL_Surface* full = SDL_GetWindowSurface(win);
		SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
		// put the location where we want the texture to be drawn into a rectangle
		// I'm also scaling the texture 2x simply by setting the width and height
		 texr.x = 0; texr.y = 0; texr.w = w*2; texr.h = h*2;
		int i = 0;
		// main loop
//		while (1) {
//			++i;
//
//			// event handling
//			SDL_Event e;
//			if ( SDL_PollEvent(&e) ) {
//				if (e.type == SDL_QUIT)
//					break;
//				else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
//					break;
//			}
//
//			// clear the screen
			SDL_RenderClear(renderer);
			// copy the texture to the rendering context
			SDL_RenderCopy(renderer, img, NULL, &texr);
			if (i / 50 % 3 == 0)
				SDL_RenderCopy(renderer,A,NULL, &texr);
//			SDL_RenderDrawLine(renderer, 0, 1, 200, 300);
//			Draw(20,20,A,full);
			// flip the backbuffer
			// this means that everything that we prepared behind the screens is actually shown
			SDL_RenderPresent(renderer);
			SDL_Delay(100);
//
//
//
//		}

		SDL_DestroyTexture(img);

		return 0;
	}

	void Close()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(win);
	}

};

//class Engine
//{
//public:
//	void Draw(int x, int y, SDL_Surface *source, SDL_Surface *destination)
//	{
//		SDL_Rect temp;
//		temp.x = x;
//		temp.y = y;
//		SDL_BlitSurface(source, NULL, destination, &temp);
//	}
//
//	SDL_Surface* load_image(std::string filename)
//	{
//		//The image that's loaded
//		SDL_Surface* loadedImage = NULL;
//		//The optimized image that will be used
//		SDL_Surface* optimizedImage = NULL;
//		//Load the image using SDL_image
////		   loadedImage = IMG_Load( filename.c_str() );
//		loadedImage = SDL_LoadBMP(filename.c_str());
//		//If the image loaded
//		if (loadedImage != NULL)
//		{
//			return loadedImage;
//			//Create an optimized image
////			optimizedImage = SDL_DisplayFormat(loadedImage);
////			optimizedImage = SDL_ConvertSurfaceFormat(loadedImage);
//			//Free the old image
//			SDL_FreeSurface(loadedImage);
//		}
//		//Return the optimized image
//		return optimizedImage;
//	}
//};
//
//class Sprite
//{
//public:
//
//	void LoadTexture(Engine* _eng, std::string texture)
//	{
//		Engine* engine = _eng;
//		SDL_Surface* player = engine->load_image("Textures/player1.png");
//		//Set position, center on bottom of the screen. This shouldn't really be here, but it is for now.
////		x = engine->SCR_W / 2 - player->w / 2;
////		y = engine->SCR_H - player->h;
//	}
//};
#endif
