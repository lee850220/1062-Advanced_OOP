#include "main.h"

int main(int argc, char* argv[]) {
    
    MyTAR mytar = MyTAR();

    if(!mytar.openFile(argc, argv)) return 0;
    mytar.readFile();
    mytar.printList();

    return 0;
}