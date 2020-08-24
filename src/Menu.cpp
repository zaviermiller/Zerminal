#include <string>
#include <iostream>
#include <array>
#include "Menu.h"
#include "draw_helpers.h"

Menu::Menu(std::vector<MenuOption> ops) {
    options = ops;
    currentSelection = 0;
}

Menu::Menu() {
    return;
}

void Menu::draw(int width, int height) {
    for (int i = 0; i < options.size(); i++) {
        MenuOption currentOption = options.at(i);
        goto(width / 2 - ((currentOption.text.length() + 3) / 2), 10 + i);
        if (i == currentSelection) {
            highlight();
            bold();
        }
        printf((std::to_string(i + 1) + ". " + currentOption.text + " ").c_str());
        reset_text();
    }
}

void Menu::up() {
    if (currentSelection <= 0) {
        currentSelection = options.size() - 1;
    } else {
        currentSelection -= 1;
    }
}

void Menu::down() {
    if (currentSelection >= options.size() - 1) {
        currentSelection = 0;
    } else {
        currentSelection += 1;
    }
}