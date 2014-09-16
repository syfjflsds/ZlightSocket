/*********************************************************************************
*
*    ZLoger,  «Zlight SocketµƒLoger£¨ø…“‘Õ®π˝À¸¿¥∑Ω±„µÿ‘ˆº”µ˜ ‘–≈œ¢
*
**********************************************************************************/

#ifndef _ZLOGER_H__
#define _ZLOGER_H__

#include <cstdio>
#ifndef WIN32
#include <unistd.h>
#endif

namespace Zlight
{
	class ZLogger
	{
	public:
		static ZLogger & getInstance(); //ªÒ»°ZLogger µ¿˝
		void setEnable(bool isEnable);  //…Ë÷√ «∑Ò¥Ú”°Log
		void Log(const char *logInfo);  //”√Log¿¥º«¬º–≈œ¢
	private:
		ZLogger();
		virtual ~ZLogger();
	private:
		static ZLogger *m_zloger;
		std::FILE *m_fp;
		bool m_enable;
	};
}


#define LOGGER Zlight::ZLogger::getInstance()

#endif