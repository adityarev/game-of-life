#ifndef FILE_READER_H
#define FILE_READER_H

class FileReader {
private:
	FILE* f;
	std::vector<std::string> lines;

public:
	FileReader();
	FileReader(std::string);
	void read(std::string);
	std::vector<std::string> get_lines();
	std::vector<std::string> get_normalized_lines();

private:
	void open(std::string);
	void read();
	void close();
};

#endif // FILE_READER_H

