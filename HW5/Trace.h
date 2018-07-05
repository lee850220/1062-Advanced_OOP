#ifndef __TRACE_H_INCLUDED__
#define __TRACE_H_INCLUDED__

#include <iostream>
#include <string>

using std::cerr;
using std::endl;
using std::string;

class Trace {
    private:
        static int depth;
        const string name;

        void print_name(const string prefix) {
            for (int i = 0; i < depth; i++) {
                cerr << " ";
            }
            cerr << prefix << " " << name << " (" << depth << ")" << endl;
        }

    public:
        Trace(const string n) : name(n) {
            depth++;
            print_name("Entering");
        }

        ~Trace() {
            print_name("Leaving ");
            depth--;
        }
};

#ifdef __TRACE__
#define TRACE(v, n) Trace v(n)
#else
#define TRACE(v, n)
#endif

#endif