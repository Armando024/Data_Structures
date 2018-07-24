//
// Created by Arman on 7/24/2016.
//

#ifndef HOMEWORK5_STACK_LIST_H
#define HOMEWORK5_STACK_LIST_H
namespace Armando_Linked_List {
    template<typename T>
    class stack_list {
    public:
        stack_list();

        void push(const T& A);

        void pop();

        bool empty()const;

        const int& size() const;

        const T top() const;

        ~stack_list(); //SV

        stack_list(const stack_list<T>&); //SV

        stack_list<T>& operator=(const stack_list<T>&);//SV

    private:
        class node {
        public:
            node(const T &items = T(), node *next = nullptr) {
                this->items = items;
                this->next = next;
            }

            void set_item(const T &stuff) { items = stuff; }

            void set_next(node *next) { this->next = next; }

            T get_item() const { return items; }

            node *get_next() { return next; } //you need to provide both functions
            const node *get_next() const { return next; } // the compiler will choose the correct one
/*
        friend std::istream& operator>>(std::istream &inside,node& armando) {
         inside>>armando.items;
            return inside;
        }
*/

        private:
            T items;
            node *next;

        };
        int count;
        node* headPtr;
        node* temp;
        node* tailPtr;

    };


}
#include "stack_list.template"
#endif //HOMEWORK5_STACK_LIST_H
