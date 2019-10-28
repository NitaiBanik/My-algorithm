#include<bits/stdc++.h>
using namespace std;
#define sq(a) a*a

double fun(double l, double m, double n)
{
    double x = sq(l) - sq(m) + sq(n);
    return sqrt(x);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int type;
        double x,y,z,ans;
        scanf("%d %lf %lf %lf",&type,&x,&y,&z);
        if(type == 1)
            ans = fun(x,y,z);

        else if(type == 2)
            ans = fun(x,z,y);

        else if(type == 3)
            ans = fun(y,x,z);
            else
            ans = fun(x,y,z);
            printf("%.10f\n",ans);
    }
}
