#include <iostream>
#include <vector>
#include "Window.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void handle1() {
	std::cout << "test";
	return;
}

void handle2() {
	std::cout << "test2";
	return;
}

int main() {
	char inp;
	Window window(2,1,"Zerminal");
	Menu mainMenu(std::vector<MenuOption>({{"Test1", handle1}, {"Test2", handle2}}));
	window.setMenu(mainMenu);
	// window.listen()

	while (inp != 'q') {
		// switch(inp) {
		// 	case KEY_UP:

		// }

		window.draw();
		std::cin >> inp;
	}
	

	return 0;
}
