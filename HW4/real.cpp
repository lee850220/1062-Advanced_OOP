#include "real.h"

string Real::toString() {
    ostringstream ss;
    ss << value;
    return string(ss.str());
}