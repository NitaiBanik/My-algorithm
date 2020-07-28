#include<bits/stdc++.h>
using namespace std;
#define ll long long
/// At first set a value by binary search;
/// then check all the value if greater or equal set 1 or zero(0)
/// 8 bits so maximum value will be 255
/// take all the mask in a set and n*n loop
/// if all bit is ON after OR operation then that mid is possible
///If possible try to check greater value
int vec[300005][10];
int mask[300005];


int main()
{
    int n,m;
    cin>>n>>m;
    int mp = 1<<m;
    mp--;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < m; j++)
            cin>>vec[i][j];
    }

    int ans1 = 0, ans2 = 0;

    int lo = 0, hi = 1000000000;

    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        set<int>st;
        set<int> :: iterator it1,it2;
        int save[mp+1];
        for(int i = 0; i< n; i++)
        {
            int mk = 0;
            for(int j = 0; j < m; j++)
                if(vec[i][j]>=mid)
                    mk|=(1<<j);
            save[mk] = i;
            st.insert(mk);
        }

        int ck = 0, k, kk;
        //  cout<<"mid = "<<mid<<endl;
        for(it1 = st.begin(); it1 != st.end(); it1++)
        {
            //cout<<*it1<<endl;
            if(ck)
                break;
            for(it2 = st.begin(); it2 != st.end(); it2++)
            {
                k = *it1;
                kk = *it2;
                if((k|kk) == mp)
                {
                    ck = 1;
                    break;
                }
            }
        }
        if(ck)
        {

            ans1 = save[k];
            ans2 = save[kk];
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout<<ans1+1<<" "<<ans2+1<<endl;
    return 0;
}
