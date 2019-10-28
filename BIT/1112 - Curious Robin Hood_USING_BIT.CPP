#include<bits/stdc++.h>
using namespace std;

long long arr[100005];
long long tree[100005];

void update(long long  idx,long long  x,long long  n)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+=(idx & (-idx));
    }
}
long long query(long long  idx)
{
    long long sum = 0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}
int main()
{
    long long test,w = 0;
    scanf("%lld",&test);
    while(test--)
    {

        long long num,Q;
        scanf("%lld %lld",&num,&Q);
        tree[0] = 0;
        for(long long  i=1; i<=num; i++)
        {
            long long val;
            scanf("%lld",&val);
             update(i,val,num);

            arr[i] = val;
        }
        printf("Case %lld:\n",++w);
        for(long long  i=1; i<=Q; i++)
        {
            long long  ck,ind,val;
            scanf("%lld",&ck);
            if(ck ==1)
            {
                scanf("%lld",&ind);
                ind++;
                printf("%lld\n",arr[ind]);
                update(ind,(-1*arr[ind]),num);
                arr[ind] = 0;
            }
            else if(ck ==2)
            {
                scanf("%lld %lld",&ind,&val);
                ind++;
                arr[ind]+=val;
                update(ind,val,num);
            }
            else
            {
                long long  f,r;
                long long f1,f2;
                scanf("%lld %lld",&f,&r);
                f++,r++;
                if((f-1)==0) f1 = 0;
                else
                    f1 = query(f-1);

                    f2 = query(r);
                    printf("%lld\n",f2-f1);
            }
        }
        memset(tree,0,sizeof(tree));
       // memset(tree,0,sizeof(tree));
    }
    return 0;
}
