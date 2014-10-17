#ifndef __ZOMBI_NATIVEFILE_HPP__
#define __ZOMBI_NATIVEFILE_HPP__

#include <File.hpp>

namespace Zombi
{
	class NativeFile : public File
	{
	public:
		NativeFile( );
		virtual ~NativeFile( );

		virtual ZOM_UINT32 Open( const std::string &p_FileName,
			const ZOM_UINT32 p_Access );
		virtual ZOM_UINT32 Close( );

		virtual ZOM_UINT32 Seek( const FILE_SEEK p_Start,
			const ZOM_MEMSIZE p_Offset );
		virtual ZOM_MEMSIZE GetPosition( ) const;
		virtual ZOM_UINT32 Rewind( );

		virtual ZOM_UINT32 WriteByte( const ZOM_BYTE *p_pData,
			const ZOM_MEMSIZE p_Count, ZOM_MEMSIZE *p_pWritten );

		virtual ZOM_UINT32 ReadByte( ZOM_BYTE *p_pData,
			const ZOM_MEMSIZE p_Count, ZOM_MEMSIZE *p_pRead );

	private:
		struct FileData;

		FileData	*m_pFileData;
	};
}

#endif // __ZOMBI_NATIVEFILE_HPP__

