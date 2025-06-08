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
    int size = neighbors.size();
    int i = 0;

    //List Conversion to array
    int arr[100] , k = 0;
   
    for (int val: neighbors)
    {
        arr[k++] = val;
    }

    for(i = 0; i<k ; i++)
    {
        int neighbour = arr[i];
        if(!visited[neighbour])
        {
            visited[neighbour] = true;
            q.push(neighbour);
        }
    }
   }

}
int main()
{
    map<int, list<int>> graph;

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);

    cout << "BFS starting From node 0 is " << endl;

    bfs(graph, 0);

    return 0;
}
