#include "logger.h"

using namespace std;

string getCurrentTime() {
    time_t rawTime;
    struct tm* timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeInfo);

    return buffer;
}

inline void setColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
}


void LOGGER(LogLevel level, const string& message) {
    string levelStr;
    ConsoleColor levelColor;

    switch (level) {
        case LogLevel::INFO_MSG:
            levelStr = "INFO";
            levelColor = ConsoleColor::WHITE;
            break;
        case LogLevel::WARNING_MSG:
            levelStr = "WARNING";
            levelColor = ConsoleColor::YELLOW;
            break;
        case LogLevel::ERROR_MSG:
            levelStr = "ERROR";
            levelColor = ConsoleColor::RED;
            break;
        case LogLevel::DEBUG_MSG:
            levelStr = "DEBUG";
            levelColor = ConsoleColor::MAGENTA;
            break;
    }

    string logMessage = getCurrentTime() + ": " + levelStr + ": - " + message;

    // Write to log file
    ofstream logFile("NumBox.log", ios::app);
    if (logFile.is_open()) {
        logFile << logMessage << endl;
        logFile.close();
    }

    setColor(levelColor);

    if (levelStr == "ERROR") {
        cerr << logMessage << endl;
    }
    
    else {
        cout << logMessage << endl;
    }

    setColor(ConsoleColor::DEFAULT);
}

void INFO_OUT(const string& message) {
    LOGGER(LogLevel::INFO_MSG, message);
}

void DEBUG_OUT(const string& message) {
    LOGGER(LogLevel::DEBUG_MSG, message);
}

void WARNING_OUT(const string& message) {
    LOGGER(LogLevel::WARNING_MSG, message);
}

void ERROR_OUT(const string& message) {
    LOGGER(LogLevel::ERROR_MSG, message);
}
