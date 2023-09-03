#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn
using namespace std;
int n1,n2;
class STR{
	char *p;
public:
	STR(char *s){
		p=new char[1000];
		memset(p,0,sizeof p);
		int len=strlen(s);
		for(int i=0;i<len;i++) 
			this->p[i]=s[i];
	}
	void fun(char *s,int n1,int n2){
		int len=0;
		while(this->p[len]!='\0') len++;
		char temps[1000];
		for(int i=0;i<len;i++) 
			temps[i]=this->p[i];
		for(int i=len;i<=len+n2;i++) 
			temps[i]=s[n1+i-len];
		p=temps;
	}
	char *get(){return this->p;}
	void print(){cout<<this->p;}
};
signed main(){
	STR s1("abcdefg");
	STR s2("12345678");
	scanf("%d %d",&n1,&n2);   // ‰»Î 2 5 
	s1.fun(s2.get(),n1,n2);
	s1.print();
	return 0;
}
