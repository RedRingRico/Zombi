#ifndef __ZOMBI_GAME_HPP__
#define __ZOMBI_GAME_HPP__

#include <DataTypes.hpp>

namespace Zombi
{
	class Game
	{
	public:
		Game( );
		~Game( );

		ZOM_UINT32 Initialise( );
		ZOM_UINT32 Execute( );

	private:
		ZOM_UINT32 PlatformInitialise( );
	};
}

#endif // __ZOMBI_GAME_HPP__

