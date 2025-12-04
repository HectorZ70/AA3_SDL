#include "Game.h"

#include <SDL3/SDL.h>
#include <exception>
#include <iostream>
#include "TimeManager.h"

int main()
{
	Game game;

	try
	{
		game.Init();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what();

		game.Release();

		return -1;
	}

	while (game.IsRunning())
	{
		TIME.Update();
		if (TIME.ShouldUpdateGame())
		{
			game.HandelEvents();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
		}
	}

	game.Release();

	return 0;
}