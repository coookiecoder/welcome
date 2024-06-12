#include <iostream>
#include <fstream>
#include <string>

void git_clone(std::string line) {
	std::string repo;
	std::string folder_name;
	std::string command;

	int cursor = 0;

	while (line[cursor] != ' ') {
		repo += line[cursor++];
	}

	cursor++;

	while (line[cursor]) {
		folder_name += line[cursor++];
	}

	command = "git clone http://github.com/coookiecoder/" + repo + " " + folder_name;

	system(command.c_str());
}

void purge_folder(std::string line) {
	std::string folder;
	std::string command;

	command = "rm -rf " + folder;

	system(command.c_str());
}

void do_instruction(std::string instruction) {
	std::string first_bloc;

	for (int cursor = 0; instruction[cursor] != ' '; cursor++) {
		first_bloc += instruction[cursor];
	}

	if (first_bloc == "clone")
		git_clone(instruction.c_str() + 6);
	else if (first_bloc == "purge")
		purge_folder(instruction.c_str() + 6);
}

int main(void) {
	std::cout << "Welcome" << std::endl;

	std::fstream instruction_file("/home/abareux/.config/file.welcome");

	if (instruction_file.fail()) {
		std::cerr << "no file found" << std::endl;
		return (1);
	}

	std::string instruction;

	while (std::getline(instruction_file, instruction)) {
		do_instruction(instruction);
	}

	instruction_file.close();
}
