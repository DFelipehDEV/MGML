#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>
namespace EXGML {
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