#include<iostream>
using namespace std;
char str[100],str1[100],ans[100];
int i,j=0,m=0,cnt=0,flag=0,f1=0;
int main(){
	cin.getline(str,100);
	for(i=0;str[i]!='\0';i++){
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
			str1[cnt]=str[i];
			cnt++; flag=1;
		}
		else flag=0;
		if(m<cnt && (flag == 0 || str[i+1] == '\0')){
			m=cnt;
			for(j=0;j<m;j++) ans[j]=str1[j];
			cnt=0;
		}
		if(flag==0) cnt=0;
	}
	for(i=0;i<m;i++) cout<<ans[i];
	return 0;
}
