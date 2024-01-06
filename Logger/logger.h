#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

enum class LogLevel {
    INFO_MSG,
    DEBUG_MSG,
    WARNING_MSG,
    ERROR_MSG,
};

void LOGGER(LogLevel level, string& message);

void INFO_OUT(const string& message);
void DEBUG_OUT(const string& message);
void WARNING_OUT(const string& message);
void ERROR_OUT(const string& message);

// Console display
enum ConsoleColor {
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    GREEN = FOREGROUND_GREEN,
    CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED = FOREGROUND_RED,
    MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    DEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

void setColor(ConsoleColor color);

#endif // LOGGER_H
