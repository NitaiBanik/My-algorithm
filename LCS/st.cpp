#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,st;
        s+='0';
        cin>>st;
        st+='0';
        s+=st;
        int m = 0,ss = 0;
        for(int i=1;i<s.size()-1;i++)
        {
            if(s[i] == 'm' && s[i-1] == 's') s[i-1] = '0';
            else if(s[i] == 'm' && s[i+1] == 's') s[i+1] = '0';
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'm') m++;
            if(s[i] == 's') ss++;
        }
        if(m == ss) cout<<"tie"<<endl;
        else if(m>ss)
            cout<<"mongooses"<<endl;
        else
            cout<<"snakes"<<endl;


    }
}
