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

string executeCommand(const char* cmd) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

string getGPPVersion() {
    return executeCommand("g++ --version");
}

string getCMakeVersion() {
    return executeCommand("cmake --version");
}

int getOMPMaxThreads() {
    return thread::hardware_concurrency();
}

void logSystemInfoOnce() {
    static bool systemInfoLogged = false;
    if (!systemInfoLogged) {
        string FDM_template =
            "/*--------------------------------*- C++ -*----------------------------------*\\\n"
            "|   _         _             |                                                 |\n"
            "|  | * * 0 0 0 |            | OpenFDM: Numerical Methods Toolbox              |\n"
            "|  | * * * 0 0 | F inite    | Version:  v2023                                 |\n"
            "|  | 0 * * * 0 | D iscrete  |                                                 |\n"
            "|  | 0 0 * * * | M atrix    |                                                 |\n"
            "|  |_0 0 0 * *_|            |                                                 |\n"
            "|                           |                                                 |\n"
            "\\*---------------------------------------------------------------------------*/\n\n";

        ofstream logFile("NumBox.log", ios::app);
        if (logFile.is_open()) {
            logFile << FDM_template;
            logFile.close();
        }

        string systemInfo = "CMake Version: " + getCMakeVersion() + "\n" +
                            + "G++ Version: " + getGPPVersion() + "\n" +
                            + "OMP max threads: " + to_string(getOMPMaxThreads());

        logFile.open("NumBox.log", ios::app);
        if (logFile.is_open()) {
            logFile << "System Information:\n" << systemInfo << "\n\n";
            logFile.close();
        }

        systemInfoLogged = true;
    }
}



void LOGGER(LogLevel level, const string& message) {
    logSystemInfoOnce();

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
