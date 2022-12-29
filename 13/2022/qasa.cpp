#include "qasa.h"

qasa::qasa(int s){
    elt = new int[size];
    front=back=-1;
}

void qasa:: enqueue(int val){
    if(isempty()){
        front=back=0;
        elt[back]=val;
    }
    if(back==size-1){
        cout<<"full"<<endl;
        return;
    }
    back++;
    elt[back]=val;

}
void qasa::dequeue(int &retval){
    //don't mess with back
    //cout<< a[front];
    //front++;

    //or
    //cout<<a[back];
    //back--;
}

//extra 10_2_1
//make a queue as array
//extra 10_2_2
//use template queue
//extra 10_2_3
//use queue as a linkedlist
//class qasll{
    //node* front;
    //noode* back;
    //adding at front 
    //delete from front
//}
//extra 10_2_4
//use template queue as a linkedlist
