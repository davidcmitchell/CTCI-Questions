#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

template <class T>
class Node 
{
public:
    Node(T item);
    Node* left_child;
    Node* right_child;
    T data;
};

template <class T>
Node<T>::Node(T item) : left_child(nullptr), right_child(nullptr), data(item) {};

void buildTree(int arr[], int lo, int hi, Node<int> *root)
{
    if (lo > hi)
        return;
    int mid = ((hi-lo)/2)+lo;
    root->data = arr[mid];
    if (lo <= mid-1)
    {
        root->left_child = new Node<int>(-1);
        buildTree(arr,lo,mid-1,root->left_child);
    }
    if (mid+1 <= hi)
    {
        root->right_child = new Node<int>(-1);
        buildTree(arr,mid+1,hi,root->right_child);
    }    
}

void printTree(Node<int> *root,int tabs)
{
    if (root == nullptr)
        return;
    for (int i = 0; i < tabs; i++)
    {
        std::cout << "  "; 
    }
    std::cout << root->data << std::endl;
    printTree(root->left_child,tabs-1);
    printTree(root->right_child,tabs+1);
}

vector<list<Node<int>*> > buildLinkedLists(Node<int> *root)
{
    vector<list<Node<int>*> > lists = vector<list<Node<int>*> >();
    queue<Node<int> *> q = queue<Node<int> *>();
    lists.push_back(list<Node<int>* >());
    q.push(root);
    int count = 0;
    int depth = 1;
    while( !q.empty() )
    {
        if (pow(2,depth)-1 == count)
        {
            depth++;
            lists.push_back(list<Node<int>* >());
        }
        Node<int> *curr = q.front();
        q.pop();
        lists[depth-1].push_back(curr);
        if (curr->left_child != nullptr)
        {
            q.push(curr->left_child);
        }
        if (curr->right_child != nullptr)
        {
            q.push(curr->right_child);
        }
        count++;
    }
    return lists;

}

int isBalanced(Node<int>* root, int height)
{
    int lh, rh;
    if (root->left_child != nullptr)
    {
        lh = isBalanced(root->left_child,height+1);
        if (lh == -1)
            return -1;
    }
    else
        lh = height;
    
    if (root->right_child != nullptr)
    {
        rh = isBalanced(root->right_child,height+1);
        if (rh == -1)
            return -1;
    }
    else
        rh = height;

    int max, min;
    if (rh > lh)
    {
        max = rh;
        min = lh;
    }
    else
    {
        max = lh;
        min = rh;
    }
    if (max - min > 1)
        return -1;
    return max;
}

int main(int argc, char* argv[])
{
    int arr[] = {0,1,2,3,4,5,6,7};
    Node<int> *root = new Node<int>(-1);
    buildTree(arr,0,7,root);
    printTree(root,4);
    int res = isBalanced(root,0);
    return 0;
}