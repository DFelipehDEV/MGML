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
        NUMBER,
        STRING,
        IDENTIFIER,
        LPAREN,
        RPAREN,
        LBRACE,
        RBRACE,
        SEPERATOR, 
        DELIMITER,
        EOL,
    };
}
#endif // TOKEN_HPP