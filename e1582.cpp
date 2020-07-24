#include <iostream>
#include <algorithm> 

using namespace std;

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a % b ); }

int a,b,c;

bool isPythagorean(int a, int b, int c)
{
    int l[] = {a, b, c}; 
    sort(l, l + 3);
    if(l[2]*l[2]==(l[0]*l[0]+l[1]*l[1])) return true;
  
    return false; 
}

int main()
{
    while(true)
    {
        cin >> a >> b >> c;
        if(!isPythagorean(a,b,c))
            cout << "tripla" << endl;
            
        int d;
        d = gcd(a,b);
        if(gcd(c,d)==1)
            cout << "tripla pitagorica primitiva" << endl;
        else
            cout << "tripla pitagorica" << endl;
        
    }
}
