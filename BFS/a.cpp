#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,save;
    long long pos,ck,sum = 0;
    long long mn  =99999999;
    cin>>s;
    save = s;
    //sort(save.begin(),save.end());
    int k = 0;
    vector<int>vec;
    int i;
    for(i=0; i<s.size(); i++)
    {
        if(s[i] == '2')
            vec.push_back(i);
    }
    for(i=0; i<vec.size(); i++)
        sum+=(vec[i] - i);

    mn= min(mn,sum);
    sum = 0;
    vec.clear();
    for(i=0; i<s.size(); i++)
    {
        if(s[i] == '1')
            vec.push_back(i);
    }
    for(i=0; i<vec.size(); i++)
        sum+=(vec[i] - i);
    mn= min(mn,sum);
    cout<<mn<<endl;
}
