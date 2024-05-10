#ifndef TRANSPILER_HPP
#define TRANSPILER_HPP
#include "event.hpp"
#include <fstream>
namespace MGML {
    class Transpiler {
    public:
        Transpiler();
        ~Transpiler();
        Event* GetEvent() const;
        std::string GetCode() const;
        void SetCode(const std::string code);
        void InitializeEvent();

        void Execute(std::string inputPath, std::string outputPath);
        static Event* event[Events::SIZE];

    private:
        std::string m_filePath;
    };
}
#endif // TRANSPILER_HPP