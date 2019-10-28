/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,WWE = 0;
    cin>>t;
    int gd[10005];
    gd[1] = 0,gd[2] = 0,gd[3] = 1;
    for(int i = 4; i<= 10000; i++)
    {
        int XOR = 0,dm = (i / 2);
        set<int>st;
        for(int j = 1; j <= dm; j++)
        {
            if(j == (i- j))
                break;
           st.insert(gd[j] ^ gd[i - j]);
        }
        int x = 0;
        while(st.find(x) != st.end()) x++;
        gd[i] = x;
    }
    while(t--)
    {
        int n,val,XOR = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&val);
            XOR^=gd[val];
        }
        cout<<XOR<<endl;
        if(XOR)
            printf("Case %d: Alice\n",++WWE);
        else
            printf("Case %d: Bob\n",++WWE);
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
int gd[10005];
int arr[10005];
int main()
{
    int t,WWE = 0;
    scanf("%d",&t);

    gd[1] = 0,gd[2] = 0,gd[3] = 1;
    for(int i = 4; i<= 10005; i++)
    {
        int XOR = 0,md = i/2;
        memset(arr,0,sizeof(arr));
        for(int j = 1; j <= md; j++)
        {
            if(j == (i- j))
                break;
            arr[gd[j] ^ gd[i - j]] = 1;
        }
        int x = 0;
        while(arr[x])
            x++;
        gd[i] = x;
        // cout<<x<<" "<<endl;
    }
    while(t--)
    {
        int n,val,XOR = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&val);
            XOR^=gd[val];
        }
        if(XOR)
            printf("Case %d: Alice\n",++WWE);
        else
            printf("Case %d: Bob\n",++WWE);
    }
}
