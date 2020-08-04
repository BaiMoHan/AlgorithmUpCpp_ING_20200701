//递归写法
//二叉树结点的查找、修改，先根遍历 
void search(node* root,int x,int newdata){
	if(root==NULL){
		return ;//空树,死胡同(递归边界) 
	}
	if(root->data==x){	//找到数据域为x的结点,把它修改成newdata
		root->data=newdata; 
	}
	search(root->lchild,x,newdata);	//往左子树搜索x(递归式) 
	search(root->rchild,x,newdata);	//往右子树搜索x(递归式) 
} 
