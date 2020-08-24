#define goto(x,y) printf("\033[%d;%dH", (y), (x))

#define highlight() printf("\033[7m")
#define bold() printf("\033[1m")

#define red() printf("\033[31m")
#define green() printf("\033[32m")
#define purple() printf("\033[35m")

#define reset_text() printf("\033[0m")