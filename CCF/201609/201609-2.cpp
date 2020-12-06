#include<iostream>
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define OJ 98
using namespace std;
int mp[21][6];//mp[i][0]表示该行还有多少个空位
int main()
{
	#ifndef OJ
	freopen("201609-2.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	bool flag=false;	//标记是否座位连续的 
	int order;
	_rep(k,0,n)
	{
		cin>>order;
		switch(order){
			case 1:
				_rep(i,1,21)
				{
					if(mp[i][0]<5)
					{
						cout<<(i-1)*5+mp[i][0]+1<<endl;
						mp[i][0]++;
						flag=true;
						break;
					}
				}
				break;
			
			case 2:
				_rep(i,1,21)
				{
					if(mp[i][0]<4)
					{
						_rep(j,0,2)
						{
							cout<<(i-1)*5+mp[i][0]+1<<" ";
							mp[i][0]++;
						}
						cout<<endl;
						flag=true;
						break;
					}
				}
				break;
				
			case 3:
				_rep(i,1,21)
				{
					if(mp[i][0]<3)
					{
						_rep(j,0,3)
						{
							cout<<(i-1)*5+mp[i][0]+1<<" ";
							mp[i][0]++;
						}
						cout<<endl;
						flag=true;
						break;
					}
				}
				break;
			
			case 4:
				_rep(i,1,21)
				{
					if(mp[i][0]<2)
					{
						_rep(j,0,4)
						{
							cout<<(i-1)*5+mp[i][0]+1<<" ";
							mp[i][0]++;
						}
						cout<<endl;
						flag=true;
						break;
					}
				}
				break;
				
			case 5:
				_rep(i,1,21)
				{
					if(mp[i][0]<1)
					{
						_rep(j,0,5)
						{
							cout<<(i-1)*5+mp[i][0]+1<<" ";
							mp[i][0]++;
						}
						cout<<endl;
						flag=true;
						break;
					}
				}
				break;
			
		}//end of switch
		//没能分配到连续的座位 
		if(flag==false)
		{
			_rep(i,1,21)
			{
				if(order<=0)
					break;
				if(mp[i][0]<5&&order>0)
				{
					int t=5-mp[i][0];
					_rep(j,0,t)
					{
						cout<<(i-1)*5+mp[i][0]+1<<" ";
						mp[i][0]++;
						order--;
						if(order==0)
						{
							cout<<endl;
							flag=false;
							break;
						}
					}
				}
			}
		}
		flag=false;
	}//end of for n
	
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
}
