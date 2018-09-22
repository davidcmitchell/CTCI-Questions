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

Node* intersect(LinkedList & l1, LinkedList & l2)
{
    Node* l1p = l1.head.get();
    int l1c = 0;
    Node* l2p = l2.head.get();
    int l2c = 0;
    
    while (l1p->next != nullptr || l2p->next != nullptr)
    {
        if (l1p->next != nullptr)
        {
            l1p = l1p->next.get();
            l1c++;
        }
        if (l2p->next != nullptr)
        {
            l2p = l2p->next.get();
            l2c++;
        }
    }
    if (l1p != l2p)
    {
        return nullptr;
    }

    l1p = l1.head.get();
    l2p = l2.head.get();

    while (l1c > l2c)
    {
        l1p = l1p->next.get();
        l1c--;
    }
    while (l2c > l1c)
    {
        l2p = l2p->next.get();
        l2c--;
    }
    while (l1p != l2p)
    {
        l1p = l1p->next.get();
        l2p = l2p->next.get();
    }
    
    return l1p;
}

Node *loopDetection(LinkedList & ll)
{
    Node *pos1 = ll.head.get();
    Node *pos2 = ll.head.get();
    if (pos2->next == nullptr)
    {
        return nullptr;
    }
    pos2 = pos2->next.get();
    while (pos1 != pos2)
    {
        if (pos2->next == nullptr || pos2->next->next == nullptr)
        {
            return nullptr;
        }
        pos1 = pos1->next.get();
        pos2 = pos2->next->next.get();
    }

    //node are now == size of distance from start of loop to head of loop
    pos2 = ll.head.get();
    while (pos1 != pos2)
    {
        pos1 = pos1->next.get();
        pos2 = pos2->next.get();
    }
    return pos1;
}


int main() {

    
}

