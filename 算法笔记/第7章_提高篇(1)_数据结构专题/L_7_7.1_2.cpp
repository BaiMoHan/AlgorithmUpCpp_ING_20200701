//���׼�����,��׺���ʽ����׺���ʽ
#include<iostream>
#include<string>//һ���Զ�ȡ�ַ��� 
#include<map>//�����Բ��������ȼ���ӳ��
#include<cstdio>
#include<stack>//������ջ����׺���ʽ����ջ
#include<queue>//��׺���ʽ����
using namespace std;

struct node{	//���ʽ�ַ��ṹ��
	double num;//��ֵ����,double�߾��ȱ��ھ�׼ 
	char op;//������
	bool flag;//flag=trueΪ������,flag=falseΪ������ 
}; 
//ȫ�ֱ��� 
string str;//��ȡ���ʽ
stack<node> s;//����ǰ������ջ
queue<node> q;//��׺���ʽ����
stack<node> st;//����ʱ�м���ջ 
map<char,int> op;//��������ӳ��

void change(){	//����׺���ʽת���ɺ�׺���ʽ
	//�м���� 
	double num;
	node temp;
	for(int i=0;i<str.size();){//�˴�����Ҫi++,�������ں����Ӧ����
		//str����ȫ���ַ�Ԫ��,��Ҫ����ƴ�ӳ����� 
		if(str[i]>='0'&&str[i]<='9') {	//���������
			temp.flag=true;	//�������ı��Ϊtrue
			temp.num=str[i++]='0';//�ַ�ת��Ϊ��ֵ
			
			//���ֿ��ܲ�ֹһλ,һֱƴ����ȥ
			while(i<str.length()&&str[i]>='0'&&str[i]<='9')//ֻҪ����������,�Ͳ���ƴ��
			{
				temp.num=temp.num*10+(str[i]-'0');//���ִ���ƴ��
				i++;	//���� 
			 } 
			q.push(temp);//ƴ�ӳ�һ���������������׺���ʽ����	 
		}else{	//����ǲ�����
			temp.flag=false;//�������ı��Ϊfalse
			//ֻҪ������ջ��ջ��Ԫ�رȸò��������ȼ���
			//�ͰѲ�����ջ��Ԫ�ص��������뵽��׺���ʽ�Ķ����� 
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push((s.top()));//���׺���ʽ����
				s.pop();//�Ӳ�����ջ���� 
			} 
			temp.op=str[i];
			s.push(temp);//�Ѹò�������ջ
			i++;//���� 
		} //end else
	}//end for 
	while(!s.empty())//������ջ�ǿգ�ȫ�����뵽��׺���ʽ���ж�����
	{
		q.push(s.top());
		s.pop();//�Ӳ�����ջ���� 
	 } 
} 

double cal(){	//�����׺���ʽ 
	//�м���� 
	double temp1,temp2;
	node cur,temp;
	
	while(!q.empty()){	//һֱ������׺���ʽ����Ϊ�� 
		cur=q.front();//��¼���ж���Ԫ��
		q.pop();//��������Ԫ�� 
		if(cur.flag==true)	//����ǲ�����
			st.push(cur);	//���������м���ջ
		else{	//˵���ǲ����� 
	/************************************************
			if(!st.empty()){  //��ջǰ���ж��Ƿ�ǿ�
				temp2=st.top(); 
				st.pop(); 
			}//end if ��ջ 
			
	***************************************************/
			if(st.size()>=2)//Ҫ��֤һ���������ܵ���������Ч������
			{
				temp2=st.top().num;//�ȵ������ǲ������ұߵ���,��Ϊջ����ȳ� 
				st.pop();
				temp1=st.top().num;
				st.pop(); 
			 } //end if ����
			else{	//����ѡ�� 
				printf("Error\n"); 
			} //end else����
			
			//���ݲ���������,�������㴦��
			if(cur.op=='+') //�ӷ� 
				temp.num=temp1+temp2;
			else if(cur.op=='-')//����
				temp.num=temp1-temp2;
			else if(cur.op=='*')//�˷�
				temp.num=temp1*temp2;
			else	//����
				temp.num=temp1/temp2;
				
			st.push(temp);//������󽫽����ջ 
			 
		}//end else ���������� 
		
	} //end while
	
	//��������м���ջ��������ŵ������ս�� 
	if(st.size()==1)
		return st.top().num;//���ؽ��
	else{
		printf("Error\n");
		return 0;
	} //end else
	  
}	//end cal 






 
int main(){
	//���ò����������ȼ� 
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	//���űȽ����� 
	op['(']=3;
	op[')']=4; 
	
	//��ȡ����ı��ʽ��,��ȥ���ո�
	while(getline(cin,str),str!="0"){
		for(string::iterator it=str.begin();it!=str.end();it++)
			if(*it==' ')
				str.erase(it);//ȥ���ո� 
	
		while(!s.empty()) //���ջ,��ʼ��
			s.pop();
		
		while(!st.empty()) //���ջ,��ʼ��
			st.pop();
			
		change();//����׺���ʽת���ɺ�׺���ʽ 
		
		printf("%.2f\n",cal());//�����׺���ʽ��� 
	}//end while 
	
	return 0; 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
