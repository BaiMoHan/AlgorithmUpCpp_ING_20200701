//�ݹ�д��
//���������Ĳ��ҡ��޸ģ��ȸ����� 
void search(node* root,int x,int newdata){
	if(root==NULL){
		return ;//����,����ͬ(�ݹ�߽�) 
	}
	if(root->data==x){	//�ҵ�������Ϊx�Ľ��,�����޸ĳ�newdata
		root->data=newdata; 
	}
	search(root->lchild,x,newdata);	//������������x(�ݹ�ʽ) 
	search(root->rchild,x,newdata);	//������������x(�ݹ�ʽ) 
} 
