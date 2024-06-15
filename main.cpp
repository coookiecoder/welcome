#include <iostream>
#include <fstream>
#include <string>

void git_clone(std::string line) {
	std::string command;

	command = "git clone http://github.com/coookiecoder/" + line;

	system(command.c_str());
}

void purge_folder(std::string line) {
	std::string command;
	
	command = "rm -rf " + line;

	system(command.c_str());
}

void web_get(std::string line) {
	std::string command;
	
	command = "wget " + line;

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
	else if (first_bloc == "web get")
		web_get(instruction.c_str() + 7);
	else if (first_bloc == "custom")
		system(instruction.c_str() + 7);
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
