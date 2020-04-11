#include "board.h"

#ifndef GAME_H
#define GAME_H

class Game {
private:
	Board board;
	float speed;
	int counter_speed;
	std::string path;

public:
	Game();
	Game(std::string);
	float get_speed();
	void decrease_speed();
	void increase_speed();
	void render();
	void reset(std::string);
	void run();

private:
	bool escape();
	std::string divider(char);
	void reset();
	void show_state();
	void show_status();
};

#endif // GAME_H

