#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>
namespace MGML {
    struct Token {
        int type;
        std::string value;
    };

    enum TokenType {
        KEYWORD = 0,
        OPERATOR,
    };
}
#endif // TOKEN_HPP