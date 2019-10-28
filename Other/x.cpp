#include <iostream>

using namespace std;
int arr[605][605];
int main() {
    int a, b,x,y;
    cin>>a>>b>>x>>y;
    x+=a;
    y+=b;
    for(int i=1;i<=x;i++)
    for(int j=1;j<=y;j++)
    scanf("%d",&arr[i][j]);


  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++)
    {
        printf("%d",arr[i][j]);
        if(j!=b)
        printf(" ");
    }
    printf("\n");
  }


    return 0;
}
