#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi adjList[50001];
int numberOfMutualFriends[50001];

int dfs(int u){
    if(numberOfMutualFriends[u]!= -1)
        return numberOfMutualFriends[u];
    numberOfMutualFriends[u]=0;
    for(int neighbour: adjList[u]){
        numberOfMutualFriends[u] = max(1+dfs(neighbour),numberOfMutualFriends[u]);
    }
    return numberOfMutualFriends[u];
}


int main()
{
    int T;
    cin>>T;
    int i=0;
    while(T--){
        memset(numberOfMutualFriends, -1, sizeof numberOfMutualFriends);
        int N; cin>>N;
        for(int i = 0; i < N;++i){
            int u, v; cin>>u>>v;
            adjList[u].push_back(v);
        }
        for(int i = 1; i <= N;++i){
            dfs(i);
        }
        int m = 0;
        for(int i = 1; i <= N;++i){
            if(numberOfMutualFriends[i] > numberOfMutualFriends[m])
                m = i;
        }
        cout<<"Case "<<++i<<": "<<m;
    }
}