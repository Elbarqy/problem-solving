#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    Node(int value)
    {
        this->data = value;
        this->right = NULL;
        this->left = NULL;
    }
};

int main()
{
    /*
                5 <-- root
            /        \
            2         4
        /       \   /   \
        1       8   2   9
    */
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(9);

}


void preOrderTraversal(Node* root){
    Node* p = root;
}