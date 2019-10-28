#include<bits/stdc++.h>
using namespace std;

vector<int>vec[32],graph[32];
int dis[32];
int dp[102];
int mx;
int fun(int s)
{
    if(graph[s].size() == 0)
    {
        return dp[s] = 0;
    }

    if(dp[s]!=-1) return dp[s];
    int ans1 = 0;
    for(int i=0; i<graph[s].size(); i++)
    {
        int v = graph[s][i];
        ans1  = max(ans1,1+fun(v));

    }
    return dp[s] = ans1;
}

vector<int>print;
int lis;

void path(int s)
{
    if(graph[s].size() == 0) return;
    for(int i=0; i<graph[s].size(); i++)
    {
        int v = graph[s][i];
        if(dp[v] == lis-1)///1 + total visited node.so -1 is used
        {
            lis--;
            print.push_back(v);
            path(v);
        }

    }

}
int main()
{
    int n,d;
    while(scanf("%d %d",&n,&d) == 2)
    {
        int val;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<d; j++)
            {
                cin>>val;
                vec[i].push_back(val);
            }
            sort(vec[i].begin(),vec[i].end());
        }
        int src,w = 0;
        for(int i=0; i<n; i++)
        {
            int cn = 0;
            for(int k=0; k<n; k++)
            {

                int ck = 0;
                for(int j=0; j<d; j++)
                {
                    if(vec[k][j]>=vec[i][j])
                    {
                        ck = 1;
                        break;
                    }
                }
                if(ck == 0)
                {
                    graph[i].push_back(k);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        lis = 0;

        int st;
        for(int i=0; i<n; i++)
        {
            int res = fun(i);
            if(res>lis)
            {
                lis = res;
                st = i;
            }

        }
        //print.push_back(st);
        cout<<lis + 1<<endl;
        path(st);
        for(int i=print.size()-1; i>=0; i--) cout<<print[i] + 1<<" ";
        cout<<st+1<<endl;
        for(int i=0; i<n; i++)
        {
            graph[i].clear();
            vec[i].clear();
        }
        print.clear();
    }
    return 0;
}
