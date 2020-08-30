#include <bits/stdc++.h>

using namespace std;

struct node{
    int value;
    struct node * left;
    struct node * right;
};

int depth(node * myNode){
    if(myNode == NULL){
        return 0;
    }else{
        int lDepth = depth(myNode->left);
        int rDepth = depth(myNode->right);
        if(lDepth > rDepth)
            return lDepth+1;
        else 
            return rDepth+1;
    }
}
int main(){
    node * x = (node * )malloc(sizeof(node));;
    node * y = (node * )malloc(sizeof(node));;
    node * z = (node * )malloc(sizeof(node));;
    x->value = 0;
    y->value = 1;
    z->value = 2;
    x->right = y;
    y->right = z;
    cout<<depth(x)<<endl;
    return 0;
}