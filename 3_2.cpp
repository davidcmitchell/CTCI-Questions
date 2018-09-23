#include <iostream>
#include <string>

template <class T>
class Stack {

public:
    Stack();
    T pop();
    T peek();
    T min();
    void push(T item);
    bool isEmpty();

private:
    
    class StackNode {
        public:
            StackNode(T item);
            T data;
            StackNode *next;
            StackNode *min;
    };

    StackNode *top;

};

template <class T>
Stack<T>::StackNode::StackNode(T item) : data(item), min(this) {}

template <class T>
Stack<T>::Stack() : top(nullptr) {}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw "Is empty"; 
    }
    else {
        T item = top->data;
        StackNode *tmp = top;
        top = top->next;
        delete tmp;
        return item;
    }
}

template <class T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw "Is empty";
    }
    else {
        T item = top->data;
        return item;
    }
}

template <class T>
T Stack<T>::min() {
    if (isEmpty()) {
        throw "Is Empty";
    } else {
        T item = top->min->data;
        return item;
    }
}

template <class T>
void Stack<T>::push(T item) {
    StackNode *newtop = new StackNode(item);
    if (top != nullptr) {
        if (top->min->data < item) {
            newtop->min = top->min;
        }
    }
    newtop->next = top;
    top = newtop;
}

template <class T>
bool Stack<T>::isEmpty() {
    if (top == nullptr)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    Stack<int> *stk = new Stack<int>();
    stk->push(100);
    stk->push(50);
    stk->push(99);
    stk->pop();
    stk->pop();
    int min = stk->min();
    return 0;
}