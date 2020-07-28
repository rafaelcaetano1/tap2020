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

int nbDiv(ll n)
{
    int i=0, p=primelist[i], ans=1;
    
    while(p*p<=n)
    {
        int e=0;
        while(n%p==0)
        {
            n/=p;
            e++;
        }
        
        ans *= (e+1);
        p = primelist[++i];
    }
    
    if(n!=1) ans *= 2;
    
    return ans;
}


ll n;

int main()
{
    ub = 1000010;
    sieve(ub);
    
    while(cin >> n)
    {
        ll counter = 0;
        for(ll i=2;i<=n;i++)
        {
            if(isPrime(nbDiv(n))) counter++;
        }
        
        cout << counter << endl;
// fazer tabela de hiperprimos
    }
    
    return 0;
}
