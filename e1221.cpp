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
    int cases;

    ub = 70000;
    sieve(ub);
    
    cin >> cases;
    for(int a=0;a<cases;a++)
    {
        ll test;
        cin >> test;
        cout << (isPrime(test) ? "Prime" : "Not Prime") << endl;
    }
    
    return 0;
}
