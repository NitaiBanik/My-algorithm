#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10005];
int visited[100005];
vector<int>v;
map<int,int>mp;
void dfs(int u)
{
    visited[u] = 1;
    for(int i=0;i<vec[u].size();i++)
    {
        int v=vec[u][i];
        if(visited[v] == 0)
        {
            //cout<<
            mp[v]++;
            dfs(v);
        }
    }
}
int main()
{
    int t,s=0;
    cin>>t;
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        int k,n,m;
        cin>>k>>n>>m;
        int x = k;
        while(k--)
        {
            int vv;
            cin>>vv;
            v.push_back(vv);
        }
        while(m--)
        {
            int f,s;
            cin>>f>>s;
            vec[f].push_back(s);
        }
        for(int  p =0; p<v.size(); p++)
        {
            memset(visited,0,sizeof(visited));
            int w = v[p];
            if(visited[w] == 0)
            {
                mp[w]++;
                dfs(w);
            }

        }
        int cnt = 0;
        //map<int,int>iterator it;
        for(int it=1;it<=n;it++)
        {
            if(mp[it] == x )
                cnt++;
        }
        cout<<"Case "<<++s<<": "<<cnt<<endl;
        mp.clear();
        v.clear();
        for(int i =0;i<=n;i++)
            vec[i].clear();

    }


}
