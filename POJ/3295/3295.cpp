#include<iostream>
using namespace std;
int cnt;
char str[101];	//������������� 
bool step(char str[101],int tk){
    cnt++;
    switch(str[cnt]){
        case 'p':return tk&1;
        case 'q':return(tk>>1)&1;
        case 'r':return(tk>>2)&1;
        case 's':return(tk>>3)&1;
        case 't':return(tk>>4)&1;
        case 'N':return !step(str,tk);
        case 'K':return step(str,tk)&step(str,tk);
        case 'A':return step(str,tk)|step(str,tk);
        case 'C':return !step(str,tk)|step(str,tk);
        case 'E':return step(str,tk)==step(str,tk);
    }
}
bool judge(char str[101]){
	//һ����5�ֱ�Ԫ���ܹ�2^5=32��ȡֵ������ö�� 
    for(int i=0;i<32;i++){
        cnt=-1;
        if(!step(str,i)) return 0;    
    }
    return 1;
}
int main(){
    while(cin>>str){   
        if(str[0]=='0') break;
        if(judge(str))
            cout<<"tautology"<<endl;
        else
            cout<<"not"<<endl;
    }
    return 0;
}
