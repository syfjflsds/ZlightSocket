/*******************************************************************
**	
**	The TCP Server head file.
**	It provides a TCPServer class
**
*******************************************************************/



#ifndef _TCPSERVER_H__
#define _TCPSERVER_H__


#include "TCPSocket.h"
#include "ZLoger.h"
#include <vector>

namespace Zlight
{
	class TCPServer : public TCPSocket
	{
	public:
		TCPServer();
		virtual ~TCPServer();
		virtual void run();
	protected:
		virtual void init(const char *ipStr = "127.0.0.1", int port = 9210);
		std::vector<SOCKET> m_sockIdVec;
		bool m_isServerRun;
		friend unsigned int __stdcall threadFun(void * pm)
		{
			LOGGER.Log("Thread func begin");
			char buf[1024];
			memset(buf, 0, sizeof(buf));
		#ifdef WIN32
			sprintf_s(buf, "Welcome to server");
			SOCKET clientId = *(SOCKET *)pm;
		#else
			sprintf(buf, "Welcome to server");
			int clientId = *(int *)pm;
		#endif
			send(clientId, buf, strlen(buf) + 1, 0);
			//m_sockIdVec
			LOGGER.Log("Thread func end");
			return 0;
		}
	};
}
#endif