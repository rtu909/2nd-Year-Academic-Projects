/**
 * \file Stack.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief Provides an ADT representing a model for the Stack structure.
 */
#ifndef A3_STACK_H_
#define A3_STACK_H_

#include <vector>

/**
 * \brief Represents the structure of a Stack and methods to manipulate the stack.
 * \details The Stack structure is done using a C++ vector structure,
 *      but with added restrictions where the structure follows
 *      a LIFO structure.
 */
template <class T>
class Stack {
    private:
        std::vector<T> S;

    public:
        /**
         * \brief Default constructor for the stack.
         */
        Stack();

        /**
         * \brief Constructor for the stack.
         * \param s Vector to initialize the stack with.
         */
        Stack(std::vector<T> s);

        /**
         * \brief Pushes elements onto the stack.
         * \param e Element of type T to push onto the stack.
         * \return a new stack object with the pushed element.
         */
        Stack<T> push(T e);

        /**
         * \brief Pops elements off the stack.
         * \throws out_of_range when the stack is empty, because you can't pop 
         *      an empty stack.
         * \return a new stack object with the element popped.
         */
        Stack<T> pop();

        /**
         * \brief Getter for the last(top) element in the stack.
         * \throws out_of_range when the stack is empty, because an empty stack
         *      has no last element.
         * \return the last element in the stack of type T.
         */
        T top();

        /**
         * \brief Checks the size of the stack.
         * \return the size of the stack of type natural number.
         */
        unsigned int size();

        /**
         * \brief Getter for the stack in vector form to be manipulated.
         * \return the vector representation of the stack.
         */
        std::vector<T> toSeq();
};

#endif
