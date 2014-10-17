#include <NativeFile.hpp>
#include <cstdio>

namespace Zombi
{
	struct NativeFile::FileData
	{
		FILE	*pFile;
	};

	NativeFile::NativeFile( ) :
		m_pFileData( new FileData( ) )
	{
	}

	NativeFile::~NativeFile( )
	{
		this->Close( );
		if( m_pFileData )
		{
			delete m_pFileData;
		}
	}

	ZOM_UINT32 NativeFile::Open( const std::string &p_FileName,
		const ZOM_UINT32 p_Access )
	{
		return ZOM_OK;
	}

	ZOM_UINT32 NativeFile::Close( )
	{
		return ZOM_OK;
	}

	ZOM_UINT32 NativeFile::Seek( const FILE_SEEK p_Start,
		const ZOM_MEMSIZE p_Offset )
	{
		return ZOM_OK;
	}

	ZOM_MEMSIZE NativeFile::GetPosition( ) const
	{
		return 0;
	}

	ZOM_UINT32 NativeFile::Rewind( )
	{
		return ZOM_OK;
	}

	ZOM_UINT32 NativeFile::WriteByte( const ZOM_BYTE *p_pData,
		const ZOM_MEMSIZE p_Count, ZOM_MEMSIZE *p_pWritten )
	{
		return ZOM_OK;
	}

	ZOM_UINT32 NativeFile::ReadByte( ZOM_BYTE *p_pData,
		const ZOM_MEMSIZE p_Count, ZOM_MEMSIZE *p_pRead )
	{
		return ZOM_OK;
	}
}

