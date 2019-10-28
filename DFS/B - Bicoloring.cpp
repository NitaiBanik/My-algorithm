#include<bits/stdc++.h>
using namespace std;
vector<int>vec[205];
int visited[205],p,my;
int colour[205];
void dfs(int u)
{
    visited[u] = 1;
    for(int i=0; i<vec[u].size(); i++)
    {
        int k = vec[u][i];
        if(visited[k] == 0)
        {
            if(colour[u] == 1)
                colour[k] = 2;
            else if(colour[u] == 2)
                colour[k] = 1;
            dfs(k);
        }
        if(colour[k] == colour[u])
        {
            my = 0;
            return;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("ou.txt","w",stdout);
    int node,edge;
    while(cin>>node>>edge && node)
    {
        my=1;
        memset(visited,0,sizeof(visited));
        while(edge--)
        {
            int f,s;
            cin>>f>>s;
            vec[f].push_back(s);
            vec[s].push_back(f);
        }
        int ck = 0,p=0;
        for(int i=1; i<=node; i++)
        {
            p = 0;
            // memset(visited,0,sizeof(visited));

            if(visited[i] == 0)
            {
                colour[i] = 1;
                dfs(i);
            }
        }
        if(my == 0)
            cout<<"NOT BICOLORABLE."<<endl;
        else
            cout<<"BICOLORABLE."<<endl;
        for(int i=0; i<=node; i++)
            vec[i].clear();
    }
}
