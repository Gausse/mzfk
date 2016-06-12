#include "server.h"

int server::serv_connect(unsigned long ip_addr, unsigned short port)
{
	struct sockaddr_in server;

	server.sin_addr.s_addr = ip_addr;
	server.sin_family = af;
	server.sin_port = port;

	if ( bind(sock, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR )
	{
		int ret_code = WSAGetLastError();
		std::cout << "Bind failed with error code : " << ret_code << std::endl;

		return ret_code;
	}

	return 0;
}