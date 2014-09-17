/*
**	
**	TCPClient
**
*/


#ifndef _TCPCLIENT_H__
#define _TCPCLIENT_H__

#include "TCPSocket.h"
#include "ZLoger.h"

namespace Zlight
{
	class TCPClient : public TCPSocket
	{
	public:
		TCPClient();
		~TCPClient();
		virtual void run();
	protected:
		virtual void init(const char *ipStr = "127.0.0.1", int port = 9210);
		bool m_isClientRun;
		
		//virtual void setThreadFun(unsigned int(*fun)());
		virtual void threadFun(void *args);
	private:
		static unsigned int __stdcall innerThreadCall(void *pm);
	private:
		unsigned int __stdcall threadcall();
	};
}

#endif