#include<bits/stdc++.h>
using namespace std;
#define Lf long long
double dist(Lf x,Lf y,Lf x1,Lf y1)
{
    return (((x1-x)*(x1-x))+((y1-y)*(y1-y)));
}

int  main()
{
    cout<<sin(1.5708)
<<endl;    ///There should be rotation so the distance(a,b) and distance(b,c) must be equal
    Lf a1,b1,c1;
    Lf a2,b2,c2;
    scanf("%lld %lld",&a1,&a2);
    scanf("%lld %lld",&b1,&b2);
    scanf("%lld %lld",&c1,&c2);

    Lf a = dist(a1,a2,b1,b2) ;
    Lf b = dist(b1,b2,c1,c2);
    if(a == b)
    {
        ///slope1 = (b2 - a2)/(b1 - a1);
        ///slope2 = (c2 - b2)/(c1 - b1);
        ///if slopes are equal then both points will be considered in same line...
        ///If points are in same line it is impossible to build triangle thus  circle and rotation is not possible.
        Lf m1 = (b2 - a2) * (c1 - b1);
        Lf m2 = (b1 - a1) * (c2 - b2);
        if(m1 != m2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"NO"<<endl;

}
