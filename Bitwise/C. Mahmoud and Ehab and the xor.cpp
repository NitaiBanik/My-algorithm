#include<bits/stdc++.h>
using namespace std;

int main()
{

    int f1 = (1<<18);
    int f2 = (1<<17);

    int _xor = 0;
    int n,val;

    cin>>n>>val;

    if(n == 2 && val == 0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else if(n == 1)
    {
        cout<<"YES"<<endl<<val<<endl;
        return 0;
    }
    else if(n == 2)
    {
        cout<<"YES"<<endl<<val<<" 0"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i = 1; i<=n-3; i++)
    {
        printf("%d ",i);
        _xor^=i;
    }

    if(_xor == val)
    {
        cout<<(f1+f2)<<" "<<f1<<" "<<f2<<endl;
    }
    else cout<<(f1^_xor)<<" "<<(f1^val)<<" "<<0<<endl;
    return 0;
}
