#include <string>
#include <vector>

typedef void (*MenuFunctionPtr) (void);

struct MenuOption {
    std::string text;
    MenuFunctionPtr m_function;
};

class Menu {
    public:
        int currentSelection;
        std::vector<MenuOption> options;
        Menu(std::vector<MenuOption> ops);
        Menu();
        void draw(int width, int height);
        void up();
        void down();

};