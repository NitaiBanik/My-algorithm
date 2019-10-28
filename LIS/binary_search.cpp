#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 999999999999
ll I[100005];
ll L[100005];
ll sequence[100005],n;
ll ssequence[100005];

ll LIS()
{
    cout<<"enter"<<endl;
    I[0] = -inf;
    for(int i=1; i<=n; i++)
        I[i] = inf;

    ll length = 0;

    for(int i=0; i<n; i++)
    {
        ll low = 0,mid,hi = length;
        while(low<=hi)
        {
            mid = (low + hi)/2;
            if(I[mid]<sequence[i])
                low = mid + 1;
            else hi = mid - 1;
        }
         I[low] = sequence[i];
        L[i] = low;
        if(length<low)
            length = low;
        cout<<"pos = "<<i<<"length  = "<<length<<endl;

    }
    return length;
}

int main()
{

    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0; i<n; i++)
            scanf("%lld",&sequence[i]);
            int k = 0;
            for(int i=n-1;i>=0;i--)
            {
                sequence[k] = ssequence[i];
                k++;
            }

        ll ans = LIS();
        cout<<ans<<endl;
        vector<ll>vec;
ll mn = 9999999;
                for(int i=0;i<n;i++)
                    cout<<L[i]<<" ";
                cout<<endl;
if(ans == 1)
{
    ll mn = 9999999;
    for(int i=0;i<n;i++)
      {
          mn = min(mn,sequence[i]);
      }
      cout<<mn<<endl;
      return 0;

}
      for(int i=0;i<n;i++)
      {
          if(L[i] == L[i+1])
          {
              if(sequence[i]>sequence[i+2])
                cout<<sequence[i]<<endl;
              else cout<<min(sequence[i+1],sequence[i])<<endl;

              break;
          }
      }
        vec.clear();
        cout<<mn<<endl;
    }
    return 0;
}
