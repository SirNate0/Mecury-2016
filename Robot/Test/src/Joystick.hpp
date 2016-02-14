/*
 * Joystick.hpp
 *
 *  Created on: Nov 6, 2015
 *      Author: nathan
 */

#pragma once

//#include <SDL2/SDL.h>

struct Joystick
{
	short x, y, x2, y2, l, r;
	static const int BUTTONS = 11;
	unsigned char buttons[BUTTONS];
	void Read(void* joy)
	{
//		if (SDL_JoystickGetAttached(joy) == false)
//			return;
//		x = SDL_JoystickGetAxis(joy, 0);
//		y = SDL_JoystickGetAxis(joy, 1);
//		x2 = SDL_JoystickGetAxis(joy, 3);
//		y2 = SDL_JoystickGetAxis(joy, 4);
//		l = SDL_JoystickGetAxis(joy, 2);
//		r = SDL_JoystickGetAxis(joy, 5);
//		SDL_JoystickUpdate();
//		for (int i = 0; i < BUTTONS; i++)
//			buttons[i] = SDL_JoystickGetButton(joy, i);
//		printf("%d",SDL_JoystickNumButtons(joy));
//		printf(" %d\n",SDL_JoystickGetButton(joy,0));
	}
	void Print()
	{
		printf("(%d, %d), (%d, %d) [%d | %d]\n", x,y,x2,y2,l,r);
		for (int i = 0; i < BUTTONS; i++)
			if (buttons[i])
				printf("%d:@ ", i);
			else
				printf("%d:  ", i);
//			printf("A%s") todo: use proper labels for the buttons
		printf("\n");

	}
//	void PrintFancy()
//	{
//		/*  x######			    ######X
//		 *     X				   X
//		 * (######,  X		 X		 X
//		 *    X          X		   X   X
//		 *  ######)        (######,	 X
//		 *		------		  X
//		 *		------	    ######)
//		 */
//	}
};

