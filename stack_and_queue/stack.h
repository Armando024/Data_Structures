//
// Created by Arman on 7/24/2016.
//

#ifndef HOMEWORK5_STACK_H
#define HOMEWORK5_STACK_H

#include <iostream>
using namespace std;
namespace ArmandoAguirre_Stack_Array {
    template<typename A>
    class stack {
    public:
        static const size_t DEFAULT_SIZE = 20;

        stack(size_t size = DEFAULT_SIZE);

        void push(const A &);

        void pop();

        bool empty() const;

        const A &top() const;

        ~stack(); //SV

        stack(const stack<A> &); //SV

        stack &operator=(const stack<A> &);//SV

        size_t get_count() const;

        size_t get_size() const;


    private:
        int size;
        size_t count;
        A *data;

    };

#include "stack.template"
}
#endif //HOMEWORK5_STACK_H
