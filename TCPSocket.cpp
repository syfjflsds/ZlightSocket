#include "TCPSocket.h"
#include "ZLoger.h"

using namespace Zlight;

TCPSocket::TCPSocket()
{
	//init();
	m_serverId = 0;
	m_clientId = 0;
}

TCPSocket::~TCPSocket()
{
	
}

void TCPSocket::init(SocketKind kind, const char *ipStr, int port)
{
#ifdef WIN32
	WSADATA wsaData;
	int ret;
	if ((ret = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
	{
		LOGGER.Log("WSAStart failed with error");
	}
	else
	{
		LOGGER.Log("WSAStart successful");
	}
#endif
	LOGGER.Log("init");
	m_kind = kind;
	if (m_kind == SERVER)
	{
		m_serverId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		m_serverAddr.sin_family = AF_INET;
		m_serverAddr.sin_port = htons(port);
		m_serverAddr.sin_addr.s_addr = inet_addr(ipStr);
		if ((ret = bind(m_serverId, (sockaddr *)&m_serverAddr, sizeof(m_serverAddr))) == -1)
		{
			LOGGER.Log("bind error");
		}
	}
	else
	{
		m_clientId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		m_serverAddr.sin_family = AF_INET;
		m_serverAddr.sin_port = htons(port);
		m_serverAddr.sin_addr.s_addr = inet_addr(ipStr);
	}
}

void TCPSocket::release()
{
	if (m_serverId)
	{
		closesocket(m_serverId);
		LOGGER.Log("Server ID has closed");
	}
	if (m_clientId)
	{
		closesocket(m_clientId);
		LOGGER.Log("Client ID has closed");
	}
#ifdef WIN32
	if (WSACleanup() == SOCKET_ERROR)
	{
		LOGGER.Log("WSACleanup failed with error");
	}
	else
	{
		LOGGER.Log("WSACleanup failed with error");
	}
#endif
}

/*void TCPSocket::bindAndInit(SocketKind kind, const char *ipStr, int port)// = "127.0.0.1"
{
	LOGGER.Log("bind And Init");
	m_serverId = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	m_kind = kind;
	if (m_kind == SERVER)
	{
		m_serverAddr.sin_family = AF_INET;
		m_serverAddr.sin_port = htons(port);
		m_serverAddr.sin_addr.s_addr = inet_addr(ipStr);
		bind(m_serverId, (sockaddr *)&m_serverAddr, sizeof(m_serverAddr));
	}
	else
	{

	}
}*/

void TCPSocket::action()
{
	/*listen(m_serverId, 5);
	while (true)
	{
		m_clientId = accept(m_serverId, (SOCKADDR *)&m_clientAddr, &m_clientAddrLen);
	}*/
}