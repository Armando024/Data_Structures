/*
Implement the same sequence class with the same functions using linked list data structures instead of array.Implement the value semantics. DONE

Create the template class for sequence. DONE

Implement the erase_all_ occurrence which is similar to the erase_ occurrence but it erases all the occurrence of a specific number. DONE

For example for sequence 1 2 4 3 2 3 3 1 3 2 erase_ occurrence(3, 2) removes only the third occurrence of 2 but erase_all_ occurrence(2) erases all the occurrences of 2. DONE

What is the benefit of using linked list instead of array in this case? (Optional: how you may implement the erase_all_ occurrence for arrays such that you only shift each number one time?)

 Optional answer: By making a new array and inserting all the elements, but making an if statement saying that the values can't be equal to the number that you want.
 then make my pointer point to my new array and delete the old array.


 One benefit is that it dosen't has a static size, the size can increase much as you  want, and it cal also shrink. Linked list are also
 better at insertion/deletions because they have a O(1) run time. We also don't have to resize, as resizing is very inefficient because you will to re-allocate the memory,copy, and release

Try to have two files.Implement the [] operator such that you can access to a specific element of the sequence using that.
Example: s[5] = 10;

Write down the running time of each function as a comment in from of that in the header as O notation (e.x. O(n) means linear on input size n).

Write comments in the header.
*/

#include <iostream>
#include <cassert>
using namespace std;
#include "sequence.h"

int main() {
    sequence<int> armando;
    int a=1;
    armando.insert(a);
    armando.insert(8);
    armando.insert(10);
    armando.insert(20);

    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"inserting first 85 and 56\n";
    armando.insert_first(56);
    armando.insert_first(85);

    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"deleting first \n";

    armando.erase_first();
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"deleting last\n";
    armando.erase_last();
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"errasing 1\n";
    armando.erase_occurence(1,1);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"inserting multiple 48\n";
        armando.insert_first(48);
        armando.insert(48);
        armando.insert(48);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"erasing all 48 \n";
    armando.erase_all_occurence(48);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"inserting multiples 24\n";
    armando.insert_first(24);
    armando.insert_first(24);
    armando.insert(24);
    armando.insert(24);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"erasing third 24\n";
    armando.erase_occurence(3,24);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"erasing index 4\n";
    armando.erase_from(4);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"inserting at index 5\n";
    armando.insert_at(789,5);
    cout<<armando;
    cout<<"the size is "<<armando.sequence_count()<<endl;

    cout<<"getting all elements with get_element\n";
    for(size_t i=0;i<armando.sequence_count();i++) {
        cout<<armando.get_element(i)<<endl;
    }

    cout<<"testing if it copy proparly\n";
    sequence<int> yes(armando);
    cout<<yes;
    cout<<"armando..\n";
    cout<<armando;

    cout<<"insrting 45 in yes\n";
    yes.insert(45);
    cout<<yes;
    cout<<"armando...\n";
   cout<<armando;

    cout<<"making a new sequence and making it equal with the other one using =\n";
   sequence<int> A;
    for (size_t i=0;i<6;i++)
    A.insert(i);

    sequence<int> B=A;
    cout<<B;

    cout<<"adding +="<<endl;
    B+=A;
    cout<<B;
    cout<<"adding A+A\n";
    sequence<int> results=A+A;
    cout<<results;
    cout<<"checkeing == operator A==B\n";
//you can change the B to A to check for equality
    if (A==B) {cout<<"they are equal\n";}
    else{cout<<"not equal\n";}

    cout<<"displaying all numbers with []\n";

    for(size_t i=0;i<results.sequence_count();i++) {
        cout<<results[i]<<endl;
    }

    cout<<"inserting square elements with [] \n";
    for(size_t i=0;i<results.sequence_count();i++) {
        results[i]=i*i;
    }

    cout<<results;


    cout<<"Enter 6 numbers to create a new list with console\n";
    sequence<int> trying;
    cin>>trying;
    cin>>trying;
    cin>>trying;
    cin>>trying;
    cin>>trying;
    cin>>trying;
    cout<<"te size of this sequence is "<<trying.sequence_count()<<endl;
    cout<<trying;
    return 0;
}