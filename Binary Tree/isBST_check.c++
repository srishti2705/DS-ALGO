#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Node* newNode(int data)
{
    Node *root = new Node;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

bool isBST(Node* root, int min, int max)
{
    if(root == NULL)
        return 1;
    if(root->data > max || root->data < min)
        return 0;
    return isBST(root->left, min,root->data-1) && isBST(root->right,root->data+1,max );
}

int main()
{
    Node* root = newNode(4);
    root->left = newNode(2);  
    root->right = newNode(5);  
    root->left->left = newNode(1);  
    root->left->right = newNode(3);
    
    if(isBST(root,INT_MIN,INT_MAX))
        cout<<"It is Binary Tree";
    else
        cout<<"It is not a Bimary Tree";
    
}