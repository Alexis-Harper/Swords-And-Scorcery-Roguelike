#include "stdafx.h"

#include "Game.h"


int main (int argc, char* args[])
{
	//SDL Video set up so that we can look at the screen resolution
	if (SDL_Init (SDL_INIT_VIDEO) < 0)
	{
		std::cout << "[-] SDL: " << SDL_GetError () << "\n";
	}

	//Run game
	Game game;
	game.run();

	return 0;
}
