#include <stdio.h>
#define MAX 101
int main()
{
    int n;
    int a[MAX][MAX]={0};
    int colsum[MAX][MAX]={0};
    int maxn=0,sum;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        // 方便建立表格注意j=1的初始值
        for(int j=1;j<=n;j++)
        {
            //原生矩阵a的第一个有效元素的索引是a[0]
            scanf("%d",&a[i][j-1]);
            //colsum[i][j]记录的是第i行前j个元素的和,所以前面j=1,方便推导
            colsum[i][j]=colsum[i][j-1]+a[i][j-1];
        }

    //将连续的行相加,i,j来控制每一行选择哪几个元素,j>i才有元素
    for(int i=0;i<n;i++)
        for(int j=i;j<=n;j++)
        //i,j放在外层循环,控制每一行选择几个元素
        {
            sum=0;

            //内层k表示遍历的行数,连续的行数累加就是将二维变成了一维
            for(int k=0;k<n;k++)
            {
                sum+=colsum[k][j]-colsum[k][i];
                if(sum<0)
                     sum=0;//保证有正数数据才正确
                else if(sum>maxn)
                     maxn=sum;
            }
        }
    printf("%d\n",maxn);
    return 0;
}