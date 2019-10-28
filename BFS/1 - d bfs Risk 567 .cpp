#include<bits/stdc++.h>
using namespace std;
int dis[25];
vector<int>vec[25];
int src,des;
int bfs(int s)
{
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        int sz = vec[k].size();
        for(int i=0; i<sz; i++)
        {
            int st = vec[k][i];
            // printf("st =%d dis[st] = %d\n",st,dis[st]);
            if(dis[st]==-1)
            {
                dis[st] = dis[k] + 1;
                // printf("st =%d dis[st] = %d\n",st,dis[st]);
                // getchar();
                if(st == des)
                    return dis[des];
                q.push(st);
            }
        }
    }
}
int main()
{
    int num1,num2,w = 0;
    while(scanf("%d",&num1) == 1)
    {
        int node1,node2,step = 1;
        while(num1--)
        {
            scanf("%d",&node1);

        }
    }
    return 0;
}
