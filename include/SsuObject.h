#ifndef _SSUOBJECT_H_
#define _SSUOBJECT_H_

#include <memory.h>
#include <vector>
#include <string>
#include "SsuUtils.h"

namespace ssu
{

	class Object
	{
	public:
		template<typename T>
		inline void pack(T& buf)
		{
			size_t pktSize = size();
			if(pktSize > 0)
			{
				size_t sz = buf.size();
				buf.resize(sz + pktSize);
				packBuffer(reinterpret_cast<unsigned char *>(&buf[sz]));
			}
		}
		inline bool unpack(const void * buffer, size_t length)
		{
			const unsigned char * buf = reinterpret_cast<const unsigned char *>(buffer);
			return unpackBuffer(buf, length);
		}
		virtual size_t size() = 0;
		virtual unsigned char * packBuffer(unsigned char * buf) = 0;
		virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize) = 0;
	};

}

#endif // _SSUOBJECT_H_
