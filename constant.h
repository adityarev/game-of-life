#ifndef CONSTANT_H
#define CONSTANT_H

namespace constant {
	const int HEIGHT = 25;
	const int WIDTH = 50;
	const int MARGIN = 3;
	
	const float SPEED_CHANGE = 2.0;
	const int SPEED_UPPER_LIMIT = 1;
	const int SPEED_LOWER_LIMIT = -2;
	
	const char DUMMY_C = '.';
	const char SELECTED_C = '*';
	
	const std::string PATTERN_PATH = "./patterns";
	const std::string DEFAULT_PATH = PATTERN_PATH + "/default.txt";
	const std::string GLIDER_PATH = PATTERN_PATH + "/glider.txt";
	const std::string GLIDER_GUN_PATH = PATTERN_PATH + "/glider_gun.txt";
}

#endif // CONSTANT_H

