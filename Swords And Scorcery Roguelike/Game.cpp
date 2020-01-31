#include "stdafx.h"
#include "Game.h"

#include <chrono>

using namespace std::chrono_literals;


constexpr std::chrono::nanoseconds timestep(16ms); //60 ticks per sec


Game::Game () :
	window ("Swords & Scorcery Roguelike"),
	exitBool (false)
{

}


Game::~Game()
{
	GPU_Quit ();
}


void Game::run()
{
	//Get time right after initialization
	auto startTime = std::chrono::high_resolution_clock::now ();

	//Loop game until game is closed out of
	while (!this->exitBool)
	{
		//Calculates delta (time since last frame)
		auto deltaTime = std::chrono::high_resolution_clock::now () - startTime;

		//Process SDL events every opportunity
		this->processEvents ();

		//Limit FPS to 60 Hz
		if (std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime) 
			>= timestep)
		{
			//Recalculate the start time for each frame
			startTime = std::chrono::high_resolution_clock::now ();

			//Calculate the length of frame in units of frames
			double delta = std::chrono::duration_cast<std::chrono::duration
				<double, std::nano>> (deltaTime) / std::chrono::duration_cast
				<std::chrono::duration<double, std::nano>>(timestep);

			//Update game and render 
			this->update (delta);
			this->render (this->window.getTarget ());
		}
	}

	return;
}


void Game::processEvents()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent (&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:

			this->exitBool = true;

			break;

		case SDL_WINDOWEVENT:

			if (sdlEvent.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				//Resize viewport to fit the aspect ratio
				window.resize (sdlEvent.window.data1, sdlEvent.window.data2);
			}

			break;
		}
	}

	return;
}


void Game::update (double delta)
{
	//Nothing yet
	
	return;
}


void Game::render (GPU_Target* target)
{
	//Clear current screen
	GPU_Clear (target);
	
	//Swap buffers
	GPU_Flip (target);

	return;
}
