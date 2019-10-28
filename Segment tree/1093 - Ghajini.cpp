#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;

int main()
{
    int n;

    cin>>n;

    while(n--)
    {
        string w;
        cin>>w;
        if(mp.find(w) == mp.end())
        {
            cout<<"OK"<<endl;
            mp[w]++;
        }
        else
        {
            cout<<w<<mp[w]<<endl;
            mp[w]++;
        }
    }


}
