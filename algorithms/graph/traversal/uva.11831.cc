#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi adjList[503];
int xDir[4] = {0, 1, 0, -1};
int yDir[4] = {-1, 0, 1, 0};
int orientation = 0;
bool hor = false;
void definePosition(int &pos, char *arena, int &current)
{
    switch (arena[current])
    {
    case 'N':
        pos = current;
        orientation = 0;
        break;
    case 'L':
        pos = current;
        orientation = 1;
        break;
    case 'S':
        pos = current;
        orientation = 2;
        break;
    case 'O':
        pos = current;
        orientation = 3;
        break;
    default:
        break;
    }
}

int main()
{
    int N, M, S;
    int pos = 0;
    while (true)
    {
        cin >> N >> M >> S;
        if (N == M && N == 0)
            break;
        char *arena = new char[N * M + 2];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                int curr = j + i * N;
                cin >> arena[curr];
                definePosition(pos, arena, curr);
            }
        int reward = 0;
        while (S != 0)
        {
            char command;
            cin >> command;
            int nextPosition;
            switch (command)
            {
            case 'F':
                nextPosition = pos + xDir[orientation] + yDir[orientation] * N;
                if (nextPosition < 0 || nextPosition >= N * N || arena[nextPosition] == '#')
                    break;
                if (arena[nextPosition] == '*')
                    ++reward;
                pos = nextPosition;
                break;
            case 'D':
                orientation = (orientation + 1) % 4;
                break;
            default:
                orientation = (orientation - 1) % 4;
                break;
            }
            --S;
        }
        cout << reward << "\n";
        delete[] arena;
    }
}
