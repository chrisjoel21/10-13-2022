#include <iostream>
using namespace std;

//template <class T>
struct node {
    int data;
    node* next;
};

//template <class T>
class queueArray {
    private:
        node* front;
        node* end;
    public:
        queueArray();
        //bool isEmpty();
        //bool isFull();
        //void resize();
        void enqueue(int value);
        void dequeue();
        int peek();
        void print();
};

queueArray::queueArray() {
    
    front = end = nullptr;
    
}

/*bool queueArray::isEmpty() {
    return (front == nullptr || front > end);
}

bool queueArray::isFull() {
    return (end == nullptr);
}

void queueArray::resize() {
    size *= 2;
    int* newArr = new int[size];

    for(int i = 0; i <= end; i++) {
        newArr[i] = arr[i];
    }

    arr = newArr;
}*/

void queueArray::enqueue(int value) {
    node* temp = new node();
    temp->data =value;
    temp->next =nullptr;
    if(front == nullptr && end == nullptr ) {
        front = end = temp;
    }
    else{
         end->next = temp;
         end = temp;
        }
               
    
}

void queueArray::dequeue() {
    node* temp = front;
    if(front == nullptr && end == nullptr ) {
        cout << "empty" <<endl;
    }
    else{
       // node *cur = front;
       front = front->next;
       delete temp;    
    }
}

int queueArray::peek() {
    if(front != nullptr && end != nullptr) {
        return front->data;
    }
    return -1;
}

void queueArray::print() {
    if(front == nullptr && end == nullptr)
        cout << "empty" <<endl;
    node* cur = front;
    while(cur != nullptr) {
        cout << cur->data << endl;
        cur=cur->next;
    }
    
}

int main() {
    queueArray q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    std::cout << q.peek() << std::endl;

    q.print();

    return 0;
}
