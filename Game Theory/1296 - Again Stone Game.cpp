#include<bits/stdc++.h>
using namespace std;
int gd[10005];
int main()
{
    gd[0] = 0,gd[1] = 0;
    for(int i = 2; i<=50; i++)
    {
        int mid = i / 2;
        set<int>st;
        for(int j = 1; j<= mid; j++)
            st.insert(gd[j]);
        int x = 0;
        while(st.find(x) != st.end()) x++;
        gd[i] = x;
        cout<<"value = "<<i<<" Grundy = "<<x<<endl;
    }

}
