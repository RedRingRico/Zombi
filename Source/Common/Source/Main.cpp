#include <GitVersion.hpp>
#include <Game.hpp>
#include <NativeFile.hpp>
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

	std::cout << std::endl << "FILE TESTING" << std::endl;

	Zombi::NativeFile FileTest;

	if( FileTest.Open( "zombi.txt",
		Zombi::FILE_ACCESS_MODE_WRITE | Zombi::FILE_ACCESS_MODE_UPDATE ) !=
			ZOM_OK )
	{
		std::cout << "Failed to open file for writing" << std::endl;
	}

	ZOM_SINT64 FilePosition = FileTest.GetPosition( );

	if( FilePosition == -1)
	{
		std::cout << "Could not get position (unexpected result)" << std::endl;
	}
	else
	{
		std::cout << "File position: " << FilePosition << std::endl;
	}

	std::string TestString( "Testing the file API\n\n" );

	FileTest.WriteByte(
		reinterpret_cast< const ZOM_BYTE * >( TestString.c_str( ) ),
		TestString.size( ), ZOM_NULL );

	ZOM_BYTE ReadBack[ FileTest.GetSize( ) + 1 ];
	memset( ReadBack, '\0', TestString.size( ) + 1 );

	FileTest.Rewind( );

	FileTest.ReadByte( ReadBack,
		FileTest.GetSize( ), ZOM_NULL );

	std::cout << "Read back: " << std::endl << ReadBack << std::endl;

	FilePosition = FileTest.GetPosition( );

	if( FilePosition == -1)
	{
		std::cout << "Could not get position (unexpected result)" << std::endl;
	}
	else
	{
		std::cout << "File position: " << FilePosition << std::endl;
	}

	std::cout << "File size: " << FileTest.GetSize( ) << std::endl;

	FileTest.Close( );

	if( FileTest.GetPosition( ) == -1)
	{
		std::cout << "Could not get position (expected result)" << std::endl;
	}

	Zombi::Game TheGame;

	if( TheGame.Initialise( ) != ZOM_OK )
	{
		std::cout << "[main] <ERROR> Something went wrong initialising the "
			"Game object" << std::endl;

		return ZOM_FAIL;
	}

	return TheGame.Execute( );
}

