#include "DelimException.h"
#include <iostream>
using namespace std;

DelimException::DelimException(){
    message = "Delimeter Exception";
}

DelimException::DelimException(string m){
    message = m;
}

string DelimException::GetMessage(){
    return message;
}