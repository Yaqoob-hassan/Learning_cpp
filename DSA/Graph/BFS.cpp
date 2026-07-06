#include<iostream>
#include<queue>
using namespace std;

int adj[5][5]; //  5 * 5 matrix 
int n = 5;

void BFS(int start)
 {

    bool visited[5] = {false}; // 
    queue <int> q;

    visited[start] = true;
    q.push(start);//  0

    while(!q.empty()) 
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i = 0; i < n; i++ )
        {
            if(adj[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[2][3] = 1;
    adj[3][4] = 1;

    BFS(0);

    return 0;
}