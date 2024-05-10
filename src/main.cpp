#include <string>
#include <fstream> 
#include <iostream> 
#include <regex>
#include <sstream>
#include <filesystem>
#include <thread>
#include "event.hpp"
#include "token.hpp"
#include "log.hpp"
#include "transpiler.hpp"
using namespace MGML;

void TranspileFile(const std::filesystem::path& inputFilePath);

int main(int argc, char **argv) {
    std::vector<std::thread> threads;

    for (int i = 0; i < argc; i++) {
        std::filesystem::path inputFilePath;

        if (argc < 2) {
            Log::PrintLine("Arguments not provided, using default paths...", LogType::WARNING);
            inputFilePath = "../../test.exgm";
        } else {
            if (i > 0) inputFilePath = argv[i];
        }

        threads.emplace_back(TranspileFile, inputFilePath);
    }

    for (std::thread& thread : threads) {
        thread.join();
    }

    Log::PrintLine("Done...");
    return 0;
}

void TranspileFile(const std::filesystem::path& inputFilePath) {
    std::filesystem::path outputFilePath = inputFilePath;
    outputFilePath.replace_extension(".gml");

    Transpiler transpiler;
    std::ifstream inputFile(inputFilePath);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    transpiler.Tokenize(buffer.str());
    //transpiler.Execute(inputFilePath.string(), outputFilePath.string());
}