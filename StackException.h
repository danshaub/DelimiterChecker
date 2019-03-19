#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H

#include <iostream>
using namespace std;

class StackException{
    public:
        StackException();
        StackException(string m);
        string GetMessage();
    private:
        string message;
};

#endif //STACK_EXCEPTION_H