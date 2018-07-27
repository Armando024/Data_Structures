/*
1. Create a template class priority queue using array as the container. DONE
push,//the sorting is done here,
 pop,//deletes the top element
 empty,returns true if empty and false if it's not empty
 size , it returns the amount of elements in array
 top it return  the most priority element

2. Create a template function for sorting a list of comparable types using heap sort. DONE
 Explain why you cannot use your priority queue to do the heapsort INPLACE.
        INPLACE means sorting without extra space requirement, and if we did used our priority queue to do a heapsort,
        this will required us to used extra space. The reason we will need extra space is because if we wanted to access the middle element
        or any other element in our priority queue we will have to erase the top element meaning we will need to store the top elements somewhere else
        which means we need more space.

*     The reason we don't used heapsort INPLACE for our priority queue is because Heapsort is not stable,
    because it does not preserve the order of same value input, and the resultant output.
    An example is that if we have an input of (5a,5b) in which "a" and "b" are used to denote the order in which the numbers are
    input in the priority queue, The outout would be (5b,5a) in which that would be wrong in our priority queue. because the output of our
    priority queue  should be (5a,5b) because it serves a FIFO.


3. Use priority queue to do the heapsort. Your heapsort will not be an inplace sorting algorithm. DONE

4. Create a sorting algorithm using the concept of binary search tree. DONE
 Explain what would be the best case running time and worst case running time of sorting elements using this tree.

5. Try to sort an array of strings with size 10 using your sorting algorithms. DONE
*/



#include <iostream>

#include <stdlib.h>
using namespace std;

#include "priority_queue.h"

template <typename A>
void heap_sort(A *data,int elements) {
    A temp; //to store temp data
    int temp2; //to store index
    //first I build my max heap
    int index=elements/2; // start using the fomula
    while ( index>=1 ) {
        temp=data[index];
        temp2=index*2;
        //this loops help me sort my list
        while (temp2<=elements) {

            if (temp2<elements && data[temp2+1]>data[temp2]) {
                temp2++;
            }
            if (temp>data[temp2]) {
                break;
            }
            else if ( temp<= data[temp2]) {
                data[temp2/2]=data[temp2];
                temp2=2*temp2;

            }
        }
        data[temp2/2]=temp;
        index--; //after heapfy i dcearese by 1
    }

    //Now i delete and sort them
     index=elements; //I start my index from the # of elements and decrase it
    int index2=1;
    int temp3;
    while(index>=2) {
        temp=data[index]; //get temp
        data[index]=data[1];
        data[1]=temp; //set it to index 1

            temp3=index-1;// one step behind
        //I used the same method (while) loop to sort my list except I will be sorting it now

        temp=data[index2]; //make new temp for the index 1
        temp2=index2*2;  //I make 2 temp variables one that holds the data and another the position
        //this loop help me sort my list
        while (temp2<=temp3) {

            if (temp2<temp3 && data[temp2+1]>data[temp2]) {
                temp2++;
            }
            if (temp>data[temp2]) {
                break;
            }
            else if ( temp<= data[temp2]) {
                data[temp2/2]=data[temp2];
                temp2=2*temp2;

            }
        }
        data[temp2/2]=temp;
        index--;
    }

}


template <typename X>
void heapsort_priority(X* data,int element) {

    priority_queue<X> temp;

    for (size_t i=0;i<element;i++)
    {temp.push(data[i]);}

    for(size_t i=0;i<element;i++){
        data[element-1-i]=temp.top();
        temp.pop();
    }

}


/*
 *
 * Create a sorting algorithm using the concept of binary search tree.
 Explain what would be the best case running time and worst case running time of sorting elements using this tree.


 */

