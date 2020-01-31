#pragma once

/**
 * Author:    Alexis Harper
 * Created:   27.01.2020
 *
 * Description: The Image class handles the rendering for 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 **/


class Image
{
public:

    Image (const char* filename);
    ~Image ();

    //Render the image
    void render (GPU_Target* target, float x, float y, GPU_Rect* clip);

protected:

    GPU_Image* texture;
};


class ImageSheet : Image
{
public:

    ImageSheet (const char* filename, int w, int h);
    ~ImageSheet ();

    //Render the image by creating a clip based off of the image index
    void render (GPU_Target * target, float x, float y, int indexX, int indexY);

private:

    //The resolution of each individual image in the sheet
    int resX, resY;
};
