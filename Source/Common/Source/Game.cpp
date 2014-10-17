#include <Game.hpp>
#include <iostream>

namespace Zombi
{
	Game::Game( )
	{
	}

	Game::~Game( )
	{
	}

	ZOM_UINT32 Game::Initialise( )
	{
		if( this->PlatformInitialise( ) != ZOM_OK )
		{
			std::cout << "[Zombi::Game::Initialise] <ERROR> Failed to perform "
				"platform-specific initialisation" << std::endl;

			return ZOM_FAIL;
		}

		return ZOM_OK;
	}

	ZOM_UINT32 Game::Execute( )
	{
		return ZOM_OK;
	}
}

