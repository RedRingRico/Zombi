#include <File.hpp>

namespace Zombi
{
	File::File( ) :
		m_Open( ZOM_FALSE ),
		m_Size( 0 ),
		m_FileDescriptor( ZOM_INVALID_FILE_DESCRIPTOR ),
		m_FileAccess( 0 )
	{
	}

	File::~File( )
	{
	}

	ZOM_MEMSIZE File::GetSize( ) const
	{
		return m_Size;
	}

	ZOM_BOOL File::IsOpen( ) const
	{
		return m_Open;
	}

	ZOM_FILE_DESCRIPTOR File::GetFileDescriptor( ) const
	{
		return m_FileDescriptor;
	}

	ZOM_UINT32 File::GetFileAccess( ) const
	{
		return m_FileAccess;
	}
}
