#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
int days[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	#ifndef OJ
	freopen("201509-2.txt","r",stdin);
	#endif
	int y,d,rm=1,rd;
	cin>>y>>d;
	int mode;
	if((y%4==0&&y%100)||(y%400==0))
		mode=1;
	else
		mode=0;
	_rep(i,0,12)
	{
		if(d>days[mode][i])
		{
			rm++;
			d-=days[mode][i];
		}else{
			cout<<rm<<endl<<d;
			break;
		}
	}
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}

