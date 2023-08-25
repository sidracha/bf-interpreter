#include <filesystem>
#include <fstream>
#include <iostream>

#include "interpreter.hpp"

namespace fs = std::filesystem;

int main (int argc, char* argv[]) {

	fs::path path = argv[1];
	size_t len = fs::file_size(path);
	
	std::ifstream file(path);
	
	char* code = new char[len];
	file.read(code, len);

	interpret(code, len);

	delete code;
	return 0;

}
