#include <iostream>
#include <vector>
#include <map>
#include "zerminal.h"

void handle1() {
	std::cout << "test1";
	return;
}

void handle2() {
	std::cout << "test2";
	return;
}

int main() {
	zerminal::Window window(10, 2,"Zannalysis");
	zerminal::Menu mainMenu(std::vector<zerminal::MenuOption>({{"Check inventory", handle1}, {"Check balance  ", handle2}, {"Settings       ", handle2}}));
	window.setMenu(mainMenu);
	zerminal::KeyCommands kc(std::map<char, zerminal::KeyFunc> {{'a', handle1}}, 'p');
	// window.showHints()
	window.listen(kc);

	return 0;
}
