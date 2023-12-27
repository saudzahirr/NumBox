#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

enum class LogLevel {
    INFO,
    WARNING,
    ERROR_MSG,
    DEBUG
};

void log(LogLevel level, string& message);

void info(const string& message);
void debug(const string& message);
void warning(const string& message);
void error(const string& message);

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
