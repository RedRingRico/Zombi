#ifndef __ZOMBI_FILE_HPP__
#define __ZOMBI_FILE_HPP__

#include <DataTypes.hpp>
#include <string>

namespace Zombi
{
	const ZOM_UINT32 FILE_ACCESS_MODE_READ		= 0x00000001;
	const ZOM_UINT32 FILE_ACCESS_MODE_WRITE		= 0x00000002;
	const ZOM_UINT32 FILE_ACCESS_MODE_APPEND	= 0x00000004;
	const ZOM_UINT32 FILE_ACCESS_MODE_UPDATE	= 0x00000008;
	const ZOM_UINT32 FILE_ACCESS_MODE_BINARY	= 0x00000010;
	const ZOM_UINT32 FILE_ACCESS_MODE_TEXT		= 0x00000020;

	typedef enum _tagFILE_SEEK
	{
		FILE_SEEK_SET,
		FILE_SEEK_CURRENT,
		FILE_SEEK_END
	}FILE_SEEK;

	class File
	{
	public:
		File( );
		virtual ~File( );

		virtual ZOM_UINT32 Open( const std::string &p_FileName,
			const ZOM_UINT32 p_AccessMode ) = 0;
		virtual ZOM_UINT32 Close( ) = 0;

		virtual ZOM_UINT32 Seek( const FILE_SEEK p_Start,
			const ZOM_SINT64 p_Offset ) = 0;
		virtual ZOM_SINT64 GetPosition( ) const = 0;
		virtual ZOM_UINT32 Rewind( ) = 0;

		virtual ZOM_UINT32 WriteByte( const ZOM_BYTE *p_pData,
			const ZOM_MEMSIZE p_Count, ZOM_MEMSIZE *p_pWritten ) = 0;

		virtual ZOM_UINT32 ReadByte( ZOM_BYTE *p_pData,
			const ZOM_MEMSIZE p_Count, ZOM_MEMSIZE *p_pRead ) = 0;

		ZOM_SINT64 GetSize( ) const;
		ZOM_BOOL IsOpen( ) const;
		ZOM_FILE_DESCRIPTOR	GetFileDescriptor( ) const;
		ZOM_UINT32 GetFileAccess( ) const;

	protected:
		ZOM_BOOL			m_Open;
		ZOM_SINT64			m_Size;
		ZOM_FILE_DESCRIPTOR	m_FileDescriptor;
		ZOM_UINT32			m_FileAccess;
	};
}

#endif // __ZOMBI_FILE_HPP__

