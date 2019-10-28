#include<bits/stdc++.h>
using namespace std;
long long ttl,kk;
map<long long, long long >mp;
vector<long long>vec[105];
set<long long > st;
long long dis[105];
void bfs(long long s)
{
    queue<long long>q;
    memset(dis,-1,sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        long long k = q.front();
        q.pop();

        long long sz = vec[k].size();
        for(long long i=0; i<sz; i++)
        {
            long long st = vec[k][i];
            // printf("st =%lld dis[st] = %lld\n",st,dis[st]);
            if(dis[st]==-1)
            {
                dis[st] = dis[k] + 1;
                if(dis[st]<=ttl && dis[st]>0)
                {
                    kk++;
                    // printf("st =%lld dis[st] = %lld\n",st,dis[st]);
                    // getchar();
                    q.push(st);
                }
            }
        }
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("ou.txt","w",stdout);
    long long pairr,w = 0;
    while(scanf("%lld",&pairr) && pairr != 0 )
    {
        long long a,b,i = 0;
        while(pairr--)
        {
            scanf("%lld %lld",&a,&b);
            st.insert(a);
            st.insert(b);

            if(mp[a] == 0)
            {
                i++;
                mp[a] = i;
            }
            if(mp[b] == 0)
            {
                i++;
                mp[b] = i;
            }

            vec[mp[a]].push_back(mp[b]);
            vec[mp[b]].push_back(mp[a]);
        }
        long long val,cnt;
        cnt = st.size();
        while(scanf("%lld %lld",&val,&ttl))
        {
            if(val == 0 && ttl == 0)
                break;
            w++;
            kk = 1;
            bfs(mp[val]);
            ///cout<<"kk = "<<kk<<endl;
            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",w, cnt - kk,val,ttl);
        }
        for(long long j = 0; j<=100; j++)
            vec[j].clear();
        st.clear();
        mp.clear();

    }
    return 0;
}
/*
16
10 15 15 20 20 25 10 30 30 47 47 50 25 45 45 65
15 35 35 55 20 40 50 55 35 40 55 60 40 60 60 65
35 2 35 3 0 0

14
1 2 2 7 1 3 3 4 3 5 5 10 5 11
4 6 7 6 7 8 7 9 8 9 8 6 6 11
1 1 1 2 3 2 3 3 0 0

0
*/
