#include "language.hpp"

namespace MGML {
    const std::unordered_set<std::string> Language::keywords = {
        "if", 
        "else", 
        "break", 
        "exit", 
        "var", 
        "while", 
        "for", 
        "return", 
        "with",
        "self",
        "other",
        "all",
        "noone",
        "false",
        "true",
    };

    const std::unordered_set<std::string> Language::operators = {
        "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "[", "]",
    };

    bool Language::IsKeyword(const std::string& str) {
        return keywords.find(str) != keywords.end();
    }
    bool Language::IsOperator(const std::string& str) {
        return operators.find(str) != operators.end();
    }
}