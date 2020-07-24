//简易计算器,中缀表达式、后缀表达式
#include<iostream>
#include<string>//一次性读取字符串 
#include<map>//用来对操作符优先级的映射
#include<cstdio>
#include<stack>//操作符栈，后缀表达式计算栈
#include<queue>//后缀表达式队列
using namespace std;

struct node{	//表达式字符结构体
	double num;//数值部分,double高精度便于精准 
	char op;//操作符
	bool flag;//flag=true为操作数,flag=false为操作符 
}; 
//全局变量 
string str;//读取表达式
stack<node> s;//计算前操作符栈
queue<node> q;//后缀表达式队列
stack<node> st;//计算时中间结果栈 
map<char,int> op;//操作符的映射

void change(){	//将中缀表达式转换成后缀表达式
	//中间变量 
	double num;
	node temp;
	for(int i=0;i<str.size();){//此处不需要i++,步进留在后面对应步骤
		//str里面全是字符元素,先要进行拼接成数字 
		if(str[i]>='0'&&str[i]<='9') {	//如果是数字
			temp.flag=true;	//操作数的标记为true
			temp.num=str[i++]='0';//字符转换为数值
			
			//数字可能不止一位,一直拼接下去
			while(i<str.length()&&str[i]>='0'&&str[i]<='9')//只要后面是数字,就不断拼接
			{
				temp.num=temp.num*10+(str[i]-'0');//数字串的拼接
				i++;	//步进 
			 } 
			q.push(temp);//拼接成一个完整的数后入后缀表达式队列	 
		}else{	//如果是操作符
			temp.flag=false;//操作符的标记为false
			//只要操作符栈的栈顶元素比该操作符优先级高
			//就把操作符栈顶元素弹出来加入到后缀表达式的队列中 
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push((s.top()));//入后缀表达式队列
				s.pop();//从操作符栈弹出 
			} 
			temp.op=str[i];
			s.push(temp);//把该操作符入栈
			i++;//步进 
		} //end else
	}//end for 
	while(!s.empty())//操作符栈非空，全部加入到后缀表达式队列队列中
	{
		q.push(s.top());
		s.pop();//从操作符栈弹出 
	 } 
} 

double cal(){	//计算后缀表达式 
	//中间变量 
	double temp1,temp2;
	node cur,temp;
	
	while(!q.empty()){	//一直处理到后缀表达式队列为空 
		cur=q.front();//记录队列队首元素
		q.pop();//弹出队首元素 
		if(cur.flag==true)	//如果是操作数
			st.push(cur);	//操作数进中间结果栈
		else{	//说明是操作符 
	/************************************************
			if(!st.empty()){  //出栈前先判断是否非空
				temp2=st.top(); 
				st.pop(); 
			}//end if 出栈 
			
	***************************************************/
			if(st.size()>=2)//要保证一个操作符能弹出两个有效操作数
			{
				temp2=st.top().num;//先弹出的是操作符右边的数,因为栈后进先出 
				st.pop();
				temp1=st.top().num;
				st.pop(); 
			 } //end if 弹数
			else{	//报错选项 
				printf("Error\n"); 
			} //end else报错
			
			//根据操作符类型,进行运算处理
			if(cur.op=='+') //加法 
				temp.num=temp1+temp2;
			else if(cur.op=='-')//减法
				temp.num=temp1-temp2;
			else if(cur.op=='*')//乘法
				temp.num=temp1*temp2;
			else	//除法
				temp.num=temp1/temp2;
				
			st.push(temp);//运算完后将结果入栈 
			 
		}//end else 操作符处理 
		
	} //end while
	
	//运算完后中间结果栈理想情况放的是最终结果 
	if(st.size()==1)
		return st.top().num;//返回结果
	else{
		printf("Error\n");
		return 0;
	} //end else
	  
}	//end cal 






 
int main(){
	//设置操作符的优先级 
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	//括号比较特殊 
	op['(']=3;
	op[')']=4; 
	
	//读取输入的表达式串,并去掉空格
	while(getline(cin,str),str!="0"){
		for(string::iterator it=str.begin();it!=str.end();it++)
			if(*it==' ')
				str.erase(it);//去掉空格 
	
		while(!s.empty()) //清空栈,初始化
			s.pop();
		
		while(!st.empty()) //清空栈,初始化
			st.pop();
			
		change();//将中缀表达式转换成后缀表达式 
		
		printf("%.2f\n",cal());//计算后缀表达式结果 
	}//end while 
	
	return 0; 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
