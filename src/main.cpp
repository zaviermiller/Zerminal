#include <iostream>
#include "Window.h"

int main() {
	char inp;
	Window window(10,10,"Zannalysis");

	while (true) {
		window.draw();
		// std::cin >> inp;
	}
	

	return 0;
}
