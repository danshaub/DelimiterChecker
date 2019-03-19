#include "SyntaxChecker.h"
#include "GenStack.h"

SyntaxChecker::SyntaxChecker(){
    delimeterStack = new GenStack<char>();
}

SyntaxChecker::SyntaxChecker(string f){
    delimeterStack = new GenStack<char>();
    setFileName(f);
}

void SyntaxChecker::setFileName(string f){
    fileName = f;
    fileStream.open(f);
}

bool SyntaxChecker::fileIsOpen(){
    return fileStream.is_open();
}

bool SyntaxChecker::checkDelimeters() throw (DelimException){
    string line;
    int lineNumber = 1;

    while(getline(fileStream, line)){
        try{
            for(int i = 0; i < line.length < i++){
                if(line[i] == '(' || 
                   line[i] == '[' ||
                   line[i] == '{'){
                       delimeterStack->push(line[i]);
                   }
                else if(line[i] == ')' || 
                        line[i] == ']' ||
                        line[i] == '}'){
                            char check = delimeterStack.pop();
                        }
            }
        }
        catch(StackException e){
            cerr << e.GetMessage() << endl;
            throw DelimException("Stack error");
        }

        lineNumber++;
    }
}