#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> pi;

map<string,int> people;
vector<pi> relations;

int n,m;

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


void map_people(string personX)
{
    if(people.count(personX)==0)
    {
        int size = people.size();
        people.insert(make_pair(personX,size));
    }
    
};

void solve()
{
    cin >> m >> n;
    
    disjointSets ds(m);
    
    for(int i=0;i<n;i++)
    {
        string person1, to, person2;
        cin >> person1 >> to >> person2;
        
        map_people(person1);
        map_people(person2);
        
        int p1,p2;
        p1 = people[person1];
        p2 = people[person2];
        
        ds.merge(p1,p2);
    }

    for(int i=0; i<m; i++)
    {
        ds.parent[i]=ds.find(ds.parent[i]);
    }
    
    
    int counter = 0;
    vector<int> parents;
    parents.reserve(m);
    
    vector<int>::iterator it;
    
    for(int i=0;i<m;i++)
    {
        int p1 = ds.parent[i];
        it = find (parents.begin(), parents.end(), p1);
        if(it==parents.end())
        {
            parents.push_back(p1);
            counter++;
        }
    }
    
    cout << counter;
    
};

    
int main()
{
    solve();
}
