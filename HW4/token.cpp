#include "token.h"


string Token::toString() {
    return string(1, (char)tag);
}
