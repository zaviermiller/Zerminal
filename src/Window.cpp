#include <iostream>
#include <string>
#include <termios.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO
#include "Window.h"
#include "draw_helpers.h"

namespace zerminal {
	struct termios orig;

	void disableRaw() {
		system("clear");
		
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
		printf("\e[?25h");
	}

	void enableRaw() {
		system("clear");

		printf("\e[?25l");

		tcgetattr(STDIN_FILENO, &orig);
		atexit(disableRaw);

		struct termios raw = orig;
		raw.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	}

	Window::Window(int paddingX = 0, int paddingY = 0, std::string titleInput = "") {
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		enableRaw();
		title = titleInput;
		tWidth = w.ws_col;
		tHeight = w.ws_row;
		rows = w.ws_row - (paddingY);
		cols = w.ws_col - (paddingX * 2);
		offsetX = paddingX;
		offsetY = paddingY;
	}
			
	void Window::draw() {
		// draw initial border
		for (int row = 1 + offsetY; row <= rows; ++row) {
			if (row != 1 + offsetY && row != rows) {
				goto(offsetX,row);
				printf("┃");
				goto(cols + offsetX, row);
				printf("┃");
			} else if (row == 1 + offsetY) {
				goto(offsetX,row);
				printf("┏");
				for (int col = 1 + offsetX; col < cols + offsetX; col++) {
					// quick check to not draw where title goes.
					if (col >= (cols + offsetX * 2) / 2 - (title.length() + 8) / 2 && col <= (cols + offsetX * 2) / 2 + (title.length() + 8) / 2) {
						continue;
					}
					goto(col, row);
					printf("━");
				}
				goto((cols + offsetX * 2) / 2 - (title.length() + 8) / 2, row);
				printf("    \033[1m%s\033[0m    ", title.c_str());
				goto(cols + offsetX, row);
				printf("┓");
			} else {
				goto(offsetX,row);
				printf("┗");
				for (int col = 1 + offsetX; col < cols + offsetX; col++) {
					goto(col, row);
					printf("━");
				}
				goto(cols + offsetX, row);
				printf("┛");
			}
		}

		// draw menu (if it exists)
		if (&menu != NULL) {
			menu.draw(tWidth, tHeight);
		}
	}

	void Window::setMenu(Menu newMenu) {
		menu = newMenu;
	}

	// void Window::showMenu() {

	// }
}