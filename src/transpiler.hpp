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
        ~Transpiler() = default;
        Event* GetEvent() const;
        void InitializeEvent();
        void Format(std::string& code) const;
        int Tokenize(const std::string code);
        int FormatAndTokenize(std::string code);

        void Compile(const std::string& inputPath, const std::string& outputPath);
        static Event* event[Events::SIZE];

        const std::regex commentRegex;
        const std::regex incrementRegex;
        const std::regex decrementRegex;
        //std::regex types("\\b(function)\\b");

    private:
        std::vector<Token> tokens;
    };
}
#endif // TRANSPILER_HPP