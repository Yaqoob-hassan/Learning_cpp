#include<iostream>
#include<stack>
using namespace std;

int adj[5][5]; // 5 rows 5 column
int n = 5;

void DFS(int start) {

    bool visited[5] = {false}; // No visited matrix 
    stack <int> s;

    s.push(start); // pushing -- How does compiler know the value of start 
     // Start is a parameter is value comes from main function DFS(0)

    cout << "DFS :" ;
    while(!s.empty()) { // It mean that while(stack is not emmpty as 0 is push already.)

       int node = s.top();
       s.pop();

       if(!visited[node]) 
       {

        visited[node] = true;

        cout << node << " ";

        for(int i = 0; i < n; i++) 
        {

            if(adj[node][i] == 1 && !visited[i]) {

                s.push(i);
            }
        }
       }
    }
    cout << endl;
}

int main() {
    adj[0][1] = 1;  // { T, F, F, F, F,} --  Push(0) -- stack [0]
     adj[0][2] = 1; // { T, F, T, F, F,}  pop (0) --- push neighbour ( 1, 2,) stack [1, 2] -- Display : 0
    adj[1][3] = 1;  // { T, F, T, T, F,}  pop (2) -- LIFO -- neighbour of 2 -- stack [1, 3] --  Display : 0, 2
    adj[2][3] = 1;  // { T, F, T, T, T,}  pop (3) -- neighbour (4) -- stack [1, 4] -- Display : 0, 2, 3, 
    adj[3][4] = 1;  // { T, T, T, T, T,} pop (4) -- stack [0, 2, 3, 4] -- pop(1) -- Display : 0, 2, 3, 4, 1

    DFS(0);

    return 0;
}
