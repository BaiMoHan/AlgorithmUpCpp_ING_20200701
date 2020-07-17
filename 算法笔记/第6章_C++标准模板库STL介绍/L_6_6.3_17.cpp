#include<iostream>
#include<string>
using namespace std;
int n;//有效位数
string deal(string s,int &e){
	int k=0;//s的下标
	while(s.length()>0&&s[0]=='0'){//去掉前导0
		s.erase(s.begin());
	} 
	if(s[0]=='.'){	//去掉前导0后是小数点，说明s是小于1的数
		s.erase(s.begin());//去掉小数点
		while(s.length()>0&&s[0]=='0'){
			s.erase(s.begin());//去掉小数点后非零位前的所有0
			e--;//每去掉一个0,指数e减一 
		}
	}else{	//去掉前导0后不是小数点,则找到后面的小数点删除
		while(k<s.length()&&s[k]!='.'){	//寻找小数点 
			k++;
			e++;//相当于小数点左移,指数+1 
		} 
		if(k<s.length()){	//while结束后k<s.length(),说明碰到了小数点
			s.erase(s.begin()+k);//把小数点删除 
		}
	}
	
	if(s.length()==0)//删除了都是0后长度变成0，说明这个数是0
		e=0;//将指数设为0
	
	int num=0;
	k=0;
	string res;
	while(num<n){	//只要精度还没有到n 
		if(k<s.length())	//只要还有数字,就连接到res末尾
			res+=s[k++];
		else
			res+='0';//否则res末尾添加0
		num++;	//精度加1 
	}
	return res; 	
}
int main(){
	string s1,s2,s3,s4;
	cin>>n>>s1>>s2;
	int e1=0,e2=0;	//e1,e2为s1与s2的指数
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4&&e1==e2){	//主体相同且指数相同则yes
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl; 
	} 
	else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}
