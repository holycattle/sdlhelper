#include "SDL_load.h"

//for testing
class GameObject: public SDL_Surface {
	public:
		int x, y, width, height;
		std::string name;
		void show();
		virtual void handleInput() = 0;
};

class MovingGameObject: public GameObject {
	public:
		int xVelocity, yVelocity;
		virtual void move() = 0;
};
