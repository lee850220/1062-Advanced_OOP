#ifndef __NUM_H__
#define __NUM_H__

#include "token.h"
#include "tag.h"

class Num : public Token {
    public:
        const int value;

        Num(int v) : Token(Tag::NUM), value(v) {}
        string toString();
};

#endif