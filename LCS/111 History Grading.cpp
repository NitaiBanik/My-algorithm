#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>a,b;
ll arr1[30],arr2[30];
ll n;
ll dp[25][25];

ll lcs(int i, int j)
{
    if(i == n+1 || j == n+1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    ll ret1 = 0;

    if(arr1[i] == arr2[j])
        ret1 = max(ret1,1+lcs(i+1, j+1));


    ret1 = max(ret1,lcs(i+1,j));
    ret1 = max(ret1,lcs(i,j+1));

    return dp[i][j] = ret1;
}
int main()
{

    string s;
    while(cin>>s)
    {
x:
        stringstream ss(s);
        ll val;
        ss>>n;
        //cout<<"N = "<<n<<endl;
        a.clear();
        b.clear();
        getchar();
        getline(cin,s);
        //  cout<<"n = "<<n<<endl;
        stringstream sss(s);
        while(sss>>val)
        {
            a.push_back(val);
        }
        for(int i=0; i<a.size(); i++)
            arr1[a[i]]= i+1;

        a.clear();
        while(getline(cin,s))
        {
            if(s.size()<=2)
            {
                a.clear();
                b.clear();
                goto x;
            }
            stringstream s1(s);

            while(s1>>val)
            {
                b.push_back(val);
            }
            memset(dp,-1,sizeof(dp));

            for(int i=0; i<b.size(); i++)
                arr2[b[i]]= i+1;

            int ans = lcs(1,1);
//            cout<<"asz = "<<a.size()<<"bsz = "<<b.size()<<endl;
            cout<<ans<<endl;
            b.clear();
        }



    }
    return 0;
}
