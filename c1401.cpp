#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string word;
    vector<char> v;
    
    getline(cin, word);
    int tamanho = word.length();
    v.resize(tamanho);

    for (int i = 0; i < tamanho; i++)
        v.push_back(word[i]);

    sort(v.begin(),v.end());
    
    for(int i=0;i<tamanho;i++) //i:primeiro char
    {
        
    }
}
