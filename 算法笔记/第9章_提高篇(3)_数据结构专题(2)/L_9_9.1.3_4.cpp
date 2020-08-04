//二叉树的创建其实就是二叉树的插入过程
node* Create(int data[],int n){
	node* root=NULL;	//新建空根结点root
	for(int i=0;i<n;i++){
		insert(root,data[i]);	//将data[0]~data[n-1]插入二叉树中 
	} 
	return root;	//返回根节点 
} 
