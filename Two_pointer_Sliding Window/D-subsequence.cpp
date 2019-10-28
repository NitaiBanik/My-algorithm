#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100005];

int main()
{
   ll n,s;
   while(cin>>n>>s)
   {
       for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
       ll mn = 99999999999;
       ll st = 0,en = 0;
       ll sum =0;
       for(int i=0;i<n;i++)
       {
           sum+=arr[i];
            while(sum>=s)
           {
               mn=min(mn,i-st + 1);
               sum-=arr[st];
               st++;
           }

       }
       if(mn == 99999999999)
        mn = 0;
       cout<<mn<<endl;
   }
   return 0;
}

