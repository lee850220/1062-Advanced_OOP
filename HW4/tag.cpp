#include "tag.h"

const int   Tag::AND = 256,
            Tag::BASIC = 257,
            Tag::BREAK = 258,
            Tag::DO = 259,
            Tag::ELSE = 260,
            Tag::EQ = 261,
            Tag::FALSE = 262,
            Tag::GE = 263,
            Tag::ID = 264,
            Tag::IF = 265,
            Tag::INDEX = 266,
            Tag::LE = 267,
            Tag::MINUS = 268,
            Tag::NE = 269,
            Tag::NUM = 270,
            Tag::OR = 271,
            Tag::REAL = 272,
            Tag::Tag::TEMP = 273,
            Tag::TRUE = 274,
            Tag::WHILE = 275,
            Tag::NULLTAG = 276;  

const map<int, string> Tag::TAGS = Tag::create_map();

map<int, string> Tag::create_map() {
    map<int, string> m;
    m[AND] = "AND";
    m[BASIC] = "BASIC";
    m[BREAK] = "BREAK";
    m[DO] = "DO";
    m[ELSE] = "ELSE";
    m[EQ] = "EQ";
    m[FALSE] = "FALSE";
    m[GE] = "GE";
    m[ID] = "ID";
    m[IF] = "IF";
    m[INDEX] = "INDEX";
    m[LE] = "LE";
    m[MINUS] = "MINUS";
    m[NE] = "NE";
    m[NUM] = "NUM";
    m[OR] = "OR";
    m[REAL] = "REAL";
    m[TEMP] = "TEMP";
    m[TRUE] = "TRUE";
    m[WHILE] = "WHILE";
    return m;
}