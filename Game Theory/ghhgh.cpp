#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t,WWE = 0,n,val;
   cin>>t;
   while(t--)
   {
       scanf("%d",&n);
       int XOR = 0;
       while(n--)
       {
           scanf("%d",&val);
           cout<<val<<" ";
           int two = 0;
           while(val>1)
           {
               two++;
               val/=2;
           }
           XOR^=two;
           cout<<two<<endl;

       }
       if(XOR)
            printf("Case %d: Alice\n",++WWE);
        else
            printf("Case %d: Bob\n",++WWE);
   }


}
