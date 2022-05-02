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
auto initGraph = [&](char stream)
{
    Node *node = new Node(stream);
    graph.insert(make_pair(stream, node));
};