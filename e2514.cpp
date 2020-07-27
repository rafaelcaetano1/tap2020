#include <iostream>
#include <algorithm> 

using namespace std;

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a % b ); }
int lcm( int a, int b ) { return a * (b / gcd( a, b )); }

int long m;
int l1,l2,l3;

int main()
{

    while(true)
    {
        cin >> m;
        cin >> l1 >> l2 >> l3;
        int long periodo = lcm(l3,lcm(l1,l2));
        cout << periodo-m << endl;
    }
    
    return 0;
}
