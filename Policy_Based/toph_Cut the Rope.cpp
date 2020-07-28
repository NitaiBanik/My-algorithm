///policy based cut the rope toph
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ll long long
#define pii pair<ll,ll>

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{

    ll t;
    scanf("%lld", &t);
    ll n;
    ll q,w = 0;

    ordered_set Tree;

    set<ll>piece;
    while(t--)
    {
        scanf("%lld %lld",&n, &q);
        int idx = 0;
        Tree.insert({n,idx});
        piece.insert(0);
        piece.insert(n);
        printf("Case %lld:\n",++w);
        while(q--)
        {
            char type[2];
            ll sz;
            scanf("%s %lld",type,&sz);
            if(type[0] == 'C')
            {
                auto pp = piece.upper_bound(sz);
                ll End = *pp;
                ll Start = *(--pp);

                ll len = End - Start;
                ll left =  sz - Start;
                ll right =  End - sz;

                piece.insert(sz);
                Tree.erase(Tree.upper_bound({len,-1}));
                Tree.insert({left,++idx});
                Tree.insert({right,++idx});
            }
            else
            {
                cout<<Tree.find_by_order(sz-1)->first<<"\n";
            }

        }
        piece.clear();
        Tree.clear();

    }
    return 0;
}
