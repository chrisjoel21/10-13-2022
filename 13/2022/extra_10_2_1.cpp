#include <iostream>

class queueArray {
    private:
        int* arr;
        int size;
        int front, end;
    public:
        queueArray();
        bool isEmpty();
        bool isFull();
        void resize();
        void enqueue(int value);
        void dequeue();
        int peek();
        void print();
};

queueArray::queueArray() {
    size = 3;
    arr = new int[size];
    front = 0;
    end = -1;
}

bool queueArray::isEmpty() {
    return (front == -1 || front > end);
}

bool queueArray::isFull() {
    return (end == size - 1);
}

void queueArray::resize() {
    size *= 2;
    int* newArr = new int[size];

    for(int i = 0; i <= end; i++) {
        newArr[i] = arr[i];
    }

    arr = newArr;
}

void queueArray::enqueue(int value) {
    if(isFull()) {
        resize();
    }

    end++;
    arr[end] = value;
}

void queueArray::dequeue() {
    if(!isEmpty()) {
        for(int i = 0; i < end; i++) {
            arr[i] = arr[i + 1];
        }
        end--;
    }
}

int queueArray::peek() {
    if(!isEmpty()) {
        return arr[front];
    }
    return -1;
}

void queueArray::print() {
    while(!isEmpty()) {
        std::cout << peek() << " ";
        dequeue();
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