#include "main.h"

fstream in;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "no input file!" << endl;
        return 0;
    }

    in.open(argv[1], ios::in);
    Lexer lexer = Lexer();
    try {
        while (1) {
            unique_ptr<Token> t = lexer.scan();
            if (t->tag == 276) continue;
            if (t->tag < 256)
                cout << "Token: " << t->toString() << "\t(" << t->toString() << ")" << endl;
            else {
                cout << "Token: " << t->toString() << "\t(" << Tag::TAGS.find(t->tag)->second << ")" << endl;
            }
                
        }
    } catch (string e) {
        cout << e << endl;
        in.close();
    }
    
    return 0;
}