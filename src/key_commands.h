#include <map>

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 67
#define KEY_RIGHT 68

namespace zerminal {
    typedef void (*KeyFunc)(void);

    class KeyCommands {
        public:
            char quitKey;
            std::map<char, KeyFunc> keyCmds;

            KeyCommands(std::map<char, KeyFunc> keys, char quit = 'q');
    };
};