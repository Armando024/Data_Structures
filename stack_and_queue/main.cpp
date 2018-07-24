/*
 *
 *
 * 1. Answer to the following stacks and queues questions:

Design a template stack data structure (Call it stack) using dynamic array. DONE
Design a template stack data structure (Call it stack_list)  using linked list. DONE
Explain what is the benefit of each method.
 The benefits of arrays are that they are better at random access which has a run time of O(1),
 however Linked Lists are better at insertions/deletions
 which has a run time of O(1).They also don't have a fix size.

(Optional) Create a linked list data structure (list_array) with the fixed size DONE
 using only stack data structure (You are not allowed to use any other data-types including node).
    length of the linked list
    insert a new node at the head
    insert a node at any location
    delete a node from the head
2. Answer to the following question about trees:

Design a special tree data structure such that  the branching factor of the root
 is 3 and the branching factor of its children is two. After that the branching factor
 of a node is 2 if the node is child of a node with branching factor of 3 and its branching
 factor is 3 if it is the child of a node with branching factor of 2. DONE attach in picture
 *
 */

/*
 * push insert element
 * pop remove top element
 * empty test whether container is empty
 * size return size of array, to get count of elements used get_count
 * the size for Linked list resturn the count of the elements
 * top access next element
 *
 *
 */

#include <iostream>
using namespace std;

#include "stack.h"
using namespace ArmandoAguirre_Stack_Array;
#include "stack_list.h"
using namespace Armando_Linked_List;

#include "list_array.h"
using namespace ArmandoAguirre_List_Array;
int main() {
    cout<<"Stack with array\n";
    ArmandoAguirre_Stack_Array::stack<int> test(25);
    if (test.empty()) {cout<<"yes it's empty\n";}
    else {cout<<"not empty\n";}
    int r=0;
    test.push(5);
    test.push(r);
    test.push(45);
    test.push(54);
    test.push(12);
    if (test.empty()) {cout<<"yes it's empty\n";}
    else {cout<<"not empty\n";}

    ArmandoAguirre_Stack_Array::stack<int> test2(test);

cout<<"count=="<<test.get_count()<<endl;
    cout<<"size=="<<test.get_size()<<endl;
    cout<<test.top()<<endl;
    test.pop();
    cout<<test.top()<<endl;
    test.pop();
    cout<<test.top()<<endl;
    test.pop();
    cout<<test.top()<<endl;
    test.pop();
    cout<<test.top()<<endl;
    test.pop();


    cout<<"printing the first 3 elements of ..test2\n";
    cout<<test2.top()<<endl;
    test2.pop();
    cout<<test2.top()<<endl;
    test2.pop();
    cout<<test2.top()<<endl;
    test2.pop();

    cout<<"Stack with Linked list\n";

    stack_list<int> hello;
    if (hello.empty()) {cout<<"yes it's empty"<<" and size is "<<hello.size()<<endl;}
    else {cout<<"not empty\n";}

    for (size_t i=1;i<=6;i++) {
    hello.push(i*i);}

    if (hello.empty()) {cout<<"yes it's empty\n";}
    else {cout<<"not empty"<<" and size is "<<hello.size()<<endl;}

    stack_list<int> hello2(hello);

    cout<<"printing Linklist Stack\n";
    cout<<hello.top()<<endl;
    hello.pop();
    cout<<hello.top()<<endl;
    hello.pop();
    cout<<hello.top()<<endl;
    hello.pop();
    cout<<hello.top()<<endl;
    hello.pop();
    cout<<hello.top()<<endl;
    hello.pop();
    cout<<hello.top()<<endl;




    cout<<"printing 3 elements of copy \n";
    cout<<hello2.top()<<endl;
    hello2.pop();
    cout<<hello2.top()<<endl;
    hello2.pop();
    cout<<hello2.top()<<endl;
    hello2.pop();

   stack_list<int> equal=hello2;


    cout<<"using = operator and making it equal to the second list\n";
    cout<<equal.top()<<endl;
    equal.pop();
    cout<<equal.top()<<endl;
    equal.pop();
    cout<<equal.top()<<endl;

    cout<<"Optional part\n";
    list_array<int> first;

    for (int i=1;i<6;i++)
    first.insert_at_head(i*i*i);



    for(int i=0;i<first.get_length();i++)
    cout<<first.get_data(i)<<endl; //this insert to the head that's the reason the numbers print backward

    first.remove_from_head();
    first.remove_from_head();
    cout<<"removing head 2 times"<<endl;
    for(int i=0;i<first.get_length();i++)
        cout<<first.get_data(i)<<endl;

    cout<<"inserting 4 numbers in tail\n";
    first.insert_at_tail(45);
    first.insert_at_tail(84);
    first.insert_at_tail(452);
    first.insert_at_tail(489);
    for(int i=0;i<first.get_length();i++)
        cout<<first.get_data(i)<<endl;

    cout<<"erasing tail twice \n";
    first.remove_from_tail();
    first.remove_from_tail();
    for(int i=0;i<first.get_length();i++)
        cout<<first.get_data(i)<<endl;




   cout<<"erasing index 0 \n";
    first.remove_from(0);
    for(int i=0;i<first.get_length();i++)
        cout<<first.get_data(i)<<endl;


    cout<<"erasing index  2 \n";
    first.remove_from(2);
    for(int i=0;i<first.get_length();i++)
        cout<<first.get_data(i)<<endl;

    cout<<"insert at 0 index \n";
    first.insert_at(0,24);
    for(int i=0;i<first.get_length();i++)
        cout<<first.get_data(i)<<endl;


cout<<"value semantics \n";
    list_array<int> second(first);
    for(int i=0;i<second.get_length();i++)
        cout<<second.get_data(i)<<endl;


    cout<<"using equal operators\n";
    list_array<int> third=second;
    for(int i=0;i<third.get_length();i++)
        cout<<third.get_data(i)<<endl;

    return 0;
}




















