#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll arr[100005];
ll sum;
void mergee(int beg, int ed)
{
    queue<int>a,b,c;

    int mid = (beg + ed) / 2;

    for(int i=beg; i<=mid; i++)
        a.push(arr[i]);

    for(int i=mid + 1 ; i<=ed; i++)
        b.push(arr[i]);

    while(!a.empty() || !b.empty())
    {
        if(a.empty())
        {
            c.push(b.front());
            b.pop();
        }

        else if(b.empty())
        {
            c.push(a.front());
            a.pop();
        }

        else if(a.front()<b.front())
        {
            c.push(a.front());
            sum+=(a.front() * b.size());
            a.pop();
        }

        else
        {
            c.push(b.front());
            b.pop();
        }

    }

    int id = beg;

    while(!c.empty())
    {
        arr[id++] = c.front();
        c.pop();
    }
}

void mergesort(int beg, int ed)
{

    if(beg==ed)
        return;

    int mid = (beg + ed) / 2;

    mergesort(beg, mid);
    mergesort(mid+1, ed);

    mergee(beg, ed);


//    getchar();
//    cout<<"beg = "<<beg<<" ed = "<<ed<<endl;
//    for(int i=beg; i<=ed; i++)
//        printf("%lld ",arr[i]);
//    cout<<endl;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {


        int n;

        cin>>n;

        for(int i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
sum = 0;
        mergesort(1,n);
        cout<<sum<<endl;
    }


    return 0;
}
