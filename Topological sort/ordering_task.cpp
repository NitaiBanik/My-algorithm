#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>vec[105];
bool vis[105];
int ind[105];
vector<ll>ans;

///directed and no cycle
void visit(int u)
{
    vis[u] = 1;
    for(int i=0; i<vec[u].size(); i++)
    {
        if(!vis[vec[u][i]])
            visit(vec[u][i]);
    }
    ans.push_back(u);

}

int main()
{
    int n,edge;
    scanf("%d %d",&n,&edge)
    for(int i=1; i<=edge; i++)
    {
        int frm,to;

        scanf("%d %d",&frm,&to);
        vec[frm].push_back(to);
        vec[to].push_back(frm);
        ind[to] = 1;
    }
    for(int i=1; i<=n; i++)
        if(!ind[i])
            visit(i);
    cout<<ans[n-1];

    for(int i=n-2; i>=0; i--)
        cout<<" "<<ans[i];
    cout<<endl;

    for(int i=0; i<=n; i++)
        vec[i].clear();
    memset(vis,0,sizeof(vis));
    memset(ind,0,sizeof(ind));
    ans.clear();
}
return 0;
}
