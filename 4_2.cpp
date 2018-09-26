#include <iostream>

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

int main(int argc, char* argv[])
{
    int arr[] = {0,1,2,3,4,5,6,7};
    Node<int> *root = new Node<int>(-1);
    buildTree(arr,0,7,root);
    printTree(root,4);
    return 0;
}