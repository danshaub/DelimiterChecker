#ifndef SYNTAX_CHECKER_H
#define SYNTAX_CHECKER_H

#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "DelimException.h"

using namespace std;

class SyntaxChecker{
    public:
        SyntaxChecker();
        SyntaxChecker(string f);
        ~SyntaxChecker();
        void setFilePath(string f);
        bool fileIsOpen();
        bool checkDelimeters() throw (DelimException);
        string getFileName();

    private:
        void setFileName();
        GenStack<char> *delimeterStack;
        ifstream fileStream;
        string filePath;
        string fileName;

};


#endif //SYNTAX_CHECKER_H