#include <string>
#include "menu.h"
#include "key_commands.h"

namespace zerminal {
    class Window {
        public:
            int rows, cols, offsetX, offsetY, tWidth, tHeight;
            Menu menu;
            std::string title;
            Window(int paddingX, int paddingY, std::string titleInput);
            void draw();
            // void showMenu();
            void setMenu(Menu newMenu);
            void listen(KeyCommands kc);
    };
};