#include <GitVersion.hpp>
#include <Game.hpp>
#include <Log.hpp>
#include <iostream>
#include <cstring>

int main( int p_Argc, char **p_ppArgv )
{
	std::cout << "Project Zombi" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Build Information" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Commit hash:   " << GIT_COMMITHASH << std::endl;
	std::cout << "Version:       " << GIT_BUILD_VERSION << std::endl;
	std::cout << "Branch:        " << GIT_BRANCH << std::endl;
	std::cout << "Tag:           " << GIT_TAG_NAME << std::endl;
	std::cout << "Rolling count: " << GIT_ROLLINGCOUNT << std::endl;
	std::cout << "Commit time:   " << GIT_COMMITTERDATE << std::endl;

	std::cout << std::endl << "LOG TESTING" << std::endl;

	Zombi::OpenLogFile( "ZombiTest.log" );
	Zombi::CloseLogFile( );


	Zombi::Game TheGame;

	if( TheGame.Initialise( ) != ZOM_OK )
	{
		std::cout << "[main] <ERROR> Something went wrong initialising the "
			"Game object" << std::endl;

		return ZOM_FAIL;
	}

	return TheGame.Execute( );
}

