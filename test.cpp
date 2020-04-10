#include <iostream>
#include "test.h"

Test::Test() { }

template<typename T> void
Test::printnumb(T numb) {
	std::cout << numb << std::endl;
}

void
Test::printstr(std::string s) {
	std::cout << s << std::endl;
}

