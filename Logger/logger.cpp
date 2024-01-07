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

string formatPrecision(double value) {
    ostringstream oss;
    oss << fixed << setprecision(8) << value;
    return oss.str();
}

void sleep(int seconds) {
    time_t startTime = time(nullptr);
    time_t targetTime = startTime + seconds;

    while (time(nullptr) < targetTime);
}

void LOGGER(LogLevel level, const string& message) {
    string levelStr;
    ConsoleColor levelColor;

    switch (level) {
        case LogLevel::TRACE_MSG:
            levelStr = "TRACE";
            levelColor = ConsoleColor::GRAY;
            break;
        case LogLevel::DEBUG_MSG:
            levelStr = "DEBUG";
            levelColor = ConsoleColor::MAGENTA;
            break;
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
        case LogLevel::CRTITCAL_MSG:
            levelStr = "CRITICAL";
            levelColor = ConsoleColor::CYAN;
            break;
        case LogLevel::PRINT_MSG:
            levelStr = "INFO";
            levelColor = ConsoleColor::BLUE;
            break;
        case LogLevel::TEST_PASSED_MSG:
            levelStr = "INFO";
            levelColor = ConsoleColor::GREEN;
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
        throw runtime_error(logMessage);
    }
    
    else {
        cout << logMessage << endl;
    }

    setColor(ConsoleColor::DEFAULT);
}


void TRACE_OUT(const string& message) {
    LOGGER(LogLevel::TRACE_MSG, message);
}

// Messages that contain information normally of use only when debugging a program.
void DEBUG_OUT(const string& message) {
    LOGGER(LogLevel::DEBUG_MSG, message);
}

// Confirmation that the program is working as expected.
void INFO_OUT(const string& message) {
    LOGGER(LogLevel::INFO_MSG, message);
}

void WARNING_OUT(const string& message) {
    LOGGER(LogLevel::WARNING_MSG, message);
}

void ERROR_OUT(const string& message) {
    LOGGER(LogLevel::ERROR_MSG, message);
}

// Hard device errors.
void CRTITCAL_OUT(const string& message) {
    LOGGER(LogLevel::CRTITCAL_MSG, message);
}

void PRINT(const string& message) {
    LOGGER(LogLevel::PRINT_MSG, message);
}

void TEST_PASSED(const string& message) {
    LOGGER(LogLevel::TEST_PASSED_MSG, message);
}
