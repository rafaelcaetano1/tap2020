#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi> ppi;

vector<ppi> edges;
vector<ppi> mst;
int n,m = 1;

struct disjointSets
{
    vector<int> parent, rank;
    //Constructor
    disjointSets(int n)
    {
        parent.resize(n);
        rank.resize(n);
        
        for (int i=0; i<n; i++)
        {
            parent[i] = i;
        }
    }
        
    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
        
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
   
        if(rank[x]>rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        
        if(rank[x]==rank[y])
            rank[y]++;
    }
};

void inputRead()
{
    cin >> m >> n;
    if(m!=0 and n!=0)
    {
        edges.reserve(n);
        mst.reserve(m-1);
    
        for(int i=0;i<n;i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
        
            edges.push_back(make_pair(z, make_pair(x,y)));
        }
    }
};

void kruskal()
{
    sort(edges.begin(),edges.end());
    disjointSets ds(m);
    
    int c=0;
    
    vector<ppi>::iterator it;
    
    for(it=edges.begin();c<n;it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        
        if(set_u!=set_v)
        {
            mst.push_back(make_pair(it->first,make_pair(u,v)));
            
            ds.merge(set_u,set_v);
            c++;
        }
    }
}

int custo_anterior, novo_custo;

int main()
{
    do
    {
        inputRead();
        if(m==0 and n==0)
            break;
        kruskal();
    
        vector<ppi>::iterator it;
        for(it=mst.begin();it!=mst.end();it++)
        {
            int w = it->first;
            novo_custo += w;

        }
        
        vector<ppi>::iterator it2;
        for(it2=edges.begin();it2!=edges.end();it2++)
        {
            int w = it2->first;
            custo_anterior += w;
        }
    
        cout << custo_anterior-novo_custo;
    } while(true);
}
