#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

void bfs(map<int, list<int>> &graph, int start)
{
   map<int, bool> visited;

   queue<int> q; 

   visited[start] = true;
   q.push(start);

   while(!q.empty())
   {
    int node = q.front();
    q.pop();
    cout << node << " ";


    list<int> neighbors = graph[node];
    

   
    for (int val: neighbors)
    {
        if(!visited[val])
        {
            visited[val] = true;
            q.push(val);
        }
    }
   }

}
int main()
{
    map<int , list<int>> graph;

    graph[10].push_back(20);

    graph[10].push_back(50);
    graph[20].push_back(30);
    graph[30].push_back(40);
    graph[40].push_back(50);

    cout << "BFS starting From node 0 is " << endl;

    bfs(graph, 10);

    return 0;
}
