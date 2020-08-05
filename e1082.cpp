#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_let (char c, vector<char> v)
{
    int i;
    for(i=0;i<26;i++)
        {
            if(v[i]==c)
                return i;
        }
};

int main()
{
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

    int n, v, e, i, j = 0;

    cin >> n;
    
    for(j=0;j<n;j++)
    {
    cin >> v >> e;
    disjointSets d(v);
    char a, b;
    vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
        for(i=0;i<e;i++)
        {
            cin >> a >> b;
            int na, nb;
            na = num_let(a,letters);
            nb = num_let(b,letters);
            d.merge(na,nb);
        }
        for(int i=0;i<v;i++) d.parent[i]=d.find(i);

        //checar o parent do primeiro, escrever todo mundo que tem igual, depois apagar e repetir o processo
        int counter = 0;
        cout << "Case #" << j+1 << ":\n";
        while(not d.parent.empty())            //verifica se o vetor está vazio
        {
            counter++;
            int parent1;
            parent1 = d.parent[0];           //salva o parent do primeiro elemento
            for(i=0;i<d.parent.size();i++)
            {
                if(d.parent[i]==parent1)    // escreve todos que tem o mesmo parent do primeiro elemento
                {
                    cout << letters[i] << ",";
                    letters[i] = 'A';       // troca a letra escrita por uma flag
                }
            }
            cout << "\n";
            d.parent.erase(remove(d.parent.begin(),d.parent.end(),parent1),d.parent.end());
            letters.erase(remove(letters.begin(),letters.end(),'A'),letters.end());
        }
    
        cout << counter << " connected components\n\n";
    }
}
