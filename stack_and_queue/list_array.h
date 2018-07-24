//
// Created by Arman on 7/28/2016.
//

#ifndef HOMEWORK5_LIST_ARRAY_H
#define HOMEWORK5_LIST_ARRAY_H

#include <stack>
#include <cassert>
using namespace std;
namespace ArmandoAguirre_List_Array {
    template<typename T>
    class list_array {
    public:
        list_array();

        list_array(const list_array<T> &);

        int get_length() const;

        void insert_at_head(const T &);

        void remove_from_head();

        void insert_at_tail(const T &);

        void remove_from_tail();

        void remove_from(int);

        void insert_at(int index, const T &data);

        T get_data(const int &index) const;

        list_array<T> &operator=(const list_array<T> &);

    private:
       std::stack<T> main;
        std::stack<T> temp;
        int count;
    };

#include "list_array.template"
}
#endif //HOMEWORK5_LIST_ARRAY_H
