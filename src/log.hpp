#ifndef LOG_HPP
#define LOG_HPP
#include <string>
namespace MGML {
    class Log {
    public:
        static void PrintLine(const std::string& line, int type = 0);
    };

    enum LogType {
        INFO = 0,
        ERROR,
        WARNING,
    };
}
#endif // LOG_HPP