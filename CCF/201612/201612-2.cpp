#include<iostream>
using namespace std;
#define OJ 98
#define _rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
int main()
{
	#ifndef OJ
	freopen("201612-2.txt","r",stdin);
	#endif
	long n;
	cin>>n;
	long res=0;
    if (n<=3500)
    {
   	   res=n;
    }
    else if(n<=4955)
    {
        res=(n-3500)/0.97+3500;
    }
    else if(n<=7655)
    {
        res=(n-4955)/0.9+5000;
    }
    else if(n<=11255)
    {
        res=(n-7655)/0.80+8000;
    }
    else if(n<=30755)
    {
        res=(n-11255)/0.75+12500;
    }
    else if(n<= 44755)
    {
        res=(n-30755)/0.7+38500;
    }
    else if(n<=61005)
    {
        res=(n-44755)/0.65+58500;
    }
    else
    {
        res=(n-61005)/0.55+ 83500;
    }

    
	cout<<res;
	#ifndef OJ
	fclose(stdin);
	#endif
	return 0;
 } 


/*


0-3500		 	(0,3500] 		0 		0
3500-5000		(3500,4955]		0.03	45
4500-8000		(4955,7655]		0.10	300
8000-12500		(7655,11255]	0.20	900	
12500-38500		(11255,30755]	0.25	6500
38500-58500		(21255,44755]	0.30	6000
58500-83500		(44755,61005]	0.35	8750
83500			(61005,			0.45	
*/
