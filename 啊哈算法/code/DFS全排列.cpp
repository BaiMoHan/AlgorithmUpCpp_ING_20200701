#include<stdio.h>
int a[10],book[10],n;
//C语言全局变量默认初始化为0,a为盒子，book标记已放的牌 
void deep_first_search(int step);
int main()
{
	scanf("%d",&n);
	deep_first_search(1);//首先从第一个盒子开始尝试
	return 0; 
}
void deep_first_search(int step)//step表示站在第几个盒子前
{
	int i,count=1;//循环变量
	if(step==n+1)//递归结束条件，即前n个盒子已经放好了，完成一次全排列
	{
		
		//完成全排列后输出1-n号盒子中的编号 
		for(i=1;i<=n;i++)
			printf("%d",a[i]);
		printf("\n");
		
		return ;//输出一次全排列后返回上一次调用deep_first_search函数的地方
		 
	} 
	 
	 //此时站在第step个盒子前面，按照1,2,3,,,n的顺序尝试
	 for(i=1;i<=n;i++)
	 {
	 	if(book[i]==0)//判断手里的数字是否已经使用 
	 	{
		 	a[step]=i;
	 		book[i]=1;//放入盒子后，就标记为1 
	 		printf("我放置了%d\n",a[step]);
	 		//上述操作完成后，即当前盒子已经处理好，下一个盒子的处理方式与当前一样，递归调用
			deep_first_search(step+1);
			book[i]=0;//把刚才尝试的牌收回，从而开始下一次尝试，新的全排列 
			printf("我回收了%d\n",i);
	 	}
	  } 
 } 
