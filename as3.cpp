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

	void Game::DrawI(int x, int y)
	{
		screen->Line(100 + x, 50 + y, 200 + x, 50 + y, 0xffffff);
		screen->Line(150 + x, 50 + y, 150 + x, 300 + y, 0xffffff);
		screen->Line(100 + x, 300 + y, 200 + x, 300 + y, 0xffffff);
	}
	void Game::DrawFatI(int x, int y)
	{
		DrawI(x, y);
		DrawI(x + 1, y);
		DrawI(x, y + 1);
		DrawI(x + 1, y + 1);
	}
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{

		// clear the graphics window
		screen->Clear(0);
		DrawFatI(x++, y);
		if (x >= 600)
			x = 0;

	}
};