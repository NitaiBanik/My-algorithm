#include<bits/stdc++.h>
using namespace std;
#define ll int
int main()
{
    ll t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++w);
        ll n,q,val;
        vector<ll>vec;
        scanf("%d %d",&n,&q);
        while(n--)
        {
            scanf("%d",&val);
            vec.push_back(val);

        }
        ll sz = vec.size();
        while(q--)
        {
        getchar();
           // cout<<"query = "<<q<<endl;
            char c;
            scanf("%c %d",&c,&val);
            if(c == 'c')
            {
                val--;
                if(sz<=val) printf("none\n");
                else
                {
                    printf("%d\n",vec[val]);
                    sz--;
                    vec.erase(vec.begin()+val);
                }
            }
            else
            {
                // scanf("%d",&val);
                vec.push_back(val);
                sz++;
            }

        }
    }
}
