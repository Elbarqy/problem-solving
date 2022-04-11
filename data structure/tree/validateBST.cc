#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    };
};

bool validateBstTraversal(BST* node, int min, int max){
	bool valid = true;
	if(node->value < min || node->value >= max)
		return false;
	
	if(node->left != NULL){
		if(node->value >= node->left->value){
			valid = validateBstTraversal(node->left, min, node->value);
		}
		else{
			return false;
		}
	}
	if(node->right != NULL){
		if(node->value <= node->right->value){
			valid = valid && validateBstTraversal(node->right, node->value, max);
		}else{
			return false;
		}
	}
	return valid;
}
bool validateBst(BST *tree) {
	int INF= 999999;
	return validateBstTraversal(tree, -1*INF , INF);
}

int main()
{
    BST *head = new BST(10);
    BST *a5 = new BST(5);
    BST *a15 = new BST(15);
    BST *a10_2 = new BST(10);
    head->left = a5;
    head->right = a15;
    a5->right = a10_2;
    cout << validateBst(head) << endl;
}