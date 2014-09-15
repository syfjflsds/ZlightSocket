/*********************************************************************************
*
*    ZLoger, 是Zlight Socket的Loger，可以通过它来方便地增加调试信息
*
**********************************************************************************/

#ifndef _ZLOGER_H__
#define _ZLOGER_H__

#include <cstdio>

namespace Zlight
{
	class ZLogger
	{
	public:
		static ZLogger & getInstance(); //获取ZLogger实例
		void setEnable(bool isEnable);  //设置是否打印Log
		void Log(const char *logInfo);  //用Log来记录信息
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