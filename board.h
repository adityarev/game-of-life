#ifndef BOARD_H
#define BOARD_H

class Board {
private:
	std::string path;
	std::vector<std::vector<bool>> state;

public:
	Board();
	Board(std::string);
	Board next();
	Board next(int);
	std::vector<std::vector<bool>> get_state();
	void reset(std::string);
	void update();

private:
	std::vector<std::vector<bool>> get_initial_state();
	void reset();
};

#endif // BOARD_H

