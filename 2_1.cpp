#include <iostream>
#include <memory>

class Node {
public:    
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *n) : data(d), next(n) {}
    int data;
    std::unique_ptr<Node> next;
};

class LinkedList {
    public:
        LinkedList(Node *n) : head(n) {}
        
        void printList() {
            Node *curr = head.get();
            while (curr != nullptr)
            {
                std::cout << curr->data << " ";
                curr = curr->next.get();
            }
            std::cout << std::endl;
        }

        void removeDuplicates() {
            Node *curr = head.get();
            while (curr != nullptr && curr->next != nullptr)
            {
                Node *curr_ahead = curr;
                while (curr_ahead != nullptr && curr_ahead->next != nullptr)
                {
                    while (curr_ahead->next != nullptr && curr_ahead->next->data == curr->data)
                    {
                        curr_ahead->next = std::move(curr_ahead->next->next);
                    }
                    
                    curr_ahead = curr_ahead->next.get();
                }
                curr = curr->next.get();
            }
        }

        std::unique_ptr<Node> head;

};


int main() {

    LinkedList ll(new Node(5, new Node(6, new Node(5, new Node(5)))));
    ll.printList();
    ll.removeDuplicates();
    ll.printList();
}

