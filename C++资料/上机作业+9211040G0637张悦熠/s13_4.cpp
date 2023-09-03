#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 1000
using namespace std;
char s1[maxn],s2[maxn];
int fun(char *str,char *substr){
	int len1=strlen(str);
	int len2=strlen(substr);
	int ans=0;
	for(int i=0;i<len1;i++){
		bool flag=0;
		for(int j=0;j<len2;j++){
			if(str[i+j]!=substr[j]) {flag=1;break;}
		}
		ans+=!flag;
	}
	return ans;
}
int main(){
	printf("ÇëÊäÈëÄ¸´®:");
	scanf("%s",s1);
	printf("ÇëÊäÈë×Ó´®:");
	scanf("%s",s2);
	printf("%d\n",fun(s1,s2)); 
	return 0;
}
