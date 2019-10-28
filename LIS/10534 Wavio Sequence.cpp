#include<bits/stdc++.h>
using namespace std;
vector<int>input;
int arr[100005];
int n;
vector<int>lis()
{
    vector<int>chk,ans;
    chk.push_back(-1000000000);
    for(int i = 1; i<= n; i++)
        chk.push_back(1000000000);
    ans.push_back(-1000000000);
    for(int i = 1; i<= n; i++)
    {
        int id = lower_bound(chk.begin(),chk.end(),input[i]) - chk.begin();
        chk[id] = input[i];
        ans.push_back(id);

    }
    return ans;
}
int main()
{
    int t,w = 0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        input.push_back(0);
        for(int i = 1; i<= n; i++)
        {
            scanf("%d",&arr[i]);
            input.push_back(arr[i]);
        }

        vector<int>w1 = lis();
//        for(int i = 0; i< w.size(); i++)
//            cout<<w[i]<<" ";
        input.clear();
        input.push_back(0);

        for(int i = n; i>=1; i--)
        {
            input.push_back(arr[i]);
        }

        vector<int>w2 = lis();
        w2.push_back(-1000000000);
        reverse(w2.begin(),w2.end());

        int mx = 0;

        for(int i = 1; i<= n; i++)
            mx = max(mx,min(w1[i],w2[i]));

        printf("Case %d: %d\n",++w,mx + mx - 1);
        input.clear();
    }

    return 0;
}
