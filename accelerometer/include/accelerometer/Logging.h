#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "accelerometer/History.h"
#include <cmath>

// Color codes for different log levels
// Define color codes
namespace colors{
const std::string INFO = "\033[94m";    // Blue
const std::string WARNING = "\033[93m"; // Yellow
const std::string ERROR = "\033[91m";   // Red
const std::string RESET = "\033[0m";    // Reset to default color
const std::string PLAIN = "\033[0m";    // Reset to default color
}

struct AccelerometersboundaryesValues {
    unsigned int maxConsecutiveHigh = 3;
    float alertThreshold = 0.2f;
};

#include <cmath> // For std::abs


class AccStatistics {
public:
    inline void incrementInvalidParsed() {
        ++InvalidParsed;
    }

    inline void incrementInvalidChecksum() {
        ++InvalidChecksum;
    }

    void updateMaxX(const float& value) {
        if (value > MaxX) {
            MaxX = value;
        }
    }

    void updateMaxY(const float& value) {
        if (value > MaxY) {
            MaxY = value;
        }
    }

    void updateMaxZ(const float& value) {
        if (value > MaxZ) {
            MaxZ = value;
        }
    }

    inline void incrementNumberOfAlerts() {
        ++NumberOfAlerts;
    }

    inline float getMaxX() const {
        return MaxX;
    }

    inline float getMaxY() const {
        return MaxY;
    }

    inline float getMaxZ() const {
        return MaxZ;
    }

    int InvalidParsed{ 0 };
    int InvalidChecksum{ 0 };
    float MaxX{ 0.0f };
    float MaxY{ 0.0f };
    float MaxZ{ 0.0f };
    int NumberOfAlerts{ 0 };
};


enum Level {
    INFO,
    WARNING,
    ERROR,
    PLAIN,
};

class Logger {
public:

    Logger() : mHistory(), mLogTime(false), mLogLevel(false) {}
    void log(Level level, const std::string& message,bool show, bool SaveToHistory);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
    void plain(const std::string& message);
    void logtime(bool show, bool SaveToHistory);

    inline History GetHistory() { return mHistory; };
    inline void SetLogLevel(const bool& aLogLevel) { mLogLevel = aLogLevel; };
    inline void SetLogTime(const bool& aLogTime) {mLogTime = aLogTime; }
    std::string getCurrentTime() const;

private:

    bool mLogTime;
    bool mLogLevel;
    History mHistory;
    bool mLogInfo = false; // do not show info
    bool mLogWarning = true;
    bool mLogError = false;  // do not show errors
    bool mLogPlain = true;
};

class AccLogger : public Logger {
public:
    // Extended LogLevel enum
    enum class ExtendedLogLevel {
        XYZACCLOG
    };

    // Additional methods specific to AccLogger
    void Acceleration(const float& X, const float& Y, const float& Z);
    inline void SetGravityCompensation(bool aGravityCompensation) { mGravityCompensation = aGravityCompensation; };
    void ShowStatistics();

    inline void SetAlert(const bool& aAlert) { mAlert = aAlert; };
    
    AccStatistics stats;

private:
    unsigned int consecutiveHighCount;
    const AccelerometersboundaryesValues boundaries;
    bool mAlert;
    bool mGravityCompensation;

};


#endif // LOGGER_H
