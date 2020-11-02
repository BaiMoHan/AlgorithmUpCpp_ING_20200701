#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;
int main(){
	string str1,str2;
	map<string,string> mp;
	char c1[20];
	while(true){
		scanf("%s",&c1);
		str1.assign(c1,strlen(c1));
		if(getchar()=='\n')
			break;

//		cout<<str1<<endl;
		scanf("%s",&c1);
		str2.assign(c1,strlen(c1));
//		cout<<str2<<endl;
		mp[str2]=str1;
//		for(map<string,string>::iterator it=mp.begin();it!=mp.end();it++){
//			cout<<"-------------"<<endl;
//			cout<<it->first<<" "<<it->second<<endl;
//		}
	}
	
	do{
		if(mp.count(str1)==1)
		{
			cout<<mp[str1]<<endl;
		}else{
			cout<<"eh"<<endl;
		}
	}while(cin>>str1);
	return 0;
} 
