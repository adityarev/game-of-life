#ifndef TEST_H
#define TEST_H

class Test {
public:
	Test();
	template<typename T> void printnumb(T);
	void printstr(std::string);
};

#endif // TEST_H

