#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

void print (vector<int> v)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void listFill ( vector<int> adj[] , int n )
{
    for(int i = 1 ; i < n ; i++)
    {
        int a , b;
        cin >> a >> b;
        cout << endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void bfs ( vector<int> adj[] , int n , int start)
{
    vector<int> sol;
    vector<int> visit(n,0);
    visit[start] = 1;
    queue<int> q;
    q.push(start);
    while(q.empty() == false)
    {
        for( auto it : adj[q.front()] )
        {
            if(visit[it] == 0)
            {
                q.push(it);
                visit[it] = 1;
            }
        }
        
        sol.push_back(q.front());
        
        q.pop();
    }
    
    print(sol);
}


int main() {
    
    int n;
    int start;
    
    cout << "Enter number of nodes" << endl;
    cin >> n;
    
    vector<int> adj[n+1];
    
    listFill(adj,n+1);
    
    cout << "Enter starting node " << endl;
    cin >> start;
    
    bfs(adj,n+1,start);
    
    return 0;
}
