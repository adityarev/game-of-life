#include <iostream>
#include "test.h"

template<typename T> void
Test::printnumb(T numb) {
	std::cout << numb << std::endl;
}

void
Test::printstr(std::string s) {
	std::cout << s << std::endl;
}

