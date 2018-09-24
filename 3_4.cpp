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

template <class T>
class Queue {

public:
    Queue();
    void enqueue(T item);
    T dequeue();
    T peek();
    bool isEmpty();

private:
    Stack<T> push_stack;
    Stack<T> pop_stack;
    bool push_on;

};

template <class T>
Queue<T>::Queue() : push_stack(Stack<T>()), pop_stack(Stack<T>()), push_on(true) {}

template <class T>
void Queue<T>::enqueue(T item) {
    if (push_on) {
        push_stack.push(item);
    }
    else {
        while (!pop_stack.isEmpty()) {
            push_stack.push(pop_stack.pop());
        }
        push_on = true;
    }
}

template <class T>
T Queue<T>::dequeue() {
    if (push_on) {
        while (!push_stack.isEmpty()) {
            pop_stack.push(push_stack.pop());
        }
        push_on = false;
    }
    return pop_stack.pop();
}

template <class T>
T Queue<T>::peek() {
    if (push_on) {
        while (!push_stack.isEmpty()) {
            pop_stack.push(push_stack.pop());
        }
        push_on = false;
    }
    return pop_stack.peek();
}

template <class T>
bool Queue<T>::isEmpty() {
    if (pop_stack.isEmpty() && push_stack.isEmpty()) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {

    Queue<int> q = Queue<int>();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    int res = q.dequeue();
    res = q.peek();
}