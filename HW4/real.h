#ifndef __REAL_H__
#define __REAL_H__

#include <sstream>
#include "token.h"
#include "tag.h"

class Real : public Token {
    public:
        const float value;

        Real(float v) : Token(Tag::REAL), value(v) {}
        string toString(); 
};

#endif