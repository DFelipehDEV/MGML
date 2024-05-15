#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>
namespace MGML {
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
        DOT, 
        DELIMITER,
        EOL,
    };
    
    struct Token {
        TokenType type;
        std::string value;
    };
}
#endif // TOKEN_HPP