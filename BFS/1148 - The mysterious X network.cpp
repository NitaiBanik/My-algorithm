#include<bits/stdc++.h>
using namespace std;

vector<int>vec[100005];
int cost[100005];
int bfs(int s,int d)
{
    memset(cost,-1,sizeof(cost));
    queue<int>q;
    q.push(s);
    cost[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v = vec[u][i];
            if(cost[v] == -1)
            {
                cost[v] = cost[u]+1;
                if(v == d) return cost[d];
                q.push(v);
            }
        }
    }
    return cost[d];
}
int main()
{

    int test,w = 0;
    scanf("%d",&test);
    while(test--)
    {
        if(w>0)
            printf("\n");
        int op,frm;
        scanf("%d",&op);
        while(op--)
        {
            scanf("%d",&frm);
            int nod,edg;
            scanf("%d",&edg);
            while(edg--)
            {
                int to;
                scanf("%d",&to);
                vec[frm].push_back(to);
                vec[to].push_back(frm);
            }

        }
        int src,des;
        scanf("%d %d",&src,&des);
       int dess =  bfs(src,des);
       if(dess == 0)
            printf("0\n");
            else
            printf("%d %d %d\n",src,des,dess-1);

        w++;
        for(int i=0; i<=100005; i++)
            vec[i].clear();
    }
    return 0;

}


/*

1

5 6
0 1
0 2
3 2
2 4
4 3
1 2

*/
