#ifndef SYNTAX_CHECKER_H
#define SYNTAX_CHECKER_H

#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class SyntaxChecker{
    public:
        SyntaxChecker();
        SyntaxChecker(string f);
        ~SyntaxChecker();
        void setFileName(string f);
        bool fileIsOpen();
        bool checkDelimeters() throw (DelimException);

    private:
        GenStack<char> *delimeterStack;
        ifstream fileStream;
        string fileName;

};


#endif //SYNTAX_CHECKER_H