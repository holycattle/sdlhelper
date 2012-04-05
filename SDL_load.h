#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

SDL_Surface *loadKeyedOptimizedSurface( std::string filename ) {
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//optimized surface
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load( filename.c_str() );

	if( loadedImage != NULL ) {
		//Create optimized surface
        	optimizedImage = SDL_DisplayFormat( loadedImage );
		//Free old surface
		SDL_FreeSurface( loadedImage );
        	if( optimizedImage != NULL ) {
			//Color key surface
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
		}
	}

	//Return the optimized surface
	return optimizedImage;
}

SDL_Surface *loadOptimizedSurface( std::string filename ) {
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//optimized surface
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load( filename.c_str() );

	if( loadedImage != NULL ) {
		//Create optimized surface
        	optimizedImage = SDL_DisplayFormat( loadedImage );
		//Free old surface
		SDL_FreeSurface( loadedImage );
	}

	//Return the optimized surface
	return optimizedImage;
}
