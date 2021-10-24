#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"

int main(int argc, char** argv) {
    if(argc != 3) {
        std::cerr << "Input error\n";
        return 0;
    }
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    /*
    Dictionary a, b;
    for(int index = 0; index < 6; index++)
        a.nextWord(in);
    for(int index = 0; index < 7; index++)
        b.nextWord(in);

    a.exportData(out);

    out << '\n';
    b.exportData(out);
    out << '\n';

    a.copy(b);
    a.exportData(out);
    */

    Dictionary dictionary;
    dictionary.importData(in);
    dictionary.exportData(out);

    in.close();
    out.close();
    return 0;
}