#ifndef __TAG_H__
#define __TAG_H__

#include <map>
#include <string>

using namespace std;

class Tag {
    public:
        static const map<int, string> TAGS;
        static const int AND,
                         BASIC,
                         BREAK,
                         DO,
                         ELSE,
                         EQ,
                         FALSE,
                         GE,
                         ID,
                         IF,
                         INDEX,
                         LE,
                         MINUS,
                         NE,
                         NUM,
                         OR,
                         REAL,
                         TEMP,
                         TRUE,
                         WHILE,
                         NULLTAG;

        static map<int, string> create_map();
};

#endif