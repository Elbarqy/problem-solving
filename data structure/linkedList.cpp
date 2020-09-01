#include <bits/stdc++.h>

using namespace std;

struct node
{
public:
    int value;
    struct node *next;
    node() : value(0) {}
    node(int value) { this->value = value; }
};

int main()
{
    node *root = (struct node *)malloc(sizeof(node));
    root->value = 5;
    node *temp = (struct node *)malloc(sizeof(node));
    temp = root;
    for (int i = 0; i < 10; ++i)
    {
        node *x = (struct node *)malloc(sizeof(node));
        x->value = i;
        temp->next = x;
        temp = x;
    }
    temp = (struct node *)malloc(sizeof(node));
    temp = root;
    for(int i = 0 ; i< 11 ;++i){
        cout<<temp->value <<" ";
        temp = temp->next;
    }
    return 0;
}