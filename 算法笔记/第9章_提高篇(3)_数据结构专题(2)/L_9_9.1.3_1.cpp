//�������Ĵ洢�ṹ
struct node{
	typename data;	//������
	node* lchild;	//ָ�����������ڵ��ָ��
	node* rchild;	//ָ�����������ڵ��ָ�� 
}; 
//�����ڶ���������ǰ���ڵ㲻����,��˵�ַһ����Ϊnull
node* root=NULL;
//�������½����
node* newNode(int v){
	node* Node=new node;	//����һ��node�ͱ����ĵ�ַ�ռ�
	Node->data=v;		//����ȨֵΪv
	Node->lchild=Node->rchild=NULL;	//��ʼ״̬��û�����Һ���
	return Node;	//�����½����ĵ�ַ 
} 
