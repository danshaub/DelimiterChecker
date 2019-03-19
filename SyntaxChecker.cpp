#include "SyntaxChecker.h"
#include "GenStack.h"

SyntaxChecker::SyntaxChecker(){
    delimeterStack = new GenStack<char>();
}

SyntaxChecker::SyntaxChecker(string f){
    delimeterStack = new GenStack<char>();
    setFilePath(f);
}

void SyntaxChecker::setFilePath(string f){
    if(fileIsOpen()){
        fileStream.close();
    }
    filePath = f;
    fileStream.open(f);
    setFileName();
}

void SyntaxChecker::setFileName(){
    int indx = filePath.find_last_of("/");
    fileName = filePath.substr(indx+1);
}

bool SyntaxChecker::fileIsOpen(){
    return fileStream.is_open();
}

string SyntaxChecker::getFileName(){
    return fileName;
}

bool SyntaxChecker::checkDelimeters() throw (DelimException){
    string line;
    char checkClosed = '\0';
    char checkOpen = '\0';
    int lineNumber = 1;

    while(getline(fileStream, line)){
        try{
            for(int i = 0; i < line.length(); i++){
                if(line[i] == '(' || 
                   line[i] == '[' ||
                   line[i] == '{'){
                    delimeterStack->push(line[i]);
                    }
                else if(line[i] == ')' || 
                        line[i] == ']' ||
                        line[i] == '}'){
                    checkClosed = line[i];
                    checkOpen = delimeterStack->pop();
                    if(checkClosed == ')' && checkOpen != '('){
                        throw 0;
                    }
                    else if(checkClosed == ']' && checkOpen != '['){
                        throw 0;
                    }
                    else if(checkClosed == '}' && checkOpen != '{'){
                        throw 0;
                    }
                }
            }
        
        }
        catch(StackException e){
            cerr << e.GetMessage() << endl;
            if(e.GetMessage().find("full") != string::npos){
                throw DelimException("Stack error: Too many delimiters");
            }
            
            else{
                char oppositeDelim = '\0';

                if(checkClosed == ')')
                    oppositeDelim = '(';
                else if(checkClosed == ']')
                    oppositeDelim = '[';
                else if(checkClosed == '}')
                    oppositeDelim = '{';

                throw DelimException(fileName + ":" + to_string(lineNumber) + ": Unopened delimiter closed: \'" + oppositeDelim + "\' expected somewhere before \'" + checkClosed + "\'");
            }
            
        }
        catch(int e){
            char oppositeDelim = '\0';

            if(checkOpen == '(')
                oppositeDelim = ')';
            else if(checkOpen == '[')
                oppositeDelim = ']';
            else if(checkOpen == '{')
                oppositeDelim = '}';
            
            throw DelimException(fileName + ":" + to_string(lineNumber) + ": Mismatched Delimiter: \'" + oppositeDelim + "\' expected to close previous \'" + checkOpen + "\', found \'" + checkClosed + "\' instead");
        }

        lineNumber++;
    }
    if(!delimeterStack->isEmpty()){
        char checkOpen = delimeterStack->pop();
        char oppositeDelim = '\0';

        if(checkOpen == '(')
            oppositeDelim = ')';
        else if(checkOpen == '[')
            oppositeDelim = ']';
        else if(checkOpen == '{')
            oppositeDelim = '}';

        throw DelimException(fileName + ":" + to_string(lineNumber) + ": Unclosed Delimeter: reached end of file without finding expected \'" + oppositeDelim + "\'");
    }
}