#include <algorithm>
#include <climits>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

#include "board.h"
#include "constant.h"
#include "file_reader.cpp"

const int ROW = constant::HEIGHT + 3;
const int COL = constant::WIDTH + 3;

// --- Private Methods ---
std::vector<std::vector<bool>>
Board::get_initial_board() {
	return std::vector<std::vector<bool>>(
		ROW,
		std::vector<bool>(COL, false)
	);
}

void
Board::reset() {
	FileReader fr(path);
	std::vector<std::string> lines = fr.get_normalized_lines();
	
	board = get_initial_board();
	
	for (int i = 0; i < (int)lines.size(); i++)
		for (int j = 0; j < (int)lines[i].size(); j++)
			board[i][j] = (lines[i][j] == constant::SELECTED_C);
}


// --- Public Methods ---
Board::Board(): path(constant::DEFAULT_PATH) {
	reset();
}

Board::Board(std::string path): path(path) {
	reset();
}

Board
Board::next() {
	return next(1);
}

Board
Board::next(int n) {
	Board b = *this;
	
	for (int i = 0; i < n; i++)
		b.update();
	
	return b;
}

std::vector<std::vector<bool>>
Board::get_board() {
	return this->board;
}

void
Board::reset(std::string path) {
	this->path = path;
	reset();
}

void
Board::update() {
	static std::vector<int> xxs = {-1, 0, 1};
	static std::vector<int> yys = {-1, 0, 1};
	
	std::function<bool(int,int,int)>
	is_in_range = [&](int val, int l, int r) -> bool {
		return (l <= val && val <= r);
	}; 
	
	std::function<int(int,int)>
	count_degree = [&](int i, int j) -> int {
		int counter = 0;
		
		for (int& xx: xxs) {
			for (int& yy: yys) {
				int x = i + xx;
				int y = j + yy;
				
				if (x == i && y == j)
					continue;
				
				if (
					is_in_range(x, 0, ROW - 1)
					&& is_in_range(y, 0, COL - 1)
					&& board[x][y]
				) {
					counter++;
				}
			}
		}
		
		return counter;
	};
	
	std::vector<std::vector<bool>> updated_board = get_initial_board();
	
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++) {
			bool active = board[i][j];
			int degree = count_degree(i, j);
			
			if (active && is_in_range(degree, 2, 3))
				updated_board[i][j] = true;
			if (!active && degree == 3)
				updated_board[i][j] = true;
		}
	
	// Update board
	this->board = updated_board;
}

