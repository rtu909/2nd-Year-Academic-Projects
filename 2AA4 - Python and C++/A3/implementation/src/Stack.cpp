// Implementation here
#include <iostream>
#include "Stack.h"
#include "CardTypes.h"
#include <stdexcept>

template <class T>
Stack<T>::Stack():S(std::vector<T>()){
};

template <class T>
Stack<T>::Stack(std::vector<T> s): S(s){
};

template <class T>
Stack<T> Stack<T>::push(T e){
    std::vector<T> new_Vect;
    new_Vect = this->S;

    new_Vect.push_back(e);

    //casting the vector as a stack type
    Stack<T> new_Stack = Stack<T>(new_Vect);
    
    //returning vector as stack
    return new_Stack;
}

template <class T>
Stack<T> Stack<T>::pop(){
    if (this->S.size() == 0){
      throw std::out_of_range("can't pop empty stack");
    };

    std::vector<T> new_Vect;
    new_Vect = this->S;

    new_Vect.pop_back();

    Stack<T> new_Stack = Stack<T>(new_Vect);
    
    return new_Stack;
}

template <class T>
T Stack<T>::top(){
    if (this->S.size() == 0){
      throw std::out_of_range("can't top empty stack");
    };
    
    T last;

    last = this->S.back();
    return last;
}

template <class T>
unsigned int Stack<T>::size(){
    return this->S.size();
}

template <class T>
std::vector<T> Stack<T>::toSeq(){
    return this->S;
}

// Keep this at bottom
template class Stack<CardT>;
