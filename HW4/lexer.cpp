#include "lexer.h"

int Lexer::line = 1;

void HashTable::put(string key, Word value) {
    m.insert(pair<string, Word>(key, value));
}

Word HashTable::get(string key) {
    map<string, Word>::iterator iter = m.find(key);
    if (iter != m.end()) {
        Word w = iter->second;
        //m.erase(iter);
        return w;
    } 
    else return Word(Word::NULLWord);
}

bool Character::isDigit(char ch) {
    return isdigit((int)ch);
}

void Lexer::reserve(Word w) {
    words.put(w.lexeme, w);
}

Lexer::Lexer() {
    reserve(Word("if", Tag::IF));
    reserve(Word("else", Tag::ELSE));
    reserve(Word("while", Tag::WHILE));
    reserve(Word("do", Tag::DO));
    reserve(Word("break", Tag::BREAK));
    reserve(Word::True);
    reserve(Word::False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Bool);
    reserve(Type::Float);
}

void Lexer::readch() {
    char i;
    if (in.get(i)) {
        peek = i;
    } else {
        throw (string("End of file reached"));
    }
}

bool Lexer::readch(char c) {
    readch();
    if (peek != c) return false;
    peek = ' ';
    return true;
}

unique_ptr<Token> Lexer::scan() {
    for ( ; ; readch()) {
        if (peek == ' ' || peek == '\t') continue;
        else if (peek == '\n') line++;
        else break;
    }
    switch (peek) {
        case '&':
            if (readch('&')) return make_unique<Word>(Word::And);
            else return make_unique<Token>('&');
        case '|':
            if (readch('|')) return make_unique<Word>(Word::Or);
            else return make_unique<Token>('|');
        case '=':
            if (readch('=')) return make_unique<Word>(Word::eq);
            else return make_unique<Token>('=');
        case '!':
            if (readch('=')) return make_unique<Word>(Word::ne);
            else return make_unique<Token>('!');
        case '<':
            if (readch('=')) return make_unique<Word>(Word::le);
            else return make_unique<Token>('<');
        case '>':
            if (readch('=')) return make_unique<Word>(Word::ge);
            else return make_unique<Token>('>');
    }

    if (isdigit(peek)) {
        int v = 0;
        do {
            v = 10 * v + atoi(string(1, (char)peek).c_str());
            readch();
        } while (isdigit(peek));
        if (peek != '.') return make_unique<Num>(v);
        float x = v;
        float d = 10;
        for (;;) {
            readch();
            if (!isdigit(peek)) break;
            x += atoi(string(1, (char)peek).c_str()) / d;
            d *= 10;
        }
        return make_unique<Real>(x);
    }

    if (isalpha(peek)) {
        StringBuilder b;
        do {
            b.append(string(1, (char)peek));
            readch();
        } while (isalpha((int)peek) || isdigit((int)peek));
        string s = b.str();
        Word w = (Word) words.get(s);
        if (w != Word::NULLWord) 
            return make_unique<Word>(w);
        Word y = Word(s, Tag::ID);
        //words.put(s, y);
        return make_unique<Word>(y);
    }

    Token tok = Token((int)peek);
    peek = ' ';
    //cout << line << " ";
    return make_unique<Token>(tok);
}


