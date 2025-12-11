#include "Object.h"
#include "Game.h"
#include "ImageObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include "MainMenu.h"

#include "RenderManager.h"


void Game::Init()
{
	RM->Init();
	RM->LoadTexture("resources/image.png");
	RM->LoadFont(FONT_PATH);

	//Carga de escenas
	assert(SM.AddScene("MainMenu", new MainMenu()));
	assert(SM.AddScene("Gameplay", new Gameplay())); //DONA ERROR

	assert(SM.InitFirstScene("MainMenu"));

	_isRunning = true;
}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		throw SDL_GetError();
	}
}

void Game::CreateWindowAndRenderer()
{

}

void Game::HandelEvents()
{
	_isRunning = !IM->Listen();
}

void Game::Update()
{
	SM.UpdateCurrentScene();
}

void Game::Render()
{
	RM->ClearScreen();
	SM.GetCurrentScene()->Render();
	RM->RenderScreen();

}

void Game::Release()
{
	SM.UpdateCurrentScene();
}

bool Game::IsRunning() const
{
	return _isRunning;
}