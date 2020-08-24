#include <iostream>
#include <vector>
#include "../Zerminal.h"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 67
#define KEY_RIGHT 68

void handle1() {
	std::cout << "test";
	return;
}

void handle2() {
	std::cout << "test2";
	return;
}

int main() {
	char c,d,e;
	Window window(40, 6,"Bank of Z");
	Menu mainMenu(std::vector<MenuOption>({{"Withdrawal     ", handle1}, {"Check balance  ", handle2}, {"Settings       ", handle2}}));
	window.setMenu(mainMenu);
	// window.showMenu()

	while (c != 'q') {
		if ((c == 27) && (d == 91)) {
			switch(e) {
				case KEY_UP:
					window.menu.up();
					break;
				case KEY_DOWN:
					window.menu.down();
					break;
				default:
					std::cout << std::to_string(e);
			}
		} else {
		}

		window.draw();
		std::cin >> c;
		std::cin >> d;
		std::cin >> e;
	}
	

	return 0;
}
