#include <iostream>
using namespace std;
template <class T>
class queueArray {
    private:
        T* arr;
        int size;
        int front, end;
    public:
        queueArray();
        bool isEmpty();
        bool isFull();
        void resize();
        void enqueue(T value);
        void dequeue();
        int peek();
        void print();
};
template <class T>
queueArray<T>::queueArray() {
    size = 3;
    arr = new T[size];
    front = 0;
    end = -1;
}

template <class T>
bool queueArray<T>::isEmpty() {
    return (front == -1 || front > end);
}

template <class T>
bool queueArray<T>::isFull() {
    return (end == size - 1);
}
template <class T>
void queueArray<T>::resize() {
    size *= 2;
    int* newArr = new int[size];

    for(int i = 0; i <= end; i++) {
        newArr[i] = arr[i];
    }

    arr = newArr;
}
template <class T>
void queueArray<T>::enqueue(T value) {
    if(isFull()) {
        resize();
    }

    end++;
    arr[end] = value;
}
template <class T>
void queueArray<T>::dequeue() {
    if(!isEmpty()) {
        for(int i = 0; i < end; i++) {
            arr[i] = arr[i + 1];
        }
        end--;
    }
}
template <class T>
int queueArray<T>::peek() {
    if(!isEmpty()) {
        return arr[front];
    }
    return -1;
}

template <class T>
void queueArray<T>::print() {
    if(isEmpty()){
        cout << "empty" <<endl;
    }
    while(!isEmpty()) {
        std::cout << peek() << " ";
        dequeue();
    }
}

int main() {
    queueArray<int> q;
    queueArray<char> p;
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