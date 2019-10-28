#include<bits/stdc++.h>

using namespace std;

struct matrix
{
    long long v[8][8];
    long long row,col;
};

long long mod;

matrix multi(matrix a, matrix b)
{
    assert(a.col == b.row);

    matrix r;
    r.row = a.row;
    r.col = b.col;

    for(long long i=0; i<r.row; i++)
        for(long long j=0; j<r.row; j++)
        {
            long long sum = 0;
            for(long long k=0; k<a.col; k++)
            {
                sum+=(a.v[i][k] * b.v[k][j]);
                sum%=mod;
            }
            r.v[i][j] = sum;
        }

    return r;
}

matrix power(matrix mat,long long p)
{
    assert(p >=1 );

    if(p==1) return mat;

    if(p%2 == 1)
        return multi(mat,power(mat,p-1));

    matrix ret = power(mat,p/2);

    ret = multi(ret,ret);
    return ret;
}

int main()
{
    long long n,m,t,w = 0;

    scanf("%lld",&t);

    while(t--)
    {

        long long a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2;
        scanf("%lld %lld %lld",&a1,&b1,&c1);
        scanf("%lld %lld %lld",&a2,&b2,&c2);
        scanf("%lld %lld %lld",&f0,&f1,&f2);
        scanf("%lld %lld %lld",&g0,&g1,&g2);
        scanf("%lld",&mod);
        long long Q;
        scanf("%lld",&Q);

        long long arr[105];
        for(int i=0; i<Q; i++)
            scanf("%lld",&arr[i]);
        printf("Case %lld:\n",++w);
        for(int i=0; i<Q; i++)
        {
            long long n;
            n = arr[i];

            if(n<3)
            {
                if(n==0) cout<<f0%mod<<" "<<g0%mod<<endl;
                if(n==1) cout<<f1%mod<<" "<<g1%mod<<endl;
                if(n==2) cout<<f2%mod<<" "<<g2%mod<<endl;
            }

            else
            {
                matrix mt;

                mt.row = mt.col = 6;
                for(int i=0; i<6; i++)
                    for(int j=0; j<6; j++)
                        mt.v[i][j] = 0;

                mt.v[0][0] = a1,mt.v[0][1] = b1,mt.v[0][5] = c1;
                mt.v[1][0] = 1;
                mt.v[2][1] = 1;
                mt.v[3][2] = c2,mt.v[3][3] = a2,mt.v[3][4] = b2;
                mt.v[4][3] = 1;
                mt.v[5][4] = 1;

                mt = power(mt,n-2);
                long long ans1 = f2 * mt.v[0][0] + f1 * mt.v[0][1] + f0 * mt.v[0][2] + g2 * mt.v[0][3]+  g1 * mt.v[0][4] + g0*  mt.v[0][5];
                long long ans2 = f2 * mt.v[3][0] + f1 * mt.v[3][1] + f0 * mt.v[3][2] + g2 * mt.v[3][3]+ + g1 * mt.v[3][4] + g0*  mt.v[3][5];

               cout<<ans1%mod<<" "<<ans2%mod<<endl;
            }
        }

    }
    return 0;
}
