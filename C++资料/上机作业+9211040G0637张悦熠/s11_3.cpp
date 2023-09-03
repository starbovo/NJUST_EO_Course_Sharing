#include<iostream>
#include<cstring>
using namespace std;
int ans;
char s[2000];
bool judge(char x){
	return (x>='a'&&x<='z') || (x>='A' && x<='Z');
}
int main(){//只要不是大小写字母都算作间隔 
	cin.getline(s,1000);
	int len=strlen(s),now=0;
	while(now<len){
		if(!judge(s[now])) {now++;continue;}
		ans++;
		while(judge(s[now])) now++;
	}
	printf("%d\n",ans);
	return 0;
}
