#include<iostream>
#define OJ 98
using namespace std;
int main()
{
	#ifndef OJ
	freopen("201803-1.txt","r",stdin);
	#endif
	int temp;//�м���� 
	int res=0;//���
	int count=0;//����2���ֵĴ��� 
	while(true)
	{
		cin>>temp;
		if(temp==1)
		{
			res+=((count+1)*count);
			count=0;
			res+=1;
		}
		else if(temp==2)
		{
			count++;
		 }
		else{
			res+=((count+1)*count);
			count=0;
			break;
		}
	 } 
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 
