#include <string>
#include <fstream> 
#include <iostream> 
#include <regex>
#include <sstream>
#include "event.hpp"
#include "token.hpp"
#include "log.hpp"
#include "transpiler.hpp"
using namespace MGML;

int main(int argc, char **argv) {
    std::string inputFilePath, outputFilePath;
    if (argc < 3) {
        Log::PrintLine("Arguments not provided, using default paths...");
        inputFilePath = "../../test.exgm";
        outputFilePath = "C://Users//thedi//Dev//Astral-Engine-Gaia//src//AstralEngine82.gm82//objects//objPlayer.gml";
    } else {
        inputFilePath = argv[1];
        outputFilePath = argv[2];
    }

    std::ifstream* inputFile = new std::ifstream(inputFilePath);
    std::ofstream* outputFile = new std::ofstream(outputFilePath);
    
    if (!inputFile) {
        Log::PrintLine("Unable to open input " + inputFilePath, LogType::ERROR);
        return 1;
    }

    if (!outputFile->good()) {
        Log::PrintLine("Unable to open output " + outputFilePath, LogType::ERROR);
        return 1;
    }

    Transpiler transpiler;
    transpiler.Execute(inputFile, outputFile);

    Log::PrintLine("Done...");
    delete inputFile;
    delete outputFile;

    return 0;
}