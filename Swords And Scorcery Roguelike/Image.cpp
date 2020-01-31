#include "stdafx.h"
#include "Image.h"


Image::Image (const char* filename)
{
	//Load image file into texture
	this->texture = GPU_LoadImage (filename);

	if (this->texture == NULL)
	{
		GPU_ErrorObject error = GPU_PopErrorCode ();
		const char* errorMessage = GPU_GetErrorString (error.error);
		std::cout << "[-] GPU: " << errorMessage << "\n";

		exit (error.error);
	}

	//Set OpenGL filter to nearest (pixel art mode)
	GPU_SetImageFilter (this->texture, GPU_FILTER_NEAREST);
}


Image::~Image ()
{
	//Free texture upon deletion
	GPU_FreeImage (this->texture);
}


void Image::render (GPU_Target* target, float x, float y, GPU_Rect* clip)
{
	//Render the image on the screen with the given clip rect
	GPU_Blit (this->texture, clip, target, x, y);

	return;
}


ImageSheet::ImageSheet (const char* filename, int w, int h) :
	Image (filename)
{
	//Calculate the resolution of each individual image in the sheet
	this->resX = (int)(this->texture->w / w);
	this->resY = (int)(this->texture->h / h);
}


ImageSheet::~ImageSheet ()
{
	//Everything is done in base class
}


void ImageSheet::render (GPU_Target* target, float x, float y, 
	int indexX, int indexY)
{
	GPU_Rect clip;

	clip.x = (float)(this->resX * indexX);
	clip.y = (float)(this->resY * indexY);
	clip.w = (float)this->resX;
	clip.h = (float)this->resY;

	GPU_Blit (this->texture, &clip, target, x, y);

	return;
}
