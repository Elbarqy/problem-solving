#include <bits/stdc++.h>
using namespace std;
class Uva872
{
private:
    bool adjMatrix[28][28];
    int inDeg[28], n;
    bool visited[28];
    vector<char> res;
    void initVariables();
    void BackTrackSearchKhanAlgo(int u);
    template <typename lambda>
    void parseLineByDelim(lambda callback, char delim);

public:
    void populate();
    void run();
};

void Uva872::initVariables()
{
    n = 0;
    memset(adjMatrix, false, sizeof adjMatrix);
    memset(inDeg, 0, sizeof inDeg);
    memset(visited, false, sizeof visited);
}
template <typename lambda>
void Uva872::parseLineByDelim(lambda callback, char delim)
{
    string line;
    string token;
    getline(cin, line);
    stringstream ss(line);
    while (getline(ss, token, delim))
    {
        callback(token);
    }
}

void Uva872::populate()
{
    auto getChars = [&](string token)
    {
        adjMatrix[(int)token[0] - (int)'A'][(int)token[0] - (int)'A'] = true;
        ++n;
    };
    parseLineByDelim(getChars, ' ');
    auto getConstraints = [&](string token)
    {
        if (token.length() != 3)
            throw invalid_argument("If each node is one char with one comparison symbol in between length should be of 3 of each constraint");

        switch (token[1])
        {
        case '>':
            adjMatrix[(int)token[0] - (int)'A'][(int)token[2] - (int)'A'] = true;
            ++inDeg[(int)token[2] - (int)'A'];
            break;
        case '<':
            adjMatrix[(int)token[2] - (int)'A'][(int)token[0] - (int)'A'] = true;
            ++inDeg[(int)token[0] - (int)'A'];
            break;
        case '=':
            // TODO
            //  adjMatrix[][] = true;
            break;
        default:
            break;
        }
    };
    parseLineByDelim(getConstraints, ' ');
}

void Uva872::run()
{
    initVariables();
    populate();
    BackTrackSearchKhanAlgo(0);
}

void Uva872::BackTrackSearchKhanAlgo(int u)
{
    for (int i = 0; i < 28; ++i)
    {
        if (adjMatrix[i][i] && !visited[i] && inDeg[i] == 0)
        {
            for (int j = 0; j < 28; ++j)
                if (adjMatrix[i][j] && i != j)
                    --inDeg[j];
            res.push_back(char(i + 'A'));
            visited[i] = true;
            BackTrackSearchKhanAlgo(i + 1);
            res.pop_back();
            visited[i] = false;
            for (int j = 0; j < 28; ++j)
                if (adjMatrix[i][j] && i != j)
                    ++inDeg[j];
        }
    }
    if (res.size() == n)
    {
        for (char c : res)
            cout << c;
        cout << endl;
    }
}

int main()
{
    Uva872 *uva872 = new Uva872();
    uva872->run();
}