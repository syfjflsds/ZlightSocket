#include "TCPServer.h"
#ifdef WIN32
#include <process.h>
#else

#endif

using namespace Zlight;


TCPServer::TCPServer()
{
	init();
}

TCPServer::~TCPServer()
{

}

void TCPServer::init(const char *ipStr, int port)
{
	m_sockIdVec.clear();
	TCPSocket::init(SERVER, ipStr, port);
	listen(m_serverId, 5);
	m_isServerRun = true;
}

void TCPServer::run()
{
	int len = sizeof(m_clientAddr);
	while (m_isServerRun)
	{
#ifdef WIN32
		SOCKET clientId = accept(m_serverId, (sockaddr *)&m_clientAddr, &len);
#else
      int clientId = accept(m_serverId, (sockaddr *)&m_clientAddr, (socklen_t *)&len);
#endif
		//m_sockIdVec.push_back(clientId);
#ifdef WIN32
		_beginthreadex(NULL, 0, &threadFun, (void *)&clientId, 0, 0);
#endif
	}
}