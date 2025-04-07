#pragma once
// Logger.h - Handles System Logging
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include <ctime>
#include <iostream>

class Logger {
private:
    static Logger* instance;
    static std::mutex mutex;
    std::ofstream logFile;
    Logger(); // Private constructor to prevent direct instantiation
    Logger(Logger& other) = delete;  //Done: deleted copy constructor
    Logger& operator=(Logger& other) = delete; //Done: deleted assing operator
    

public:
    static Logger* getInstance();
    void log(const std::string& message);
    ~Logger();
};

#endif // LOGGER_H