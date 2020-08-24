#include <string>

class Window {
    public:
        int rows, cols, offsetX, offsetY;
        std::string title;
        Window(int paddingX, int paddingY, std::string titleInput);
        void draw();
};