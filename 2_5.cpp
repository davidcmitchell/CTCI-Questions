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
            while (curr->next != nullptr)
            {
                Node *curr_ahead = curr;
                while (curr_ahead->next != nullptr)
                {
                    while (curr_ahead->next != nullptr && curr_ahead->next->data == curr->data)
                    {
                        curr_ahead->next = std::move(curr_ahead->next->next);
                    }
                    if (curr_ahead->next != nullptr)
                    {
                        curr_ahead = curr_ahead->next.get();
                    }
                }
                curr = curr->next.get();
            }
        }

        Node* returnKthLast(int k) {
            int count = 0;
            Node * curr = head.get();
            while (curr != nullptr)
            {
                count++;
                curr = curr->next.get();
            }
            curr = head.get();
            for (int i = 0; i < count-k; i++)
            {
                curr = curr->next.get();
            }
            return curr;

        }

        void deleteMiddleNode(Node *mid) {
            mid->data = mid->next->data;
            mid->next = std::move(mid->next->next);
        }

        void partition(int p) {
            Node *slow = head.get();
            while (slow != nullptr)
            {
                if (slow->data < p)
                {
                    slow = slow->next.get();
                }
                else
                {
                    Node *fast = slow->next.get();
                    while (fast != nullptr)
                    {
                        if (fast->data < p)
                        {
                            int tmp = slow->data;
                            slow->data = fast->data;
                            fast->data = tmp;
                            slow = slow->next.get();
                            break;
                        }
                        fast = fast->next.get();
                    }
                    if (fast == nullptr)
                    {
                        break;
                    }
                }

            }
        }

        std::unique_ptr<Node> head;

};

LinkedList* addLinkedLists(LinkedList & l1, LinkedList &l2)
{
    LinkedList *ll = new LinkedList(new Node(0));
    Node *sum_pos = ll->head.get();
    Node *l1_pos = l1.head.get();
    Node *l2_pos = l2.head.get();
    while (l1_pos != nullptr || l2_pos != nullptr)
    {
        int sum;
        if (l1_pos != nullptr && l2_pos != nullptr)
        {
            sum = l1_pos->data + l2_pos->data;
            l1_pos = l1_pos->next.get();
            l2_pos = l2_pos->next.get();

        }
        else if (l1_pos != nullptr)
        {
            sum = l1_pos->data;
            l1_pos = l1_pos->next.get();
        }
        else
        {
            sum = l2_pos->data;
            l2_pos = l2_pos->next.get();
        }
        sum_pos->data += sum % 10;
        if (sum/10 != 0)
        {
            sum_pos->next = std::unique_ptr<Node>(new Node(sum/10));        
        }
        else if (l1_pos != nullptr || l2_pos != nullptr)
        {
            sum_pos->next = std::unique_ptr<Node>(new Node(0));
        }
        sum_pos = sum_pos->next.get();
    }
    return ll;
}


int main() {

    LinkedList l1(new Node(7, new Node(7, new Node(9))));
    LinkedList l2(new Node(5, new Node(9, new Node(2))));
    LinkedList *ll = addLinkedLists(l1,l2);
    ll->printList();

}

