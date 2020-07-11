#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

//N,NE,L,SE,S,SO,O,NO
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

int main()
{
    int testes;
    cin >> testes;
    for(int n=0;n!=testes;n++)
    {
        int a,b;
        cin >> a >> b;
        int pomar[a+2][b+2];
        int parent[a+2][b+2];
        int sequence[a+2][b+2];
        for(int i=0;i!=a;i++)
        {
            for(int j=0;j!=b;j++)
            {
                cin >> pomar[i+1][j+1];
            }
        }
        
        for(int i=0;i!=b+2;i++)
        {
            pomar[0][i]=0;
            pomar[a+1][i]=0;
        }
        
        for(int i=0;i!=a+2;i++)
        {
            pomar[i][0]=0;
            pomar[i][b+1]=0;
        }
        
        for(int i=0;i!=a+2;i++)
        {
            for(int j=0;j!=b+2;j++)
            {
                parent[i][j]=-2;
                sequence[i][j]=-1;
            }
        }
        
        int xs,ys;
        cin >> xs >> ys;
        
        queue<pair<int,int>> q;
        
        q.push({xs,ys});
        
        int seq = 0;
        parent[xs][ys] = 1;
        sequence[xs][ys]= 0;
        while(!q.empty())
        {
            pair<int,int> v = q.front();
            q.pop();
            
            int seq_atual = sequence[v.first][v.second];
            
            for(int i=0;i<8;i++)
            {
                int nX = v.first + dx[i];
                int nY = v.second + dy[i];

                if(pomar[nX][nY]!=0)
                {
                    if(parent[nX][nY]==-2)
                    {
                        q.push({nX,nY});
                        parent[nX][nY] =1;
                        sequence[nX][nY] = seq_atual + 1;;
                    }
                }
            }
            seq = seq_atual;
        }
        
        cout << seq <<endl;
        
    }


}
