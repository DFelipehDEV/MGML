#include <string>
#include <fstream> 
#include <iostream> 
#include <regex>
#include <sstream>
#include <filesystem>
#include "event.hpp"
#include "token.hpp"
#include "log.hpp"
#include "transpiler.hpp"
#include "file.hpp"
using namespace MGML;

int main(int argc, char **argv) {
    std::filesystem::path inputFilePath, outputFilePath;
    if (argc < 2) {
        Log::PrintLine("Arguments not provided, using default paths...", LogType::WARNING);
        inputFilePath = "../../test.exgm";
    } else {
        inputFilePath = argv[1];
    }
    outputFilePath = inputFilePath;
    outputFilePath.replace_extension(".gml");

    Transpiler transpiler;
    transpiler.Execute(inputFilePath.string(), outputFilePath.string());

    Log::PrintLine("Done...");

    return 0;
}