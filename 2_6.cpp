#include <iostream>
#include <memory>
#include <cmath>

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
    Node *l1_pos = l1.head.get();
    Node *l2_pos = l2.head.get();
    
    int count1 = 0;
    while (l1_pos != nullptr)
    {
        l1_pos = l1_pos->next.get();
        count1++;
    }

    int count2 = 0;
    while (l2_pos != nullptr)
    {
        l2_pos = l2_pos->next.get();
        count2++;
    }
    int diff = sqrt((count1-count2)*(count1-count2));
    int count;
    if (diff > 0)
    {
        std::unique_ptr<Node> newHead(new Node(0));
        Node *curr = newHead.get();
        for (int i = 1; i < diff; i++)
        {
            curr->next = std::unique_ptr<Node>(new Node(0));
            curr = curr->next.get();
        }
        if (count1 > count2)
        {
            curr->next = std::move(l2.head);
            l2.head = std::move(newHead);
            count = count1;
        }
        else
        {
            curr->next = std::move(l1.head);
            l1.head = std::move(newHead);
            count = count2;
        }
    }
    int sum = 0;
    l1_pos = l1.head.get();
    l2_pos = l2.head.get();

    for (int i = 1; i <= count; i++)
    {
        sum += l1_pos->data*pow(10,count-i)+l2_pos->data*pow(10,count-i);
        l1_pos = l1_pos->next.get();
        l2_pos = l2_pos->next.get();

    }
    LinkedList *ll = new LinkedList(new Node(0));
    Node *pos = ll->head.get();
    int digs = int(ceil(log10(sum)));
}

bool isPalindrome(Node **start, Node *end)
{
    bool result = true;
    if (end->next != nullptr)
    {
        result = isPalindrome(start, end->next.get());
    }
    if (!result)
    {
        return false;
    }
    if ((*start)->data == end->data)
    {
        *start = (*start)->next.get();
        return true;
    }
    
    return false;
}


int main() {

    LinkedList l1(new Node(1, new Node(2, new Node(9, new Node(3, new Node(1))))));
    Node *end = l1.head.get();
    Node* start = l1.head.get();
    
    if (isPalindrome(&start,end))
    {
        std::cout << "yes" << std::endl;
    }
}

