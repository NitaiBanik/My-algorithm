#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100010
#define mod 1000000007LL

vector<ll>graph[mx + 5];

ll level[mx + 5];
ll start[mx + 5];
ll End[mx + 5];
ll arr[2*mx + 5];

bool visit[mx + 5];

ll power[mx + 5];
ll inv[mx + 5];

ll bigmod(ll b, ll p)
{
    ll ans = 1;
    ll k = b;
    while(p)
    {
        if(p&1){
            ans *= k;
            ans %= mod;
        }

        k*=k;
        k%=mod;
        p = p>>1LL;
    }
    return ans;
}
void poower()
{
    power[0] = 1;
    inv[0]=bigmod(power[0],mod-2);
    for(int i=1; i<mx; i++)
    {
        power[i] = power[i - 1] * 2;
        power[i]%=mod;
        inv[i]=bigmod(power[i],mod-2);
    }
    //cout<<inv[1]<<endl;
    //cout<<inv[2]<<endl;
}

ll tym;

void dfs(ll src, ll lvl)
{

    visit[src] = true;
    level[src] = lvl;
    start[src] = ++tym;

    for(int i=0; i<graph[src].size(); i++)
    {
        ll x = graph[src][i];

        if(visit[x] == false)
            dfs(x,lvl+1);
    }
    End[src] = ++tym;
}


long long tree_val[mx * 8];
long long tree_sum[mx * 8];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree_val[node] = arr[b];
        //cout<<arr[b]<<endl;
        return ;
    }
    ll left = node * 2;
    ll right  = node * 2 + 1;
    ll mid = (b + e) / 2;

    init(left,b,mid);
    init(right,mid + 1, e);
}

void update(ll node, ll b, ll e, ll i, ll j, ll vall)
{
    //cout<<node<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<" "<<vall<<endl;
    // cout<<"emn kno"<<endl;
    if(b>j || e<i)
        return;

    if(b>=i && e<=j)
    {
        //cout<<"last level - >"<<node<<endl;
        ll vv = (tree_val[node] * vall);
//        vv %= mod;
//        if(vv<0)vv+=mod;
        tree_sum[node]+=vv;
        tree_sum[node]%=mod;
        if(tree_sum[node]<0)tree_sum[node]+=mod;
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b+ e) / 2;

    update(left,b,mid,i,j,vall);
    update(right,mid + 1,e,i,j,vall);

    tree_sum[node] = (tree_sum[left] + tree_sum[right]) % mod;
}

ll query(ll node, ll b, ll e,ll i, ll j)
{
    // cout<<"haha"<<endl;
    if(b>j || e<i) return 0LL;
    if(b>=i && e<=j) return tree_sum[node] % mod;

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    ll xx = query(left, b, mid, i,j);

    ll yy = query(right,mid + 1,e, i,j);

    return (xx+yy)%mod;
}

//ll inv[mx + 5];
ll brr[mx+5];
int main()
{
    //freopen("out.txt","w",stdout);
    poower();
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {

        int node;

        scanf("%d",&node);

        ll frm,to;

        for(int i = 1; i<node; i ++)
        {
            scanf("%lld %lld",&frm,&to);
            graph[frm].push_back(to);
            graph[to].push_back(frm);
        }

        //cout<<"end of input"<<endl;
       // getchar();

        memset(visit,false,sizeof(visit));
        memset(tree_sum,0,sizeof(tree_sum));
        memset(tree_val,0,sizeof(tree_val));
        memset(start,0,sizeof(start));
        memset(End,0,sizeof(End));
        memset(arr,0,sizeof(arr));
        memset(level,0,sizeof(level));
        //cout<<"before dfs"<<endl;

        tym = 0;
        dfs(1,0);
        //cout<<"end of dfs"<<endl;
        arr[1] = 0;
        for(int i=2; i<=node; i++)
        {
            //  cout<<start[i]<<"End = "<<End[i]<<endl;
            //cout<<"level of "<<i<<" = "<<level[i]<<endl;
            if(End[i] - start[i] == 1)
                arr[start[i]] = power[level[i] - 1];

            // cout<<"value = "<<arr[start[i]]<<endl;
        }

        init(1,1,node*2);

        ll queery;

        scanf("%lld",&queery);
        ll type,x,y;

        memset(brr,0,sizeof(brr));

        printf("Case %d:\n",++w);
        while(queery--)
        {
            scanf("%lld",&type);

            if(type == 2)
            {
                scanf("%lld %lld",&x,&y);
                brr[x]+=y;
                brr[x]%=mod;

                if(brr[x]<0)
                {
                    brr[x]+=mod;
                    brr[x]%=mod;
                }

                update(1,1,node*2,start[x],start[x],y);
            }
            else
            {
                scanf("%lld",&x);

                ll ans;
                if(End[x]-start[x]==1)
                {
                    ans=brr[x]%mod;
                }
                else
                {
                    ans = query(1,1,node*2,start[x],End[x]) % mod;
                    // cout<<"pre_ans = "<<ans<<endl;
                    ans*=inv[level[x]];

                    ans%=mod;

                    if(ans<0)
                        ans+=mod;

                }

                printf("%lld\n",ans%mod);
            }
        }

        for(int i=0; i<=node+2; i++) graph[i].clear();
    }
    return 0;
}

