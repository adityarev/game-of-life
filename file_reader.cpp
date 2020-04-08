#include <algorithm>
#include <cstdio>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>

#include "constant.h"
#include "file_reader.h"

// --- Private Methods ---
void
FileReader::open(std::string path) {
	printf("Opening file... ");
	f = fopen(path.c_str(), "r");
	if (!f) {
		puts("failed! Path changed to default");
		f = fopen((constant::DEFAULT_PATH).c_str(), "r");
	} else {
		puts("done");
	}
}

void
FileReader::read() {
	const int len = constant::WIDTH + 1;
	char str[len];
	
	std::vector<std::string> lines;
	
	while (!fgets(str, len, f)) {
		std::string line(str);
		lines.push_back(line);
	}
	
	this->lines = lines;
}

void
FileReader::close() {
	fclose(f);
}


// --- Public Methods ---
FileReader::FileReader() {
	read(constant::DEFAULT_PATH);
}

FileReader::FileReader(std::string path) {
	read(path);
}

void
FileReader::read(std::string path) {
	open(path);
	read();
	close();
}

std::vector<std::string>
FileReader::get_lines() {
	return this->lines;
}

std::vector<std::string>
FileReader::get_normalized_lines() {
	std::function<int()>
	get_max_len = [&]() -> int {
		int res = INT_MIN;
		for (std::string& line: lines)
			res = std::max(res, (int)line.length());
		return res;
	};
	
	int max_len = get_max_len();
	std::vector<std::string> normalized_lines;
	
	for (std::string& line: normalized_lines) {
		while ((int)line.length() < max_len)
			line += constant::DUMMY_C;
	}
	
	return normalized_lines;
}

