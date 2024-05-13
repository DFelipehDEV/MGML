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
            inputFilePath = "../../test.exgm";
            Log::PrintLine("Arguments not provided, using " + inputFilePath.string(), LogType::WARNING);
        } else {
            if (i > 0) inputFilePath = argv[i];
        }

        if (i > 0) threads.emplace_back(TranspileFile, inputFilePath);
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
    return 0;
}

void TranspileFile(const std::filesystem::path& inputFilePath) {
    std::filesystem::path outputFilePath = inputFilePath;
    outputFilePath.replace_extension(".gml");

    Transpiler transpiler;
    std::ifstream inputFile(inputFilePath);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    transpiler.Execute(inputFilePath.string(), outputFilePath.string());
}