#ifndef BOARD_H
#define BOARD_H

class Board {
private:
	std::string path;
	std::vector<std::vector<bool>> board;

public:
	Board();
	Board(std::string);
	Board next();
	Board next(int);
	std::vector<std::vector<bool>> get_board();
	void reset(std::string);
	void update();

private:
	std::vector<std::vector<bool>> get_initial_board();
	void reset();
};

#endif // BOARD_H

