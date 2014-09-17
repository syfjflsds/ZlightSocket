#include "TCPClient.h"
#ifdef WIN32
#include <process.h>
#endif

using namespace Zlight;

TCPClient::TCPClient()
{
	init();
}

TCPClient::~TCPClient()
{

}

void TCPClient::init(const char *ipStr, int port)
{
	TCPSocket::init(CLIENT);
	m_isClientRun = true;
	if (connect(m_serverId, (sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) > -1)
		LOGGER.Log("connnect success");
	else
		LOGGER.Log("connect failed");
}

unsigned int __stdcall TCPClient::innerThreadCall(void *pm)
{
	TCPClient *client = (TCPClient *)pm;
	return client->threadcall();
}

void TCPClient::run()
{
#ifdef WIN32
	_beginthreadex(NULL, 0, &innerThreadCall, (void *)this, 0, 0);
#endif
}

unsigned int __stdcall TCPClient::threadcall()
{
	while (m_isClientRun)
	{
		threadFun(0);
	}
	return 0;
}

void TCPClient::threadFun(void *args)
{

}