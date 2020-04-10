#include <cstdio>
#include <iostream>
#include <vector>
#include <windows.h>

#include "constant.h"
#include "board.cpp"

int
main() {
	Board board(constant::GLIDER_GUN_PATH);
	system("pause");
	
	const int ON_C = 169;
	const int OFF_C = 32;
	
	while (true) {
		system("cls");
		std::vector<std::vector<bool>> on = board.get_board();
	
		for (int i = 0; i < constant::HEIGHT; i++) {
			for (int j = 0; j < constant::WIDTH; j++) {
				if (on[i][j])
					putchar(ON_C);
				else
					putchar(OFF_C);
			}
			putchar('\n');
		}
		
		Sleep(100);
		board.update();
	}
	
	return 0;
}

