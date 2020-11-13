#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
struct nodes
{
    long long value;//���
    long long num;  //����
}node[25];
long long res;
bool cmp(struct nodes a,struct nodes b)
{
    return a.value>b.value;
}
int main()
{
    int n,c;
    scanf("%d",&n);
    scanf("%d",&c);
    memset(node,0,sizeof(node));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&node[i].value);
        scanf("%lld",&node[i].num);
    }
    sort(node,node+n,cmp);
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<node[i].value<<" "<<node[i].num<<endl;
    // }
    
    //������c��ͳ�Ʒ���
    int id; //��һ��Ҫ���ǵ�Ӳ�ұ��
    for(id=0;id<n;id++)
    {
        if(node[id].value<c)
            break;  //���ȫ��������
        res+=node[id].num;
    }

    if(id==n) //�ж��Ƿ����
    {
        printf("%d",res);
    }
    else    //С��Ӳ�Ҵ���һ��
    {
        int temp;//��ǰ���Դճɵ�Ӳ��
        while(true)
        {
            temp=0;
            //�Ӵ�С�սӽ�c
            for(int j=id;j<n;j++)
            {
                while(node[j].num&&temp+node[j].value<c)
                {
                    temp+=node[j].value;
                    node[j].num--;
                }
            }
            //��С�������սӽ�c
            for(int j=n-1;j>=id;j--)
            {
                while(node[j].num&&temp<c)
                {
                    temp+=node[j].value;
                    node[j].num--;
                }
            }
            
            if(temp<c)  //�ղ����ˣ���ֹͣ��
                break;

            //������
            res++;    
        }
        printf("%d\n",res);

    }

    
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, C;
struct node
{
    int d, c;
};
node a[25];

bool cmp(const node & a, const node & b)
{
    return a.d > b.d;
}

int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a[i].d, &a[i].c);
    }
    sort(a, a + N, cmp);
    int cnt = 0;
    int j = 0;
    for (; j < N; j++)
    {
        if (a[j].d < C)
            break;
    }
    for (int i = 0; i < j; i++)
    {
        cnt += (a[i].d / C) * a[i].c;
    }
    while (true)
    {
        int now = 0;
        for (int i = j; i < N; i++)
        {
            while (a[i].c && now + a[i].d <= C)
            {
                now += a[i].d;
                a[i].c--;
            }
        }
        for (int i = N - 1; i >= j; i--)
        {
            while (a[i].c && now < C)
            {
                now += a[i].d;
                a[i].c--;
            }
        }
        if (now < C)
            break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
*/
