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
        // ���㽨�����ע��j=1�ĳ�ʼֵ
        for(int j=1;j<=n;j++)
        {
            //ԭ������a�ĵ�һ����ЧԪ�ص�������a[0]
            scanf("%d",&a[i][j-1]);
            //colsum[i][j]��¼���ǵ�i��ǰj��Ԫ�صĺ�,����ǰ��j=1,�����Ƶ�
            colsum[i][j]=colsum[i][j-1]+a[i][j-1];
        }

    //�������������,i,j������ÿһ��ѡ���ļ���Ԫ��,j>i����Ԫ��
    for(int i=0;i<n;i++)
        for(int j=i;j<=n;j++)
        //i,j�������ѭ��,����ÿһ��ѡ�񼸸�Ԫ��
        {
            sum=0;

            //�ڲ�k��ʾ����������,�����������ۼӾ��ǽ���ά�����һά
            for(int k=0;k<n;k++)
            {
                sum+=colsum[k][j]-colsum[k][i];
                if(sum<0)
                     sum=0;//��֤���������ݲ���ȷ
                else if(sum>maxn)
                     maxn=sum;
            }
        }
    printf("%d\n",maxn);
    return 0;
}