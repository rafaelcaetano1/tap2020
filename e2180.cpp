#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ub;
bitset<10000010> prime;

vector<ll> primelist;

void sieve(ll n)
{
    prime.set();
    prime[0] = 0;
    prime[1] = 0;
    for(ll i=4; i<=n; i+=2)
        prime[i]=0;
    
    for(ll i=3; (i*i)<=n; i+=2)
        if(prime[i])
        {
            for(ll j= i*i; j<n; j+=i)
                prime[j]=0;
        }
    
    for(ll i=2; i<=n; i++)
    {
        if(prime[i])
            primelist.push_back(i);
    }
}


bool isPrime(ll n)
{
    if(n<=ub) return prime[n];
    
    for(int i=0; i<(int)primelist.size(); i++)
    {
        if(n%primelist[i]==0)
            return false;
    }
    
    return true;
}


int main()
{
    int peso;
    int c = 0;
    ll vmax = 0;

    ub = 70000;
    sieve(ub);
    
    cin >> peso;
    for(ll a=peso;c<10;a++)
    {
        if(isPrime(a))
        {
            vmax += a;
            c++;
        }
    }
    
    int long th = 60000000/vmax;
    int long td = th/24;
    
    cout << vmax << " km/h" << endl;
    cout << th << " h / " << td << " d" << endl;
    
    return 0;
}
