//
// Created by Arman on 7/29/2016.
//

#ifndef HOMEWORK6_PRIORITY_QUEUE_H
#define HOMEWORK6_PRIORITY_QUEUE_H

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class priority_queue {
public:
    priority_queue();

    priority_queue(const priority_queue<T>&); //SV

    void push(const T&);

    T top()const ;

    void pop();

    bool empty() const;

    int size()const;

    priority_queue<T>& operator=(const priority_queue<T>&); //SV

    ~priority_queue(); //SV

private:
    T* data;
    static const size_t SIZE=25;
    size_t count;

};

#include "priority_queue.template"

#endif //HOMEWORK6_PRIORITY_QUEUE_H
