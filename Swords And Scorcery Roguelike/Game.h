#pragma once

/**
 * Author:    Alexis Harper
 * Created:   25.01.2020
 *
 * Description: The Game class deals with the game loop and event handling.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 **/

#include "Window.h"
#include "Image.h"


class Game
{
public:

	Game ();
	~Game ();

	void run ();

private:

    //The stages of the game loop
    void processEvents(); //Process SDL events
    void update(double delta); //Update physics
    void render(GPU_Target* target); //Render game

    

    //All main game vars
    Window window;
    bool exitBool;
};
