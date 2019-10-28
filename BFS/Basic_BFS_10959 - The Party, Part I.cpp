#include<bits/stdc++.h>
using namespace std;

vector<int>vec[1005];
int cost[1005];
void bfs()
{
    memset(cost,-1,sizeof(cost));
    queue<int>q;
    q.push(0);
    cost[0] = 0;
    while(!q.empty())
    {
      int u = q.front();
      q.pop();
      for(int i=0;i<vec[u].size();i++)
      {
          int v = vec[u][i];
          if(cost[v] == -1)
          {
              cost[v] = cost[u]+1;
              q.push(v);
          }
      }
    }
}
int main()
{

    int test,w = 0;
    scanf("%d",&test);
    while(test--)
    {
        if(w>0)
                printf("\n");
        int nod,edg;
        scanf("%d %d",&nod,&edg);
        while(edg--)
        {
            int frm,to;
            scanf("%d %d",&frm,&to);
            vec[frm].push_back(to);
            vec[to].push_back(frm);
        }
        bfs();
        for(int i=1; i<nod; i++)
            printf("%d\n",cost[i]);

            w++;
             for(int i=0; i<=nod; i++)
            vec[i].clear();
    }

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
