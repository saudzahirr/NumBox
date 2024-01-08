#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <string>
#include <Windows.h>

using namespace std;

enum class LogLevel {
    TRACE_MSG,
    DEBUG_MSG,
    INFO_MSG,
    WARNING_MSG,
    ERROR_MSG,
    CRTITCAL_MSG,
    PRINT_MSG,
    TEST_PASSED_MSG,
};

void LOGGER(LogLevel level, string& message);

void TRACE_OUT(const string& message);
void DEBUG_OUT(const string& message);
void INFO_OUT(const string& message);
void WARNING_OUT(const string& message);
void ERROR_OUT(const string& message);
void CRTITCAL_OUT(const string& message);
void PRINT(const string& message);
void TEST_PASSED(const string& message);

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
    GRAY = FOREGROUND_INTENSITY,
    DEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

void setColor(ConsoleColor color);

string formatPrecision(double value);

void sleep(int seconds);

#endif // LOGGER_H
