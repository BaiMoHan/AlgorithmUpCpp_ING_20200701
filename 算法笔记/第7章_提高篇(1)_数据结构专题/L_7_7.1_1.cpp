//stack�Ļ�������������ֱ��ʹ��STL��

//���
void clear()
{
	TOP=-1;
 } 
 
 
//��ȡջ��Ԫ�ظ���
int size(){
	return TOP+1;
} 

//�п�
bool empty(){
	return TOP==-1?true:false; 
} 

//��ջ
void push(int x){
	st[++TOP]=x;
} 

//��ջ
void pop(){
	TOP--;
} 

//ȡջ��Ԫ��
int top()
{
	return st[TOP];
 } 



//STL�в�û��ʵ��ջ�����,�����Ҫ���²��� 
while(!st.empty){
	st.pop();
} 






