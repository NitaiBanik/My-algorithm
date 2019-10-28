#include<bits/stdc++.h>
using namespace std;

vector<int>vec[1000];
int cost[1000][1000];
bool vis[1000];

class ABC
{
public:
    int a,b,c;
    ABC(int x,int y,int z)
    {
        a  = x;
        b = y;
        c = z;
    }
    bool operator <(const ABC&two) const
    {
        return two.c<c;
    }
};
queue<int>Q;
int mst(int N, int source)
{
    priority_queue<ABC>Q1;
    for(int i=0; i<vec[source].size(); i++)
    {
        int k = vec[source][i];
        Q1.push(ABC(source,k,cost[source][k]));
    }
    int tot = 0;
    for(int i=1; i<N; i++)
    {
        ABC temp = Q1.top();
        if(vis[temp.a] == true && vis[temp.b] == true)
        {
            Q1.pop();
            i--;
            continue;
        }

        vis[temp.a] = true;
        vis[temp.b] = true;
        Q.push(temp.a);
        Q.push(temp.b);
        tot+=temp.c;
        int x = temp.b;
        for(int ii=0; ii<vec[x].size(); ii++)
        {
            int k = vec[x][ii];
            if(vis[k] == false)
                Q1.push(ABC(x,k,cost[x][k]));
        }

    }
    return tot;
}
int main()
{

    int node,edge;
    scanf("%d %d",&node,&edge);
    int frm,to,cst;
    for(int i=0; i<edge; i++)
    {
        scanf("%d %d %d",&frm,&to,&cst);
        vec[frm].push_back(to);
        vec[to].push_back(frm);
        cost[frm][to] = cst;
        cost[to][frm] = cst;
    }
    int ans = mst(node,5);

    printf("The total cost for MST = %d\n",ans);

    while(!Q.empty())
    {
        int first = Q.front();
        Q.pop();
        int second = Q.front();
        Q.pop();
        printf("Edge from %d to Edge %d and cost = %d\n",first,second,cost[first][second]);
    }


}
