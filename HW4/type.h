#ifndef __TYPE_H__
#define __TYPE_H__

#include <string>
#include "word.h"

class Type : public Word {
    public:
        int width = 0;
        const static Type TypeNULL  ;
        const static Type Int       ;
        const static Type Float     ;
        const static Type Char      ;
        const static Type Bool      ;

        Type(string s, int tag, int w) : Word(s, tag), width(w) {}
        static bool numeric(Type P);
        static Type max(Type p1, Type p2);
        friend bool operator==(const Type& a, const Type& b);
};



#endif