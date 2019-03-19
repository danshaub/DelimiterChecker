#include "StackException.h"
#include <iostream>
using namespace std;

StackException::StackException(){
    message = "Stack Exception";
}

StackException::StackException(string m){
    message = m;
}

string StackException::GetMessage(){
    return message;
}