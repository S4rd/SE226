#include <iostream>

using namespace std;


class Node {


public:
    int data;
    Node *next;

};

class Queue {
private:
    Node *front;
    Node *back;
    int number;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        number = 0;
    }



    void enqueue(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        if (isEmpty()) {
            front = back = temp;

        } else {
            back->next = temp;
            back = temp;
        }
        number++;


    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            number--;
        }
    }
    int top() {
        if (isEmpty()) {
            
            return NULL;
        } else {
            return front->data;
        }
    }
    bool isEmpty() {
        return (number == 0);
    }
    int size() {
        return number;
    }

};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue size is " << q.size() << endl;
    cout << "Queue top is " << q.top() << endl;
    q.dequeue();
    cout << "Queue size is " << q.size() << endl;
    cout << "Queue top is " << q.top() << endl;
    q.dequeue();
    cout << "Queue size is " << q.size() << endl;
    cout << "Queue top is " << q.top() << endl;
    q.dequeue();
    cout << "Queue size is " << q.size() << endl;
    cout << "Queue top is " << q.top() << endl;


return 0;

}
