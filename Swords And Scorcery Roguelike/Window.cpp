#include "stdafx.h"
#include "Window.h"


Window::Window (const char* windowName)
{
	//Get screen dimentions
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode (0, &displayMode);

	int w = displayMode.w;
	int h = displayMode.h;

	//Set dimentions of window to max size that fits screen 
	if (h < 240 && w < 256)
	{
		//144p 4:3
		this->windowResX = 192;
		this->windowResY = 144;
	}
	else if (h < 240)
	{
		//144p 16:9
		this->windowResX = 256;
		this->windowResY = 144;
	}
	else if (h < 360 && w < 426)
	{
		//240p 4:3
		this->windowResX = 320;
		this->windowResY = 240;
	}
	else if (h < 360)
	{
		//240p 16:9
		this->windowResX = 426;
		this->windowResY = 240;
	}
	else if (h < 480 && w < 640)
	{
		//360p 4:3
		this->windowResX = 480;
		this->windowResY = 360;
	}
	else if (h < 480)
	{
		//360p 16:9
		this->windowResX = 640;
		this->windowResY = 360;
	}
	else if (h < 720 && w < 854)
	{
		//480p 4:3
		this->windowResX = 640;
		this->windowResY = 480;
	}
	else if (h < 720)
	{
		//480p 16:9
		this->windowResX = 854;
		this->windowResY = 480;
	}
	else if (h < 1080)
	{
		//720p 16:9
		this->windowResX = 1280;
		this->windowResY = 720;
	}
	else if (h < 2160)
	{
		//1080p 16:9
		this->windowResX = 1920;
		this->windowResY = 1080;
	}
	else
	{
		//4K
		this->windowResX = 3840;
		this->windowResY = 2160;
	}

	//Tell us if any errors happen at all
	GPU_SetDebugLevel (GPU_DEBUG_LEVEL_MAX);

	//Create window and initialize SDL_gpu
	this->target = GPU_Init (this->windowResX, this->windowResY, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (this->target == NULL) 
	{
		GPU_ErrorObject error = GPU_PopErrorCode ();
		const char* errorMessage = GPU_GetErrorString (error.error);
		std::cout << "[-] GPU: " << errorMessage << "\n";

		exit (error.error);
	}

	//Rename window
	SDL_SetWindowTitle (SDL_GetWindowFromID (this->target->context->windowID),
		windowName);

	//std::cout << this->windowResX << " x " << this->windowResY << "\n";

	GPU_SetVirtualResolution (this->target, 256, 224);

	//Create viewport
	GPU_Rect viewport;

	viewport.w = this->windowResY * 1.33333333f;
	viewport.h = (float) this->windowResY;

	viewport.x = (this->windowResX - viewport.w) * 0.5f;
	viewport.y = 0.0f;

	//std::cout << "(" << viewport.x << ", " << viewport.y << "), " << viewport.w << " x " << viewport.h << "\n";

	//GPU_SetVirtualResolution (this->target, 256, 224);
	GPU_SetViewport (this->target, viewport);

	return;
}


Window::~Window ()
{
	//Deconstructor
}


void Window::resize (int x, int y)
{
	//SDL_GetWindowSize (SDL_GetWindowFromID (this->target->context->windowID), &x, &y);

	//Update the window dimentions
	this->windowResX = x;
	this->windowResY = y;

	std::cout << this->windowResX << " x " << this->windowResY << "\n";

	//Create viewport
	GPU_Rect viewport;

	viewport.w = this->windowResY * 4.0f / 3.0f;
	viewport.h = (float) this->windowResY;

	viewport.x = (this->windowResX - viewport.w) * 0.5f;
	viewport.y = 0.0f;

	std::cout << "(" << viewport.x << ", " << viewport.y << "), " << viewport.w << " x " << viewport.h << "\n";

	GPU_SetViewport (this->target, viewport);

	return;
}

GPU_Target* Window::getTarget ()
{
	return this->target;
}
