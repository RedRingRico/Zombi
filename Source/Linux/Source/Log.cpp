#include <Log.hpp>
#include <iostream>
#include <NativeFile.hpp>

namespace Zombi
{
	File *g_pLogFile = ZOM_NULL;

	ZOM_UINT32 OpenLogFile( const std::string &p_FileName )
	{
		if( g_pLogFile == ZOM_NULL )
		{
			g_pLogFile = new NativeFile( );
		}
		std::string FileName = p_FileName;

		if( p_FileName.empty( ) )
		{
			FileName = "Zombi.log";
		}

		if( g_pLogFile->Open( FileName, FILE_ACCESS_MODE_WRITE) != ZOM_OK )
		{
			std::cout << "[Zombi::OpenLogFile] <ERROR> Unable to open log "
				"file for writing" << std::endl;

			return ZOM_FAIL;
		}

		return ZOM_OK;
	}

	ZOM_UINT32 CloseLogFile( )
	{
		g_pLogFile->Close( );

		return ZOM_OK;
	}
}

