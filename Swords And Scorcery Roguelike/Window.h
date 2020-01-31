#pragma once

/**
 * Author:    Alexis Harper
 * Created:   27.01.2020
 *
 * Description: The Window class wraps window management together
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 **/


class Window
{
public:

    Window (const char* windowName);
    ~Window ();

    //Called upon resizing of the window, editing the viewport
    void resize (int x, int y);

    //Getters
    GPU_Target* getTarget ();

private:

    //Window dimentions
    int windowResX, windowResY;
    
    //SDL_gpu target and viewport
    GPU_Target* target;
};
