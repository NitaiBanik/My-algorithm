#include<bits/stdc++.h>
using namespace std;

int col[100005];
bool vis[100005];
vector<int>graph[100005];
struct st
{
    int u,v;
} arr[100005];
int ck;
void dfs(int src, int colr)
{

    if(vis[src] == true)
        return;
    vis[src] = true;

    for(int i=0; i<graph[src].size(); i++)
    {
        int x = graph[src][i];
        if(vis[x] == true) continue;
        else if(col[x]!=colr)
        {
            ck = 1;
           cout<<"Src = "<<src<<" color = "<<col[src]<<endl;
           cout<<"nod = "<<x<<" color = "<<col[x]<<endl;
            return;
        }
        else
            dfs(x,col[x]);
    }
}
int main()
{
    int n,u,v;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        arr[i].u = u;
        arr[i].v = v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<n; i++)
        scanf("%d",&col[i]);

    int node1 = 0,node2 = 0;
    for(int i=1; i<n; i++)
    {
        if(col[arr[i].u]!=col[arr[i].v])
        {
            node1 = arr[i].u;
            node2 = arr[i].v;
            break;
        }
    }
    cout<<"Nod1 = "<<node1<<" "<<"nod2 = "<<node2<<endl;
    if(node1 == node2 && node1 == 0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    ck = 0;
    vis[node1] = true;

    for(int i=0; i<graph[node1].size(); i++)
    {
        int x = graph[node1][i];
        if(vis[x] == false)
            dfs(x,col[x]);
    }
    if(!ck)
    {
        cout<<"YES"<<endl;
        cout<<node1<<endl;
        return 0;
    }
    memset(vis,false,sizeof(vis));
    vis[node2] = true;
    ck = 0;
    for(int i=0; i<graph[node2].size(); i++)
    {
        int x = graph[node2][i];
        if(vis[x] == false)
            dfs(x,col[x]);
    }
    if(!ck)
    {
        cout<<"YES"<<endl;
        cout<<node2<<endl;
        return 0;
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
