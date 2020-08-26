#include <string>
#include <vector>
#include "draw_helpers.h"

namespace zerminal {
    typedef void (*MenuFunctionPtr)(void);

    struct MenuOption {
        std::string text;
        MenuFunctionPtr m_function;
    };

    class Menu {
        public:
            int currentSelection;
            std::vector<std::string> activeStyles;
            std::vector<MenuOption> options;
            Menu(std::vector<MenuOption> ops, std::vector<std::string> styles = {"\033[7m", "\033[1m"});
            Menu();
            void draw(int width, int height);
            void up();
            void down();
            void executeActiveFunc();

    };
};