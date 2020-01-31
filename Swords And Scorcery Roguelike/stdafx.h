#pragma once

//Include basic IO
#include <iostream>

//Include SDL
#include <SDL.h>

//Include GPU
#include <SDL_gpu.h>

//Add memory map info in Debug mode
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>  
#include <crtdbg.h> 

#define _new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#else

#define _new new

#endif
