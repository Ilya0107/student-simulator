#include "color.h"

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(ConsoleColor textColor, ConsoleColor bgColor) {
    int attr = textColor + (bgColor * 16);
    SetConsoleTextAttribute(hConsole, attr);
}

void resetColor() {
    setColor(LIGHT_GRAY, BLACK);  // стандартный вид
}