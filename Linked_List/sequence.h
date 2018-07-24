//
// Created by Arman on 7/21/2016.
//

#ifndef HOMEWORK4_SEQUENCE_H
#define HOMEWORK4_SEQUENCE_H
//value semantic safe

template <typename T>
class sequence;

template <typename T>
ostream& operator<< (ostream&, sequence<T>&);

template <typename T>
istream& operator>> (istream&,sequence<T>&);

template <typename T>
class sequence {
public:
    sequence(); //T() means the default datatype

    sequence( const sequence<T>&); //value semantic

    ~sequence(); //value semantic

    sequence<T>& operator=(const sequence<T>&); //value semantic

    void insert(const T& x); //O(1)

    void insert_first(const T& x); //O(1)

    void erase_first(); //O(1)

    void erase_last(); //O(1)

    void erase_all_occurence(const T&); //O(n)

    void erase_occurence(int,const T&); //O(n)

    void erase_from(int); //accepts an index //(O(1))

    void insert_at(const T&,int); //accepts data, inserts it at the index //(O(1))

    T get_element(int) const; //O(n)

    int sequence_count() const; //O(1)

    sequence operator+=(const sequence<T>&);

    bool operator==(const sequence<T>&);

   const T& operator[](int ) const;

     T& operator[](int);


    friend ostream& operator<< <>(ostream&, sequence<T>&);

   friend istream& operator>> <> (istream &inside,sequence<T> &armando);

            private:

    class node {

    public:
        node(const T& items =T(), node *next= nullptr ) {
            this->items=items;    this->next= next; }

        void set_item(const T& stuff ) { items=stuff; }

        void set_next( node* next) {this->next=next;}

        T get_item() const { return items;}

        node* get_next() {return next;} //you need to provide both functions
        const node* get_next() const { return next;} // the compiler will choose the correct one
        T items;
    private:

        node* next;
    };

    node* frontptr;
    node* tailptr;
    node* currently;
    node* temp;
    size_t size;

    void Only_for_console_input() {
        if ( frontptr != nullptr) {

            node* B=new node;
            tailptr->set_next(B);
            tailptr=B;
            tailptr->set_next(nullptr);
            size++;
        }
        else {
            node *B=new node;
            frontptr=B;
            tailptr=B;
            B->set_next(nullptr);
            size++;
        }
    }
};
template <typename T>
sequence<T> operator+(const sequence<T>&,const sequence<T>&);



#include "sequence.template"



#endif //HOMEWORK4_SEQUENCE_H
