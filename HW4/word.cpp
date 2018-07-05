#include "word.h"

const Word Word::And      = Word("&&",    Tag::AND);
const Word Word::Or       = Word("||",    Tag::OR);
const Word Word::eq       = Word("==",    Tag::EQ);
const Word Word::ne       = Word("!=",    Tag::NE);
const Word Word::le       = Word("<=",    Tag::LE);
const Word Word::ge       = Word(">=",    Tag::GE);
const Word Word::minus    = Word("minus", Tag::MINUS);
const Word Word::True     = Word("true",  Tag::TRUE);
const Word Word::False    = Word("false", Tag::FALSE);
const Word Word::temp     = Word("t",     Tag::TEMP);
const Word Word::NULLWord = Word("NULL",  Tag::NULLTAG);

string Word::toString() {
    return string(lexeme);
}

Word Word::operator=(const Word& c) {
    return Word(c.lexeme, c.tag);
}

bool operator!=(const Word& a, const Word& b) {
    return ( (a.lexeme != b.lexeme) || (a.tag != b.tag) );
}