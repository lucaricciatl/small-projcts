#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
#include <memory>
#include <ctime>
#include "accelerometer/Logging.h"


static constexpr float COMPENSATION_VALUE = 1.0f;

struct LogParam {
    std::string color;
    std::string levelStr;
};

LogParam GetLogParam(Level level) {
    std::string color;
    std::string levelStr;
    switch (level) {
    case INFO:
        color = colors::INFO;
        levelStr = "INFO";
        break;
    case WARNING:
        color = colors::WARNING;
        levelStr = "WARNING";
        break;
    case ERROR:
        color = colors::ERROR;
        levelStr = "ERROR";
        break;
    case PLAIN:
        color = colors::PLAIN;
        levelStr = "INFO";
        break;
    }
    LogParam log_parameters;
    log_parameters.levelStr = levelStr;
    log_parameters.color = color;
    return log_parameters;
};

namespace {
    std::string formatDouble(double value, int precision = 2) {
        std::ostringstream out;
        out << std::fixed << std::setprecision(precision) << value;
        return out.str();
    }
}
void Logger::log(Level level, const std::string& message, bool show, bool SaveToHistory) {
    LogParam log_parameters = GetLogParam(level);
        log_parameters.levelStr = log_parameters.levelStr + " - ";
    if (SaveToHistory) { mHistory.addString(getCurrentTime() + " - " + log_parameters.levelStr + message); };
    std::string timestr = "";
    if (mLogTime) { timestr = getCurrentTime() + " - "; };
    if (!mLogLevel) { log_parameters.levelStr = ""; };
    if (show) {
        const std::string assembledstring = timestr + log_parameters.levelStr + message;
        std::cout << log_parameters.color << assembledstring << colors::RESET << std::endl;
        std::cout.flush();
    }
}

void Logger::logtime(bool show, bool SaveToHistory) {
    std::string time = getCurrentTime();
    log(PLAIN, time, show, SaveToHistory);
}
void Logger::info(const std::string& message) {
    log(INFO, message, mLogInfo, true);
}
void Logger::warning(const std::string& message) {
    log(WARNING, message, mLogWarning, true);
}
void Logger::error(const std::string& message) {
    log(ERROR, message , mLogError, true);
}
void Logger::plain(const std::string& message) {
    log(PLAIN, message, mLogPlain, true);
}




void AccLogger::Acceleration(const float& X, const float& Y, const float& Z) {
    const std::string x = formatDouble(X);
    const std::string y = formatDouble(Y);
    std::string z = formatDouble(Z);

    stats.updateMaxX(X);
    stats.updateMaxY(Y);
    stats.updateMaxZ(Z);

    if (std::abs(Y) > boundaries.alertThreshold) {
        consecutiveHighCount++;
    }
    else {
        consecutiveHighCount = 0; // Reset count if condition is not met
    }
    if (mGravityCompensation) {
        std::string logstring = "X = " + x + "\t, Y = " + y + "\t, Z = " + z;
        z = formatDouble(Z - COMPENSATION_VALUE);
        // Check if the absolute value of Y is greater than the threshold
        std::string HistoryString = "X = " + x + "\t, Y = " + y + "\t, Z = " + z;
        // Append [ALERT] if the condition has been met for the required number of messages
        if (consecutiveHighCount >= boundaries.maxConsecutiveHigh) {
            HistoryString += " [ALERT]";
            logstring += " [ALERT]";
            consecutiveHighCount = 0; // Reset after adding the alert
            log(WARNING, logstring, true, false); //log
            log(WARNING, HistoryString, false, true); //save to history, do not log
            stats.incrementNumberOfAlerts();
        }
        else {
            log(PLAIN, logstring, true, false); //log
            log(PLAIN, HistoryString, false, true); //save to history, do not log}
        }
    }
    else{
        std::string logstring = "X = " + x + "\t, Y = " + y + "\t, Z = " + z;
        z = Z - COMPENSATION_VALUE;
        log(PLAIN, logstring, true, true); //log
        // Append [ALERT] if the condition has been met for the required number of messages
        if (consecutiveHighCount >= boundaries.maxConsecutiveHigh) {
            logstring += " [ALERT]";
            consecutiveHighCount = 0; // Reset after adding the alert
            log(WARNING, logstring, true, true);
            stats.incrementNumberOfAlerts();
        }
        else {
            log(PLAIN, logstring, true, true); //log
        }
    }
};

void AccLogger::ShowStatistics() {
    std::cout << "==============================\n";
    std::cout << "       ACCELEROMETER STATS      \n";
    std::cout << "==============================\n";
    std::cout << std::setw(20) << std::left << "Invalid Parsed:" << stats.InvalidParsed << "\n";
    std::cout << std::setw(20) << std::left << "Invalid Checksum:" << stats.InvalidChecksum << "\n";
    // Output stats with formatting
    
    std::cout << std::fixed << std::setprecision(2); // Set fixed-point notation and 2 decimal places
    std::cout << std::setw(20) << std::left << "Max X:" << stats.getMaxX() << "\n";
    std::cout << std::setw(20) << std::left << "Max Y:" << stats.getMaxY() << "\n";
    std::cout << std::setw(20) << std::left << "Max Z:" << stats.getMaxZ() << "\n";
    std::cout << std::setw(20) << std::left << "Number of Alerts:" << stats.NumberOfAlerts << "\n";
    std::cout << "==============================\n";
}

std::string Logger::getCurrentTime() const{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);
    std::ostringstream oss;
    oss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
