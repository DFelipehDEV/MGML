#include <string>
#include <fstream> 
#include <iostream> 
#include <regex>
#include <sstream>
#include "event.hpp"
#include "token.hpp"
#include "log.hpp"
#include "transpiler.hpp"
#include "file.hpp"
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

    InputFile inputFile;
    inputFile.file = new std::ifstream(inputFilePath);
    inputFile.path = inputFilePath;
    OutputFile outputFile;
    outputFile.file = new std::ofstream(outputFilePath);
    outputFile.path = outputFilePath;
    
    if (!inputFile.file->good()) {
        Log::PrintLine("Unable to open input " + inputFilePath, LogType::ERROR);
        return 1;
    }

    if (!outputFile.file->good()) {
        Log::PrintLine("Unable to open output " + outputFilePath, LogType::ERROR);
        return 1;
    }

    Transpiler transpiler;
    transpiler.Execute(inputFile.file, outputFile.file);

    Log::PrintLine("Done...");
    //TODO: Move to File destructor 
    delete inputFile.file;
    delete outputFile.file;

    return 0;
}