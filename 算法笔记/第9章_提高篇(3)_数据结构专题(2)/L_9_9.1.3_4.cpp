//�������Ĵ�����ʵ���Ƕ������Ĳ������
node* Create(int data[],int n){
	node* root=NULL;	//�½��ո����root
	for(int i=0;i<n;i++){
		insert(root,data[i]);	//��data[0]~data[n-1]����������� 
	} 
	return root;	//���ظ��ڵ� 
} 
