#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>

#include "constant.h"
#include "game.h"
#include "board.cpp"

// --- Private Methods ---
bool
Game::escape() {
	if (GetAsyncKeyState(VK_ESCAPE))
        return true;
    
    if (GetAsyncKeyState(VK_UP))
    	increase_speed();
    if (GetAsyncKeyState(VK_DOWN))
    	decrease_speed();
    
	return false;
}

std::string
Game::divider(char c) {
	std::string str = "";
	
	for (int i = 0; i < constant::WIDTH; i++)
		str += c;
	
	return str;
}

void
Game::reset() {
	this->board = Board(path);
	this->speed = 1.0f;
	this->counter_speed = 0;
}

void
Game::show_state() {
	const int ON_C = 178;
	const int OFF_C = 32;
	
	std::vector<std::vector<bool>> active = board.get_state();
	
	puts(divider('=').c_str());
	puts("Consway's Game of Life'");
	puts(divider('=').c_str());
	
	for (int i = 0; i < constant::HEIGHT; i++) {
		for (int j = 0; j < constant::WIDTH; j++)
			putchar(active[i][j] ? ON_C : OFF_C);
		putchar('\n');
	}
}

void
Game::show_status() {
	puts(divider('-').c_str());
	
	std::cout << std::left << std::setw(6) << "Path";
	std::cout << ": \"" << path << "\"" << std::endl;
	std::cout << std::left << std::setw(6) << "Speed";
	std::cout << ": " << speed << "x" << std::endl;
}


// --- Public Methods ---
Game::Game() {
	reset(constant::DEFAULT_PATH);
}

Game::Game(std::string path) {
	reset(path);
}

float
Game::get_speed() {
	return this->speed;
}

void
Game::decrease_speed() {
	if (counter_speed > constant::SPEED_LOWER_LIMIT) {
		speed /= constant::SPEED_CHANGE;
		counter_speed--;
	}
}

void
Game::increase_speed() {
	if (counter_speed < constant::SPEED_UPPER_LIMIT) {
		speed *= constant::SPEED_CHANGE;
		counter_speed++;
	}
}

void
Game::render() {
	show_state();
	show_status();
}

void
Game::reset(std::string path) {
	this->path = path;
	reset();
}

void
Game::run() {
	system("pause");
	
	while (!escape()) {
		system("cls");
		render();
		
		Sleep((1.0 / speed) * 1000);
		board.update();
	}
}

