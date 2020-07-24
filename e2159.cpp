#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    double lb,ub;
    
    cin >> n;
    lb = n/(log(n));
    cout << lb << endl;
    ub = 1.25506*lb;
    cout << fixed << setprecision(1) << lb << " " << ub << endl;
}
