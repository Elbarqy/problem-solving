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
        this->right = nullptr;
        this->left = nullptr;
    }
};

bool isBalanced(Node *root)
{
    Node *ptr = root;
    vector<Node *> stack;
    Node *last_visited;
    int minHeight = 1000000;
    int maxHeight = -1;
    while (ptr != nullptr && last_visited != root)
    {
        while (ptr != nullptr && ptr != last_visited)
        {
            stack.push_back(ptr);
            ptr = ptr->left;
        }
        ptr = stack.back();
        stack.pop_back();

        if (ptr->right == nullptr || ptr->right == last_visited)
        {
            if (ptr->left == nullptr && ptr->right == nullptr)
            {
                int size = stack.size();
                if (size < minHeight)
                {
                    minHeight = size;
                }
                if (size > maxHeight)
                {
                    maxHeight = size;
                }
            }
            last_visited = ptr;
        }
        else
        {
            stack.push_back(ptr);
            ptr = ptr->right;
        }
    }
    return maxHeight - minHeight <= 1;
}

void assignArrayToTree(Node *nodeArr[], int idx, int size)
{
    if (idx * 2 + 1 > size - 2)
        return;
    nodeArr[idx]->left = nodeArr[idx * 2];
    nodeArr[idx]->right = nodeArr[idx * 2 + 1];
    cout << "Assigned " << idx << " to " << idx * 2 << " " << idx * 2 + 1 << "\n";
    assignArrayToTree(nodeArr, idx * 2, size);
    assignArrayToTree(nodeArr, idx * 2 + 1, size);
}

int main()
{
    int size = 11;
    Node *nodes[size];
    for (int i = 0; i < size; ++i)
        nodes[i] = new Node(i);
    Node *add1 = new Node(-1);
    Node *add2 = new Node(-2);
    nodes[6]->right = add1;
    add1->left = add2;
    assignArrayToTree(nodes, 1, size);
    bool res = isBalanced(nodes[1]);
    cout << res << endl;
}

pair<bool, int> isbalance(Node *root)
{
    if (root == nullptr)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> l = isbalance(root->left);
    pair<bool, int> r = isbalance(root->right);
    bool left = l.first;
    bool right = r.first;
    bool diff = abs(l.second - r.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(l.second, r.second) + 1;
    if (left & right & diff)
        ans.first = true;
    else
        ans.first = false;
    return ans;
}