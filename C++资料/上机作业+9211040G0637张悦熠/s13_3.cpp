#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 10000
using namespace std;
char s[maxn];
int b[maxn],top;
int getdata(char s[]){
	int len=strlen(s),cnt=0;
	s[len]='a'; len++;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9') cnt++;
		else{
			if(!cnt) continue;
			else{
				top++;
				for(int j=i-cnt;j<i;j++){
					b[top]=b[top]*10+s[j]-'0';
				}
				cnt=0;
			} 
		}
	}
	return top;
}
int main(){
	cin.getline(s,1000);
	getdata(s);
	for(int i=1;i<=top;i++) printf("%d ",b[i]);
	return 0;
}
