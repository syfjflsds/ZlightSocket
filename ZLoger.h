/*********************************************************************************
*
*    ZLoger, ��Zlight Socket��Loger������ͨ��������������ӵ�����Ϣ
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
		static ZLogger & getInstance(); //��ȡZLoggerʵ��
		void setEnable(bool isEnable);  //�����Ƿ��ӡLog
		void Log(const char *logInfo);  //��Log����¼��Ϣ
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