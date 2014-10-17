#include <NativeFile.hpp>
#include <cstdio>
#include <iostream>

namespace Zombi
{
	struct NativeFile::FileData
	{
		FILE	*pFile;
	};

	NativeFile::NativeFile( ) :
		m_pFileData( new FileData( ) )
	{
		m_pFileData->pFile = ZOM_NULL;
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
		this->Close( );

		std::string Access;

		if( p_Access & FILE_ACCESS_MODE_READ )
		{
			if( p_Access & FILE_ACCESS_MODE_WRITE )
			{
				std::cout << "[Zombi::NativeData::Open] <ERROR> "
					"Cannot combine read and write access" << std::endl;

				return ZOM_FAIL;
			}
			if( p_Access & FILE_ACCESS_MODE_APPEND )
			{
				std::cout << "[Zombi::NativeData::Open] <ERROR> "
					"Cannot combine read and append access" << std::endl;

				return ZOM_FAIL;
			}

			Access += 'r';
		}

		if( p_Access & FILE_ACCESS_MODE_WRITE )
		{
			if( p_Access & FILE_ACCESS_MODE_READ )
			{
				std::cout << "[Zombi::NativeData::Open] <ERROR> "
					"Cannot combine write and read access" << std::endl;

				return ZOM_FAIL;
			}

			if( p_Access & FILE_ACCESS_MODE_APPEND )
			{
				std::cout << "[Zombi::NativeData::Open] <ERROR> "
					"Cannot combine write and append access" << std::endl;

				return ZOM_FAIL;
			}

			Access += 'w';
		}

		if( p_Access & FILE_ACCESS_MODE_APPEND )
		{
			if( p_Access & FILE_ACCESS_MODE_READ )
			{
				std::cout << "[Zombi::NativeData::Open] <ERROR> "
					"Cannot combine append and read access" << std::endl;

				return ZOM_FAIL;
			}

			if( p_Access & FILE_ACCESS_MODE_WRITE )
			{
				std::cout << "[Zombi::NativeData::Open] <ERROR> "
					"Cannot combine append and write access" << std::endl;

				return ZOM_FAIL;
			}

			Access += 'a';
		}

		if( p_Access & FILE_ACCESS_MODE_UPDATE )
		{
			Access += '+';
		}

		if( Access.size( ) <= 0 )
		{
			std::cout << "[Zombi::NativeData::Open] <ERROR> "
				"Unrecognised access flags passed" << std::endl;

			return ZOM_FAIL;
		}

		m_pFileData->pFile = fopen( p_FileName.c_str( ), Access.c_str( ) );

		if( m_pFileData->pFile == ZOM_NULL )
		{
			std::cout << "[Zombi::NativeData::Open] <ERROR> "
				"Could not open file: " << p_FileName << std::endl;

			return ZOM_FAIL;
		}

		fseek( m_pFileData->pFile, 0, SEEK_END );
		m_Size = ftell( m_pFileData->pFile );
		rewind( m_pFileData->pFile );

		m_FileDescriptor = fileno( m_pFileData->pFile );

		if( m_FileDescriptor == ZOM_INVALID_FILE_DESCRIPTOR )
		{
			this->Close( );

			switch( errno )
			{
				case EBADF:
				{
					std::cout << "[Zombi::NativeData::Open] <ERROR> "
						"Could not obtain file descriptor, file stream "
						"invalid" << std::endl;

					break;
				}
				default:
				{
					std::cout << "[Zombi::NativeData::Open] <ERROR> "
						"Unknown error occurred while attempting to obtain the"
						"file descriptor from the file stream" << std::endl;
					break;
				}
			}

			return ZOM_FAIL;
		}

		m_Open = ZOM_TRUE;

		return ZOM_OK;
	}

	ZOM_UINT32 NativeFile::Close( )
	{
		if( m_pFileData->pFile )
		{
			fclose( m_pFileData->pFile );
			m_pFileData->pFile = ZOM_NULL;
		}

		m_Open = ZOM_FALSE;
		m_FileDescriptor = ZOM_INVALID_FILE_DESCRIPTOR;

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

