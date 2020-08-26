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
	zerminal::Window window(10, 2,"Zannalysis");
	zerminal::Menu mainMenu(std::vector<zerminal::MenuOption>({{"Check inventory", handle1}, {"Check balance  ", handle2}, {"Settings       ", handle2}}));
	window.setMenu(mainMenu);
	// KeyCommands kc(std::vector<KeyFunc>({'a', handle1}), 'p');
	// window.
	// window.showHints()

	while (c != 'q') {
		if (c == 27) {
			std::cin >> d;
			if (d == 91) {
				std::cin >> e;
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
			}
		} else if (c == '\n') {
			window.menu.executeActiveFunc();
		} else {
			std::cout << c;
		}

		window.draw();
		c = getchar();
	}
	

	return 0;
}
