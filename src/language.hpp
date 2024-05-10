#ifndef MGML_HPP
#define MGML_HPP
#include <unordered_set>
#include <string>
namespace MGML {
    class Language {
    public:
        static const std::unordered_set<std::string> keywords;

        static const std::unordered_set<std::string> operators;

        static bool IsKeyword(const std::string& str);

        static bool IsOperator(const std::string& str);
    };
}
#endif