#pragma once

#include "core.h"

class server
{
	SOCKET sock;
	int af;
	int type;
	int protocol;
public:
	server(int m_af, int m_type, int m_protocol): af(m_af), type(m_type), protocol(m_protocol)
	{
		if ((sock = socket(af, type, protocol)) == INVALID_SOCKET)
		{
			std::cout << "Could not create socket : " << WSAGetLastError() << std::endl;
		}

		std::cout << "Server socket created." << std::endl;
	}
	~server()
	{
		closesocket(sock);
		std::cout << "Server socket closed." << std::endl;
	}

	int serv_connect(unsigned long ip_addr, unsigned short port);
	void serv_listen(int max_conn);
};

