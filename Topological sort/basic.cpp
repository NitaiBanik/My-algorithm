#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>vec[105];
bool vis[105];
vector<ll>ans;

///directed and no cycle
void visit(int u)
{
    for(int i=0; i<vec[u].size(); i++)
    {
        if(!vis[vec[u][i]])
            visit(vec[u][i]);
    }
    ans.push_back(u);
    vis[u] = 1;
}

int main()
{
    int n,edge;
    while(scanf("%d %d",&n,&edge) == 2)
    {
        if(!n && !edge) break;
        for(int i=1; i<=edge; i++)
        {
            int frm,to;

            scanf("%d %d",&frm,&to);
            vec[frm].push_back(to);
        }
        for(int i=1; i<=n; i++)
            if(!vis[i])
                visit(i);
        cout<<ans[n-1];

        for(int i=n-2; i>=0; i--)
            cout<<" "<<ans[i];
        cout<<endl;

        for(int i=0; i<=n; i++) vec[i].clear();
        memset(vis,0,sizeof(vis));
        ans.clear();
    }
    return 0;
}
