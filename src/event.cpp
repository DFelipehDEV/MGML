#include "event.hpp"

namespace EXGML {
    Event::Event(const std::string& functionName, const std::string& define) {
        SetFunctionName(functionName);	
        SetDefine(define);
    }
    std::string Event::GetDefine() {
        return this->m_define;
    }

    void Event::SetDefine(const std::string& define) {
        this->m_define = define;
    }

    std::string Event::GetFunctionName() {
        return this->m_functionName;
    }

    void Event::SetFunctionName(const std::string& name) {
        this->m_functionName = name;
    }
}