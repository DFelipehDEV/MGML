#include "log.hpp"
#include <iostream>
#include <chrono>

namespace MGML {
    void Log::PrintLine(const std::string& line, int type) {
        std::time_t time = std::time(NULL);
        tm *localTime = localtime(&time);
        switch (type) {
            case LogType::INFO:
                std::cout << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << " [INFO] " << line << std::endl;
                break;

            case LogType::ERROR:
                std::cout << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << " \x1B[31m[ERROR] " << line << "\x1B[0m" << std::endl;
                break;
            
            case LogType::WARNING:
                std::cout << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << " \x1B[33m[WARN] " << line << "\x1B[0m" << std::endl;
                break;
        }
    }
}
