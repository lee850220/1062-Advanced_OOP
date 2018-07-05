#ifndef __LEXER_H__
#define __LEXER_H__

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <cctype>
#include <cstdlib>
#include <string>
#include "token.h"
#include "word.h"
#include "type.h"
#include "num.h"
#include "real.h"
#include "StringBuilder.h"

using namespace std;

extern fstream in;

class HashTable {
    private:
        map<string, Word> m;
    
    public:
        void put(string key, Word value);
        Word get(string key);

};

class Character {
    private:
        char value;
    public:
        static const char DECIMAL_DIGIT_NUMBER = (char)9;
        Character(char value) : value(value) {}
        static bool isDigit(char ch);
        static bool isDigit(int codePoint);
        static int getType(int codePoint);
        
};

class Lexer {
    private:

        char peek = ' ';
        HashTable words;
        
        void reserve(Word w);
        void readch();
        bool readch(char c);
    
    public:
        
        static int line;
        Lexer();
        //Token& scan();
        unique_ptr<Token> scan();
};

#endif