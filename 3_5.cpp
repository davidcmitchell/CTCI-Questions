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
    int getSize();

private:
    
    class StackNode {
        public:
            StackNode(T item);
            T data;
            StackNode *next;
            StackNode *min;
    };

    StackNode *top;
    int size;
};

template <class T>
Stack<T>::StackNode::StackNode(T item) : data(item), min(this) {}

template <class T>
Stack<T>::Stack() : top(nullptr), size(0) {}

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
        size--;
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
    size++;
}

template <class T>
bool Stack<T>::isEmpty() {
    if (top == nullptr)
        return true;
    return false;
}

template <class T>
int Stack<T>::getSize() {
    return size;
}

template <class T>
void StackSort(Stack<T> &sort_stack) {
    Stack<T> hold_stack = Stack<T>();
    int num_items = sort_stack.getSize();
    for (int i = 0; i < num_items; i++) {
        T min = sort_stack.pop();
        for (int j = i+1; j < num_items; j++) {
            T curr = sort_stack.pop();
            if (curr < min) {
                hold_stack.push(min);
                min = curr;
            }
            else {
                hold_stack.push(curr);
            }
        }
        for (int j = i+1; j < num_items; j++) {
            sort_stack.push(hold_stack.pop());
        }
        hold_stack.push(min);
    }
    for (int i = 0; i < num_items; i++) {
        sort_stack.push(hold_stack.pop());
    }
}


int main(int argc, char *argv[]) {

    Stack<int> stk1 = Stack<int>();
    stk1.push(47);
    stk1.push(12);
    stk1.push(1);
    stk1.push(1007);
    stk1.push(12);
    stk1.push(1007);
    stk1.push(1);
    StackSort(stk1);


    return 0;
}