#ifndef __ZOMBI_DEBUG_HPP__
#define __ZOMBI_DEBUG_HPP__

#include <string>
#include <DataTypes.hpp>
#include <File.hpp>

namespace Zombi
{
	ZOM_UINT32 OpenLogFile( const std::string &p_FileName );
	ZOM_UINT32 CloseLogFile( );

	ZOM_SINT32 LogDebugMessage( const std::string p_Message );
	ZOM_SINT32 LogInfoMessage( const std::string &p_Message );
	ZOM_SINT32 LogWarnMessage( const std::string &p_Message );
	ZOM_SINT32 LogErrorMessage( const std::string &p_Message );
}

#endif // __ZOMBI_DEBUG_HPP__

