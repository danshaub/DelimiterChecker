#include <iostream>
#include "SyntaxChecker.h"

using namespace std;

int main(int argc, char **argv){
    if(argc < 2){
        cout << "Please enter a file name as an arguement" << endl;
        cout << "Usage: ./assignment3.exe [file path]" << endl;
        return 0;
    }

    SyntaxChecker *sc = new SyntaxChecker(argv[1]);
    while(!sc->fileIsOpen()){
        cout << "Invalid file, please enter a new file path" << endl;
        
        string filePath;

        cin >> filePath;

        sc->setFilePath(filePath);
    }

    bool checkMore = false;

    do{
        try{
            sc->checkDelimeters();
        }
        catch(DelimException e){
            cout << e.GetMessage() << endl;
            return 0;
        }

        cout << "Delimiter Syntax is correct for " + sc->getFileName() + " is correct." << endl;
        cout << "Would you like to check another file? [y/n]" << endl;

        char resp;

        cin >> resp;

        if(resp == 'y'){
            checkMore = true;
            cout << "Please enter the path of the next file" << endl;
            string filePath;
            cin >> filePath;
            sc->setFilePath(filePath);
            while(!sc->fileIsOpen()){
                cout << "Invalid file, please enter a new file path" << endl;

                cin >> filePath;

                sc->setFilePath(filePath);
            }
        }
        else{
            checkMore = false;
        }
    }while(checkMore);
}
