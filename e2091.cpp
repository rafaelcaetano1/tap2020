#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int num;
vector <bool> numbers(10010,false);

int main()
{
    while (cin >> num, num!=0)
    {
        array <long long,10010> a;
        for (int i=0; i < num; i++) //input and calc
        {
            cin >> a[i];
        }

        for (int i=0; i < num; i++) //calc and output
        {
            long long check = a[i];
            if (none_of(a.begin()+i, a.end(), [check](long long x){return x==check;}) )
            {
                cout << a[i] << endl;
                i = num;
            }
        }
    }
    return 0;
}
