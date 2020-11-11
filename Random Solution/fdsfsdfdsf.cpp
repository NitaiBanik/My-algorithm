#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    float a;
    scanf("%f cm",&a);
    printf("%.4f mm2\n",(((1.0/3.0)-(1.0/12.0))*3.1416*a*a*10.0*10.0));
    return 0;
}
