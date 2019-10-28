#include<bits/stdc++.h>
using namespace std;
long long par[10000];

long long  findd(long long  val)
{
    if(par[val] == val)
        return val;
    return par[val]=findd(par[val]);
}

void Union(long long a,long long b)
{
    par[findd(b)] = findd(a);
}

int main()
{
    int n,edge;

    scanf("%d %d",&n,&edge);

    for(int i=1; i<=n ; i++)
        par[i] = i;

    while(edge--)
    {
        int f,s;
        scanf("%d %d",&f,&s);
        Union(f,s);
    }

    int cnt = 0;
    for(int i=1; i <=n ; i++)
        par[i] = findd(i);

    for(int i=1; i <=n ; i++)
    {
        if(par[i] == i)
            cnt++;
    }
    printf("%d\n",cnt);
}
