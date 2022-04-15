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

void postOrder(Node *root)
{
    Node *ptr = root;
    Node *last_visited;
    vector<Node *> stack;
    while (ptr != nullptr && stack.empty())
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
            last_visited = ptr;
            cout << "visited " << ptr->data << " \n";
        }
        else
        {
            stack.push_back(ptr);
            ptr = ptr->right;
        }
    }
}

int main()
{
    int size = 11;
    Node *nodes[size];
    for (int i = 0; i < size; ++i)
        nodes[i] = new Node(i);
    assignArrayToTree(nodes, 1, size);
    postOrder(nodes[1]);
}
