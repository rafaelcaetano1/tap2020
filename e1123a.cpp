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

void outputWrite ()
{
    for (int i = 0; i < 9; i++)
    {
        cout << setw (2) << i << " : (" << setw (2) << dist[i] << " vindo de " << parent[i] << endl;
        
        /*int j = parent[i];
        while (j != -1)
        {
            cout << " -> " << j;
            j = parent[j];
        }*/
        //cout << endl;
    }
}

void dijkstra (int source)
{
    // Min heap where: first = weight , second = vertex
    priority_queue <pi , vector <pi>, greater <pi>> pq;
    pq.push(make_pair(0,source));

    dist[source] = 0; // Distance from source to itself is 0

    list <pi>::iterator it;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int v = pq.top().second;
        cout << "vamos olhar pro " << v << endl;
        pq.pop();
        if(visited[v]) continue; // Vertex already processed
        
        visited[v] = true;
        
        
        if(route[v])
        {
            cout << "é parte da rota" << endl;
            //adicionar o proximo ponto da rota na fila com o peso
            
            //pq.push(make_pair(####,v+1));
            
            
            for(int v_aux = v+1;v_aux!=c;v_aux++)
            {
                cout << "o ponto seguinte é " << v_aux << endl;
                int w_aux;
                for(it = graph[v_aux].begin(); it!=graph[v_aux].end();++it)
                {
                    if(it->second == v_aux-1)
                    {
                        w_aux = it->first;
                        cout << "a dist até " << v_aux <<  " é " << w_aux << endl;
                        break;
                    }
                }
                cout << "blz" << endl;
                cout << "até agora dist pro " << v_aux << " é de "<< dist[v_aux] << endl;
                cout << "o acumulado até o anterior é " << dist[v_aux-1] << endl;
                if(dist[v_aux] > dist[v_aux-1] + w_aux)
                {
                    parent[v_aux] = v_aux-1;
                    dist[v_aux] = dist[v_aux-1] + w_aux;
                    cout << dist[v_aux] << endl;//aaaaaaa
                    pq.push(make_pair(dist[it->second],it->second));
                }
                
            }
        }
        
        else
        {
            cout << "n é parte da rota" << endl;
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
        cout << "distancia pro destino " << dist[3] << endl;
        outputWrite();
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
