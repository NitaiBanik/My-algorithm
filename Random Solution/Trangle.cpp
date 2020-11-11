#include<bits/stdc++.h>
using namespace std;

#define PI 3.1416

int main()
{
    cout<<PI<<endl;
    while(1)
    {
        cout<<"Enter the side of the triangle"<<endl;

        double triangleSide;
        cin>>triangleSide;

        double sin60 = sin( ( PI / 180.0) * 60.0);

        // cout<<sin60<<endl;

        double outerRadius = triangleSide / (2.0 * sin60);

        double outerArea = outerRadius * outerRadius * PI;

//        cout<<outerArea<<endl;

        double smallTriangleArea = ( (double)( sqrt(3.0) * (triangleSide* triangleSide) ) / 4.0 ) / 3.0 ;

        double innerRadius = (smallTriangleArea * 2) / triangleSide;
        double innerArea = innerRadius * innerRadius * PI;

        printf("%.4f\n",(outerArea-innerArea) * 100.0);
    }
}
