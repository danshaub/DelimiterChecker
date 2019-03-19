#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "StackException.h"
using namespace std;

template<class T>
class GenStack{
    public:
        GenStack(); //constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); //destructor

        void push(T d) throw (StackException);
        T pop() throw (StackException);
        T peek() throw (StackException);//aka top()

        int getSize();
        bool isFull();
        bool isEmpty();

        int size;
        int top;

        T *myArray;
};

template<class T>
GenStack<T>::GenStack(){
    myArray = new T[128];
    size = 128;
    top = -1;
}

template<class T>
GenStack<T>::GenStack(int maxSize){
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

template<class T>
GenStack<T>::~GenStack(){
    delete[] myArray;
}

template<class T>
void GenStack<T>::push(T d) throw (StackException){
    if(isFull()){
        throw StackException("Stack Array full: tried to push to full stack");
    }
    myArray[++top] = d;
}

template<class T>
T GenStack<T>::pop() throw (StackException){
    if(isEmpty()){
        throw StackException("Stack Array empty: tried to pop from empty stack");
    }

    return myArray[top--];
}

template<class T>
T GenStack<T>::peek() throw (StackException){
    if(isEmpty()){
        throw StackException("Stack Array empty: tried to peek from empty stack");
    }

    return myArray[top];
}

template<class T>
int GenStack<T>::getSize(){
    return top+1;
}

template<class T>
bool GenStack<T>::isFull(){
    return (top == size-1);
}

template<class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

#endif //GENSTACK_H