/*********************************************************************************
*
*    TCPSocket头文件，是TCPSocket接口的通用类
*
**********************************************************************************/



#ifndef _TCPSOCKET_H__

#define _TCPSOCKET_H__

#ifdef WIN32
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#include "ZLoger.h"


enum SocketKind
{
	SERVER,
	CLIENT,
};

namespace Zlight
{
	class TCPSocket 
	{
	public:
		TCPSocket();
		virtual ~TCPSocket();
		virtual void init(SocketKind kind, const char *ipStr = "127.0.0.1", int port = 9210);
		void release();
#ifdef WIN32:
    protected:
		SOCKET m_serverId;
		SOCKET m_clientId;
#else
    //public:
		int m_serverId;
        int m_clientId;
#endif
		sockaddr_in m_serverAddr;
		sockaddr_in m_clientAddr;
		//int m_clientAddrLen;
		SocketKind m_kind;

	};
}

#endif