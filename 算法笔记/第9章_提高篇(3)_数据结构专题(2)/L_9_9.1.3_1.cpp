//二叉树的存储结构
struct node{
	typename data;	//数据域
	node* lchild;	//指向左子树根节点的指针
	node* rchild;	//指向右子树根节点的指针 
}; 
//由于在二叉树建树前根节点不存在,因此地址一般设为null
node* root=NULL;
//二叉树新建结点
node* newNode(int v){
	node* Node=new node;	//申请一个node型变量的地址空间
	Node->data=v;		//结点的权值为v
	Node->lchild=Node->rchild=NULL;	//初始状态下没有左右孩子
	return Node;	//返回新建结点的地址 
} 
