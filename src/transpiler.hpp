#ifndef TRANSPILER_HPP
#define TRANSPILER_HPP
#include <fstream>
#include <vector>
#include <regex>
#include "event.hpp"
#include "token.hpp"
namespace MGML {
    class Transpiler {
    public:
        Transpiler();
        ~Transpiler();
        Event* GetEvent() const;
        void InitializeEvent();
        void Tokenize(const std::string code);

        void Execute(std::string inputPath, std::string outputPath);
        static Event* event[Events::SIZE];

        std::regex commentRegex;
        std::regex incrementRegex;
        std::regex decrementRegex;
        //std::regex types("\\b(function)\\b");

    private:
        std::string m_filePath;
        std::vector<Token> tokens;
    };
}
#endif // TRANSPILER_HPP