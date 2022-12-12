#include "game.h"
#include "surface.h"
#include <iostream> //printf

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{

	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}


	Sprite theSprite(new Surface("assets/ctankbase.tga"), 16);
	static int frame = 0;
	int x = 0, y = 1;

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
   	{

		// clear the graphics window
		screen->Clear(0);
		for (int i = 0; i < 10; i++)
		{
		    for (int j = 0; j < 16; j++)
		    {
			theSprite.SetFrame(j);
			theSprite.Draw(screen, i * 50, j * 50);
		    }
		}
	}
};
