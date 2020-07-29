#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ub;
bitset<10000010> prime;
vector<ll> primelist;
vector<ll> soma_div;
vector<ll> num_divinos;

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

int sumDiv(ll n)
{
    ll i=0, p=primelist[i], ans=1;

    while(p*p<=n)
    {
        int e=0;
        while(n%p==0)
        {
            n/=p;
            e++;
        }

        ans *= ((ll) pow( (double) p, e + 1.0 ) - 1) / (p - 1);
        p = primelist[++i];
    }

    if (n != 1) ans *= ((ll) pow( (double) n, 2.0 ) - 1) / (n - 1);
    return ans;
}

void numerosdivinos(ll n)
{
    soma_div.push_back(0);
    for(ll i=1;i<=n;i++)
        soma_div.push_back(sumDiv(i));
    
    num_divinos.push_back(0);
    for(ll i=1;i<=n;i++)
    {
        ll a = soma_div[i];
        ll b = num_divinos[i-1];
        num_divinos.push_back(a+b);
    }
}




int main()
{
    ub = 100001;
    sieve(ub);
    numerosdivinos(ub);
    ll n;

    while(cin >> n , n!=0);
    {
        cout << "ok" << endl;
        cout << num_divinos[n] << endl;
    }
    return 0;
}
