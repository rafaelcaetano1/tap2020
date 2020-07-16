#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi> ppi;

vector<ppi> edges;
vector<ppi> mst;
int n,m;

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
    cin >> n >> m;
    
    edges.reserve(m);
    mst.reserve(n-1);
    
    for(int i=0;i<m;i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        
        edges.push_back(make_pair(c, make_pair(u,v)));
    }
};

void kruskal()
{
    sort(edges.begin(),edges.end());
    disjointSets ds(n);
    
    int c=1;
    
    vector<ppi>::iterator it;
    
    for(it=edges.begin();c<n;it++)
    {
        
        int n1 = it->second.first;
        int n2 = it->second.second;
        
        int set_n1 = ds.find(n1);
        int set_n2 = ds.find(n2);
        
        if(set_n1!=set_n2)
        {
            mst.push_back(make_pair(it->first,make_pair(n1,n2)));
            
            ds.merge(set_n1,set_n2);
            c++;
        }
    }
}
    
int main()
{
    inputRead();
    kruskal();
    
    int total;
    vector<ppi>::iterator it;
    for(it=mst.begin();it!=mst.end();it++)
    {
        total += it->first;
    }
    
    cout << total << endl;
    edges.clear();
    mst.clear();
}
