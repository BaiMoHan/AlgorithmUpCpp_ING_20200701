//stack的基本操作（均可直接使用STL）

//清空
void clear()
{
	TOP=-1;
 } 
 
 
//获取栈内元素个数
int size(){
	return TOP+1;
} 

//判空
bool empty(){
	return TOP==-1?true:false; 
} 

//进栈
void push(int x){
	st[++TOP]=x;
} 

//出栈
void pop(){
	TOP--;
} 

//取栈顶元素
int top()
{
	return st[TOP];
 } 



//STL中并没有实现栈的清空,因此需要如下操作 
while(!st.empty){
	st.pop();
} 






