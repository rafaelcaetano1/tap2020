#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> pi;

map<char,int> letras;

int n,v,e;

struct disjointSets
{
    vector<int> parent, rank;
    //Constructor
    disjointSets(int n)
    {
        parent.resize(n,0);
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

void solve()
{
    letras.insert(pair<char,int>('a',0));
    letras.insert(pair<char,int>('b',1));
    letras.insert(pair<char,int>('c',2));
    letras.insert(pair<char,int>('d',3));
    letras.insert(pair<char,int>('e',4));
    letras.insert(pair<char,int>('f',5));
    letras.insert(pair<char,int>('g',6));
    letras.insert(pair<char,int>('h',7));
    letras.insert(pair<char,int>('i',8));
    letras.insert(pair<char,int>('j',9));
    letras.insert(pair<char,int>('k',10));
    letras.insert(pair<char,int>('l',11));
    letras.insert(pair<char,int>('m',12));
    letras.insert(pair<char,int>('n',13));
    letras.insert(pair<char,int>('o',14));
    letras.insert(pair<char,int>('p',15));
    letras.insert(pair<char,int>('q',16));
    letras.insert(pair<char,int>('r',17));
    letras.insert(pair<char,int>('s',18));
    letras.insert(pair<char,int>('t',19));
    letras.insert(pair<char,int>('u',20));
    letras.insert(pair<char,int>('v',21));
    letras.insert(pair<char,int>('w',22));
    letras.insert(pair<char,int>('x',23));
    letras.insert(pair<char,int>('y',24));
    letras.insert(pair<char,int>('z',25));
    
    cin >> v >> e;
    
    disjointSets ds(v);
    
    for(int i=0;i<e;i++)
    {
        char a, b;
        cin >> a >> b;

        int p1,p2;
        p1 = letras[a];
        p2 = letras[b];
        
        ds.merge(p1,p2);
    }

    for(int i=0; i<v; i++)
    {
        ds.parent[i]=ds.find(ds.parent[i]);
    }
    
    
    int counter = 0;
    vector<int> parents;
    parents.reserve(v);
    
    vector<int> letras_p;
    letras_p.reserve(v); // cada elemento tem as "letras" do correspondente em parents
    
    vector<int>::iterator it;
    
    for(int i=0;i<v;i++)
    {
        int p1 = ds.parent[i];
        it = find (parents.begin(), parents.end(), p1);
        if(it==parents.end())
        {
            parents.push_back(p1);
            counter++;
        }
        for(int j=0;j<v;j++)
        {
            if(ds.parent[j]==p1)
            {
                letras_p.push_back(j);
            }
        }
    }
    cout << "Case #1:" << endl;??
    cout << letras[letras_p[0]]->first << endl;
    cout << counter << " connected components\n\n";
    
};

    
int main()
{
    solve();
}
