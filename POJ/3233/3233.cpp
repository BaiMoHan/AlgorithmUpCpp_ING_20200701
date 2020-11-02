
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define Nnum 31
#define Mnum 31
#define LL long long
struct matrix
{
    int mat[31][31];
};
int n,m;
matrix ONE;
matrix mul(matrix A,matrix B)//矩阵相乘
{
    int i,j,k;
    matrix C;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            C.mat[i][j]=0;
            for(k=1;k<=n;k++)
            {
                C.mat[i][j]=(A.mat[i][k]*B.mat[k][j]+C.mat[i][j])%m;
            }
        }
    }
    return C;
}
matrix add(matrix A,matrix B)//矩阵相加
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            A.mat[i][j]+=B.mat[i][j];
            A.mat[i][j]=A.mat[i][j]%m;
        }
    }
    return A;
}
matrix powmul(matrix A,int k)//A矩阵的k次方
{
    if(k==1)return A;
    matrix B=powmul(A,k/2);
    B=mul(B,B);
    if(k%2)B=mul(B,A);
    return B;
}
matrix dos(matrix A,int k)
{
    if(k==1)return A;
    if(k%2==0)
    {
        matrix B=dos(A,k/2);
        return mul(add(powmul(A,k/2),ONE),B);
    }
    else
    {
        matrix B=dos(A,(k)/2);
        matrix C=powmul(A,(k+1)/2);
        return add(C,mul(B,add(C,ONE)));
    }
}
int main()
{
    int k,i,j;
    matrix A;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;i++)
    {
        ONE.mat[i][i]=1;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&A.mat[i][j]);
        }
    }
    matrix ans=dos(A,k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j!=1)cout<<" ";
            printf("%d",(ans.mat[i][j])%m);
        }
        cout<<endl;
    }
    return 0;
}

