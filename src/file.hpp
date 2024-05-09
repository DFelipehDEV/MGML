#ifndef FILE_HPP
#define FILE_HPP
#include <istream>
#include <ostream>
namespace MGML {
    struct InputFile {
        std::ifstream* file;
        std::string path;
    };

    struct OutputFile {
        std::ofstream* file;
        std::string path;
    };
}
#endif // FILE_HPP