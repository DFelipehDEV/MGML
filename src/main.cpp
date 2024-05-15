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

int main(int argc, char* argv[]) {
    std::vector<std::thread> threads;

    std::filesystem::path inputFilePath = "";

    auto transpileFile = [](const std::filesystem::path& inputFilePath) {
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
        transpiler.Compile(inputFilePath.string(), outputFilePath.string());
    };


    if (argc == 1) {
        inputFilePath = std::filesystem::current_path() / "examples/example.mgml";
        Log::PrintLine("Arguments not provided, using " + inputFilePath.string(), LogType::WARNING);
        threads.emplace_back(transpileFile, inputFilePath);
    } else {
        for (int i = 1; i < argc; i++) {
            inputFilePath = argv[i];
            threads.emplace_back(transpileFile, inputFilePath);
        }
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
    return 0;
}