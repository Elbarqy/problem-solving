#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char val;
    vector<Node *> children;
    bool ordered;
    Node(char passedValue)
    {
        this->val = passedValue;
        this->ordered = false;
    }
};
class KhanAlgo
{
private:
    // Assuming characters are between A-Z
    unordered_map<char, Node *> graph;
    template <typename lambda>
    void processStringByDelimetar(char delim, lambda callback)
    {
        string line, token;
        getline(cin, line);
        stringstream ss(line);
        while (getline(ss, token, delim))
        {
            callback(token[0]);
        }
    }

    void cleanUp()
    {
        for (pair<char, Node *> node : graph)
        {
            delete node.second;
        }
        graph = {};
    }

public:
    void populate()
    {
        auto initGraph = [&](char stream)
        {
            Node *node = new Node(stream);
            graph.insert(make_pair(stream, node));
        };
        processStringByDelimetar(' ', initGraph);
        auto initEdges = [&](string stream)
        {
            if (stream.length() != 3)
                throw new invalid_argument("got an invalid constraint " + stream);
            auto first = graph.find(stream[0]);
            auto second = graph.find(stream[1]);
            first->second->ordered = true;
            second->second->ordered = true;
            switch (stream[1])
            {
            case '>':
                first->second->children.push_back(second->second);
                break;
            case '<':
                second->second->children.push_back(first->second);
                break;
            case '=':
                first->second->children.push_back(second->second);
                second->second->children.push_back(first->second);
                break;
            default:
                break;
            }
        };
        }

    void process()
    {
    }

    void run()
    {
        string line;
        getline(cin, line);
        int T = stoi(line);
        while (T--)
        {
            populate();
            // CODE GOES HERE
            cleanUp();
        }
    }
};

int main()
{
    KhanAlgo *khanAlgo = new KhanAlgo();
    khanAlgo->run();
    delete khanAlgo;
}