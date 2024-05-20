#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
using namespace std;

template <class T> 
class GenStack{

    public:
        GenStack(); //default constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); // destructor

        //core functions
        void push(T data);
        T pop();
        T peek();

        //aux functions
        bool isEmpty();
        bool isFull();
        int getSize();


    private:
        T *myArray;
        int top;
        int maxSize;
        int mSize;

};


template <class T>
GenStack<T>::GenStack(){
    mSize = 64;
    top = -1;
    myArray = new T [mSize];
}

template <class T>
GenStack<T>::GenStack(int maxSize){
    mSize = maxSize;
    top = -1;
    myArray = new T [mSize];
}

template <class T>
GenStack<T>::~GenStack(){
    cout << "Stack destroyed" << endl;
    delete[] myArray;
}

template <class T>
void GenStack<T>::push(T data){
    if(isFull()){
        throw runtime_error("stack is full");
    }

    myArray[++top] = data;

}

template <class T>
T GenStack<T>::pop(){
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to pop");
    }

    return myArray[top--];
}

template <class T>
T GenStack<T>::peek(){
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to peek");
    }

    return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){

    return(top == mSize -1);
}

template <class T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}

template <class T>
int GenStack<T>::getSize(){
    return top + 1;
}



#endif