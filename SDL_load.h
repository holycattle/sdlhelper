#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

bool init(std::string title, int SCREEN_WIDTH, int SCREEN_HEIGHT, int SCREEN_BPP) {
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
		return false;
	}
	
	//Set up the screen
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	//If there was an error in setting up the screen
	if( screen == NULL ) {
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption( title.c_str, NULL );

	//If everything initialized fine
	return true;
}

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

void applySurface( SDL_Surface* source, SDL_Surface* destination, int x, int y, SDL_Rect* clip = NULL ) {
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface( source, clip, destination, &offset );
}
