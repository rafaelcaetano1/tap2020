#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int n, k, a, b;
char op;

int main()
{
    cin >> n >> k;
    
    disjointSets ds(n);
    
    for(int i=0;i!=k;i++)
    {
        cin >> op >> a >> b;
        if(op=='F')
            ds.merge(a-1,b-1);
        else
        {
            ds.parent[a-1]=ds.find(ds.parent[a-1]); //atualizar
            ds.parent[b-1]=ds.find(ds.parent[b-1]);
            cout << ((ds.parent[a-1]==ds.parent[b-1]) ? "S" : "N") << endl;
        }

    }
    return 0;
}
