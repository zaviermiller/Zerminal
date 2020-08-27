#include <string>
#include <iostream>
#include <array>
#include "menu.h"
#include "draw_helpers.h"

namespace zerminal {
    Menu::Menu(std::vector<MenuOption> ops, std::vector<std::string> styles) {
        options = ops;
        currentSelection = 0;
        activeStyles = styles;
    }

    Menu::Menu() {
        return;
    }

    void Menu::draw(int width, int height) {
        for (int i = 0; i < options.size(); i++) {
            MenuOption currentOption = options.at(i);
            goto(width / 2 - ((currentOption.text.length() + 3) / 2), 10 + i);
            if (i == currentSelection) {
                for(std::string x : activeStyles) {
                    printf(x.c_str());
                }
            }
            printf((" " + std::to_string(i + 1) + ". " + currentOption.text + " ").c_str());
            reset();
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

    void Menu::executeActiveFunc() {
        MenuOption currentOption = options.at(currentSelection);
        currentOption.m_function();
    }
}