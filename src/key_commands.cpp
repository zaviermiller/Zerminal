#include "key_commands.h"
#include <map>

namespace zerminal {
    KeyCommands::KeyCommands(std::map<char, KeyFunc> keys, char quit) {
        quitKey = quit;
        keyCmds = keys;
    }
}