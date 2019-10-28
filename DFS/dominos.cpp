#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10005];

int visit[10005],node,cnt;

void dfs(int p)
{
    visit[p] = 1;
    for( int k=0; k<vec[p].size(); k++)
    {
        int v = vec[p][k];
        if(visit[v] == 0)
        {
            cnt++;
            dfs(v);
        }
    }
}

int main()
{
    // freopen("in.txt","r",stdin);
    //freopen("ou.txt","w",stdout);
    int t,m=0;
    scanf("%d",&t);
    while(t--)
    {
        // memset(vec,0,sizeof(vec));
        memset(visit,0,sizeof(visit));
        int m,l,f,s;
        cin>>node>>m>>l;
        while(m--)
        {
            cin>>f>>s;
            vec[f].push_back(s);
        }

        cnt =0;
        while(l--)
        {
            int y;
            cin>>y;
            if(visit[y]==0)
            {
                cnt++;
                dfs(y);

            }
        }
        cout<<cnt<<endl;
        for(int i=0; i<=node; i++)
            vec[i].clear();
    }
return 0;
}
