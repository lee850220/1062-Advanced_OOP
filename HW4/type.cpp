#include "type.h"

const Type Type::TypeNULL  = Type("NULL",  Tag::BASIC, 0);
const Type Type::Int       = Type("int",   Tag::BASIC, 4);
const Type Type::Float     = Type("float", Tag::BASIC, 8);
const Type Type::Char      = Type("char",  Tag::BASIC, 1);
const Type Type::Bool      = Type("bool",  Tag::BASIC, 1);

extern const Type TypeNULL;

bool operator==(const Type& a, const Type& b) {
    return ( (a.tag == b.tag) && (a.lexeme == b.lexeme) && (a.width == b.width) );
}

bool Type::numeric(Type p) {
    if (p == Char || p == Int || p == Float) return true;
    else return false;
}

Type Type::max(Type p1, Type p2) {
    if (!numeric(p1) || !numeric(p2)) return TypeNULL;
    else if (p1 == Float || p2 == Float) return Float;
    else if (p1 == Int || p2 == Int) return Int;
    else return Char;
}