template <typename B>
void algorithm_BST(B* data, int elements){
    //I'm assuming my index 0 is my root and is going to be my root element
    //first we transform it into a BST
    B temp;
    int index=0;
    int tempindex=0;
    while( index<elements ) {

            tempindex=index;

        if (data[index]<data[index+1]) {
            tempindex=index;
        }
        while (data[tempindex]>data[index+1]) {
                    tempindex++;
        }
        if (tempindex==-1) {tempindex=0;}
        else {tempindex++;}
        B* temparray=new B[elements];
        for(int i=tempindex;i<elements;i++) {
            temparray[i]=data[i];
        }
        for(int c=tempindex;c<=elements;c++) {
            data[c+1]=temparray[c];
        }
        data[tempindex]=data[index];

        index++;

    }


}
int main() {

    cout<<"unsorted array \n";
    int *BST=new int[15];

    for(int i=0;i<15;i++){
        BST[i]=-1;
    }


    BST[0]=25;
    BST[1]=10;
    BST[2]=15;

    for (size_t i=0;i<3;i++) {
        cout<<BST[i]<<endl;
    }
cout<<"sorted arrays\n";
    algorithm_BST(BST,3);
    for (size_t i=0;i<3;i++) {
        cout<<BST[i]<<endl;
    }


    int *temparray=new int[15];
    for (size_t i=0;i<10;i++)
    temparray[i]=rand() % 60;

        heapsort_priority(temparray,10);

    cout<<"temparray sorted..\n";
    for (size_t i=0;i<10;i++)
        cout<<temparray[i]<<endl;


    int* array=new int[15];

    for(size_t i=1;i<7;i++) {
        array[i]=rand() % 1001;
    }
        cout<<"Printing my unsorted array \n";
    for(size_t i=1;i<7;i++) {
        cout<<array[i]<<endl;
    }


    cout<<"my sorted array \n";
    heap_sort(array,6);
    for(size_t i=1;i<7 ;i++) {
        cout<<array[i]<<endl;
    }

    double* array2=new double[10];
    array2[1]=2.48;
    array2[2]=2.56;
    array2[3]=8.89;
    array2[4]=6.23;
    array2[5]=1.39;
    array2[6]=3.28;
    array2[7]=9.74;
    array2[8]=2.12;
    cout<<"using double numbers printing unsorted array..\n";
    for(size_t i=1;i<9 ;i++) {
        cout<<array2[i]<<endl;
    }

    cout<<"sorted array \n";
    heap_sort(array2,8);
    for(size_t i=1;i<9 ;i++) {
        cout<<array2[i]<<endl;
    }


    priority_queue<int> myQ;
    if (myQ.empty()) {cout<<"it's empty "<<"and size="<<myQ.size()<<endl; }
    else{cout<<"not empty and size="<<myQ.size()<<endl;}
    cout<<"inserting elements..\n";
    for (size_t i=0;i<10;i++)
    {
        myQ.push(rand() % 1000 + 1); //generating random numbers to test priority
    }
    priority_queue<int> second(myQ); //to be used later for copy constructor

    if (myQ.empty()) {cout<<"it's empty "<<"and size="<<myQ.size(); }
    else{cout<<"not empty and size="<<myQ.size()<<endl;}

    while (!myQ.empty()) {
    cout<<"my top == "<<myQ.top()<<endl;
    myQ.pop();}



    cout<<"semantic values copy constructor..\n";

   second.push(45);
   second.push(778);
    priority_queue<int> third=second;
    while (!second.empty()) {
        cout<<"my top == "<<second.top()<<endl;
        second.pop();
    }
    cout<<"semantic values = opearator\n";
    third.push(845);
    third.push(96);
    third.push(412);
    while (!third.empty()) {
        cout<<"my top == "<<third.top()<<endl;
        third.pop();
    }


    cout<<"creating 3 arrays of strings of 10 \n";


    string a1[4] = {"cat", "dog", "fish", "bear"};



    string texts[] = {"","edf", "qws", "dwew","sds","wew","sds","wer","okk","aqs","sds"};
    string texts1[] = {"edf", "qws", "dwew","sds","wew","sds","wer","okk","aqs","sds"};
    string texts2[] = {"edf", "qws", "dwew","sds","wew","sds","wer","okk","aqs","sds"};

    cout<<"printing unsorted string\n";
    for(int i=0;i<10;i++)
    cout << texts[i] << endl;

    cout<<"heapsorted"<<endl;
    cout<<"printing sorted list\n";
    heap_sort(texts,10);
    for(int i=0;i<10;i++)
        cout << texts[i] << endl;

    cout<<"heapsort_priority\n";
    cout<<"printing sorteed list\n";
    heapsort_priority(texts1,10);

    for(int i=0;i<10;i++)
        cout << texts1[i] << endl;



    return 0;
}


/*
 *
 *
 *    int index=0;
    B temp;
    int oldindex=0;
    while(index<=elements) {
            oldindex=index;
        while(index<index+2) {
        if (data[index]<data[index+1]) { //check that left node is smaller
            if (data[index+1]==-1) { data[index+1]=-1;}
            else {
                temp=data[index];
                data[index]=data[index+1];
                data[index+1]=temp;}
        }
        if (data[index]>data[index+2]) {
            if (data[index+2]==-1) {data[index+1]=-1;}
            else {
            temp=data[index];
            data[index]=data[index+2];
            data[index+2]=temp;}
        }
            index++;
        }
        index=oldindex;
        index++;
    }
 *
 */