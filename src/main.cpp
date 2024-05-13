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

int main(int argc, char* argv[]) {
    std::vector<std::thread> threads;

    std::filesystem::path inputFilePath = "";
    if (argc == 1) {
        inputFilePath = std::filesystem::current_path() / "examples/example.mgml";
        Log::PrintLine("Arguments not provided, using " + inputFilePath.string(), LogType::WARNING);
        threads.emplace_back(TranspileFile, inputFilePath);
    } else {
        for (int i = 1; i < argc; i++) {
            inputFilePath = argv[i];
            threads.emplace_back(TranspileFile, inputFilePath);
        }
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
    return 0;
}

void TranspileFile(const std::filesystem::path& inputFilePath) {
    std::ifstream inputFile(inputFilePath);
    if (!inputFile.good()) {
        Log::PrintLine("Couldn't find " + inputFilePath.string(), LogType::ERROR);
        return;
    } 
    std::filesystem::path outputFilePath = inputFilePath;
    outputFilePath.replace_extension(".gml");

    Transpiler transpiler;
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    transpiler.Execute(inputFilePath.string(), outputFilePath.string());
}