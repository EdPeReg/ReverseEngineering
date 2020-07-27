#include <iostream>
#include <filesystem>
#include <cctype>

int main() {
	std::filesystem::path cwd = std::filesystem::current_path();
	std::string path = static_cast<std::string>(cwd);

	int index{0};
	while(path.size() > index) {
		if(path.at(index) == '/') {
			path.at(index) = '$';
		}

		if(std::islower(path.at(index))) {
			path.at(index) -= 30;
		} else if(std::isupper(path.at(index))) {
			path.at(index) += 30;
		}

		index++;
	}

	std::cout << ":) --> " << path << '\n';
}
