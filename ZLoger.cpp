#include "ZLoger.h"
#include <cstdio>

using namespace Zlight;
using namespace std;

ZLogger * ZLogger::m_zloger = NULL;

ZLogger::ZLogger()
{

}


ZLogger &ZLogger::getInstance()
{
	if (m_zloger)
	{
		return *m_zloger;
	}
	else
	{
		m_zloger = new ZLogger();
		m_zloger->m_enable = true;
#ifdef WIN32
		fopen_s(&(m_zloger->m_fp), "ZLogger.log", "w");
#else
        fopen("ZLogger.log", "w");
#endif
		return *m_zloger;
	}
}


ZLogger::~ZLogger()
{
	fclose(m_fp);
	m_fp = NULL;
}

void ZLogger::Log(const char *info)
{
	if (m_enable)
	{
		if (m_fp)
		{
			fprintf(m_fp, "%s\n",  info);
			fflush(m_fp);
		}
		printf("%s\n", info);
	}
}

void ZLogger::setEnable(bool isEnable)
{
	m_enable = isEnable;
}