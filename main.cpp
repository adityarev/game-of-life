#include <cstdio>
#include <iostream>
#include <vector>
#include <windows.h>

#include "constant.h"
#include "game.cpp"

int
main() {
	Game game(constant::GLIDER_GUN_PATH);
	game.run();
	
	return 0;
}

