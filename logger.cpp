#include "Logger.h"

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


void log(LogLevel level, const string& message) {
    string levelStr;
    ConsoleColor levelColor;

    switch (level) {
        case LogLevel::INFO:
            levelStr = "INFO";
            levelColor = ConsoleColor::GREEN;
            break;
        case LogLevel::WARNING:
            levelStr = "WARNING";
            levelColor = ConsoleColor::YELLOW;
            break;
        case LogLevel::ERROR_MSG:
            levelStr = "ERROR";
            levelColor = ConsoleColor::RED;
            break;
        case LogLevel::DEBUG:
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

    // Set color for the level string
    setColor(levelColor);

    // Flush to console
    cout << logMessage << endl;

    // Reset color
    setColor(ConsoleColor::DEFAULT);
}

void info(const string& message) {
    log(LogLevel::INFO, message);
}

void debug(const string& message) {
    log(LogLevel::DEBUG, message);
}

void warning(const string& message) {
    log(LogLevel::WARNING, message);
}

void error(const string& message) {
    log(LogLevel::ERROR_MSG, message);
}


// int main() {
//     info("This is an informational message.");
//     warning("This is a warning message.");
//     error("This is an error message.");
//     debug("This is a debug message.");

//     return 0;
// }