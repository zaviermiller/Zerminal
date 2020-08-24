#include <string>
#include "Menu.h"

class Window {
    public:
        int rows, cols, offsetX, offsetY;
        Menu *menu = NULL;
        std::string title;
        Window(int paddingX, int paddingY, std::string titleInput);
        void draw();
        // void showMenu();
        void setMenu(Menu newMenu);
};