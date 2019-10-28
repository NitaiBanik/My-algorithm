#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2000000000000
vector<ll>seq,ans,idx;

int main()
{

    int n = 0;
    seq.push_back(0);
    ans.push_back(-5);
    idx.push_back(-inf);
    ll val;
    while(scanf("%lld", &val) == 1)
    {
        n++;

        seq.push_back(val);
        idx.push_back(inf);

    }
    int mx = 0;
    for(int i = 1; i<= n; i++)
    {
        int id = lower_bound(idx.begin(),idx.end(),seq[i]) - idx.begin();
        idx[id] = seq[i];
        ans.push_back(id);
        mx = max(mx,id);
    }

    cout<<mx<<endl<<"-"<<endl;
    idx.clear();
    ll vall = 2 * inf;
    for(int i = n; i >= 1; i--)
    {
       // cout<<ans[i]<<" "<<" seq = "<<seq[i]<<" vall = "<<vall<<endl;
        if((ans[i] == mx) && (seq[i]< vall))
        {
            vall = seq[i];
            mx--;
            idx.push_back(seq[i]);
            //cout<<seq[i]<<endl;
        }
    }
    reverse(idx.begin(), idx.end());
    for(int i = 0; i < idx.size() ; i++)
        printf("%lld\n",idx[i]);
}
