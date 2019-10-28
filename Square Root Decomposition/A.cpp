#include<bits/stdc++.h>
using namespace std;
string str[105];

bool cmp(string a, string b)
{
    return a.size()<b.size();
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i< n ; i++)
        cin>>str[i];

    sort(str,str+n,cmp);
    int ck = 0;

    for(int i = 1; i<n; i++)
    {
        if((str[i].size() == str[i - 1].size()) && (str[i]!=str[i-1]))
            ck = 1;
        else
        {
            int fk = 0;
            int sz =str[i-1].size();
            for(int j = 0; j<str[i].size()-sz+1; j++)
            {
                string w = str[i].substr(j,sz);
                if(w == str[i-1])
                {
                    fk = 1;
                    break;
                }
            }
            if(fk == 0)
                ck = 1;
        }

    }
    if(ck)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++)
            cout<<str[i]<<endl;

    }
}
