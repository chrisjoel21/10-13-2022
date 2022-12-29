#include <iostream>
using namespace std;
class qasa{
    private:
        int *elt;
        int size;
        int front;
        int back;
    public:
        qasa(int =10);
        void enqueue(int val);//add
        void dequeue(int &retval);//delete
        bool isempty(){
            
        }

};