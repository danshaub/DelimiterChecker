#ifndef DELIM_EXCEPTION_H
#define DELIM_EXCEPTION_H

#include <iostream>
using namespace std;

class DelimException{
    public:
        DelimException();
        DelimException(string m);
        string GetMessage();
    private:
        string message;
};

#endif //DELIM_EXCEPTION_H