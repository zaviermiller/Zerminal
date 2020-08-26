namespace zerminal {
    #define goto(x,y) printf("\033[%d;%dH", (y), (x))

    #define highlight() printf("\033[7m")
    #define bold() printf("\033[1m")

    // Functions to print
    #define black() printf("\033[30m")
    #define red() printf("\033[31m")
    #define green() printf("\033[32m")
    #define yellow() printf("\033[33m")
    #define blue() printf("\033[34m")
    #define purple() printf("\033[35m")
    #define cyan() printf("\033[36m")
    #define white() printf("\033[37m")

    #define reset() printf("\033[0m")
};