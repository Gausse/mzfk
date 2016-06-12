#include "core.h"

char ICQ_MODE;


#pragma comment(lib, "ws2_32.lib")


int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		std::cout << "WSAStartup failed with error: " << err << std::endl;
		return 1;
	}

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		std::cout << "Could not find a usable version of Winsock.dll" << std::endl;
		WSACleanup();
		return 1;
	}
	else
		std::cout << "The Winsock 2.2 dll was found okay" << std::endl;

	std::cout << "Choose this is (C)liet or (S)erver... ";
	std::cin >> ICQ_MODE;

	switch (ICQ_MODE)
	{
	case 'c':
	case 'C':
		std::cout << "You have choosed Client mode... Initialization..." << std::endl;
		
		break;
	case 's':
	case 'S':
		std::cout << "You have choosed Server mode... Initialization..." << std::endl;

		break;
	default:
		std::cout << "Wrong mode. Program is terminated." << std::endl;
		break;
	}

	WSACleanup();

	return 0;
}