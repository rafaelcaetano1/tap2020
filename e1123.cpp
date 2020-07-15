#include <iostream>
#include <iomanip>
#include <list>
#include <queue>
#include <vector>

using namespace std;

typedef pair <int, int> pi;

const int INF = 0x3f3f3f3f; 
vector <list <pi>> graph; // Adjacency list
vector <int> dist; // Vector solution
vector <int> parent; // The shortest paths
vector <bool> visited; // Control vector
vector <bool> route;
int n, m, c, k; 

void inputRead ()
{
    dist.resize(n, INF);
    parent.resize(n,-1);
    visited.resize(n,false);
    graph.resize(n);
    route.resize(n,false);
    
    for(int i=0;i!=c;i++)
    {
        route[i] = true;
    }

    for(int i = 0; i < m; i++)
    {
        int from , to , weight;

        cin >> from >> to >> weight;

        graph[from]. push_back(make_pair(weight,to));
        graph[to]. push_back(make_pair(weight,from));
    }
}

void dijkstra (int source)
{
    // Min heap where: first = weight , second = vertex
    priority_queue <pi , vector <pi>, greater <pi>> pq;
    pq.push( make_pair(0,source));

    dist[source] = 0; // Distance from source to itself is 0

    list <pi>::iterator it;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int v = pq.top().second;
        
        pq.pop();
        if(visited[v]) continue; // Vertex already processed
        
        visited[v] = true;
        
        
        if(route[v])
        {
            for(int v_aux = v+1;v_aux!=c;v_aux++)
            {
                int w_aux;
                for(it = graph[v_aux].begin(); it!=graph[v_aux].end();++it)
                {
                    if(it->second == v_aux-1)
                    {
                        w_aux = it->first;
                        break;
                    }
                }
                dist[v_aux] = weight + w_aux;
            }
        }
        
        else
        {
            for(it = graph[v].begin(); it!=graph[v].end();++it)
            {
                if(dist[it->second] > weight + it->first)
                {
                    parent[it->second] = v;
                    dist[it->second] = weight + it ->first;
                    pq.push(make_pair(dist[it->second],it->second));
                }
            }
        }
    }
}

void clear_all()
{
    graph.clear();
    dist.clear();
    parent.clear();
    visited.clear();
    route.clear();
}

int main()
{
    while(cin >> n >> m >> c >> k, n!=0)
    {
        inputRead();
        dijkstra(k);
        cout << dist[c-1] << endl;
        clear_all();
    }
}
