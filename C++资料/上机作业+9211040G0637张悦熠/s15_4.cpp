#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Num{
	int n,count,*p;
public:	
	NUM(int num) {n=count=num; p=new int;}
	int isdiff(int num){
		bool book[10];
		memset(book,0,sizeof book);
		while(num){
			if(book[num%10]) return false;
			book[num%10]=true;
			num/=10;
		}
		return true;
	}
	int issort(int num){
		int pre=10;
		while(num){
			if(num%10>pre) return false;
			pre=num%10;
			num/=10;
		}
		return true;
	}
	void print(int x) {printf("%d %8d\n",x,x*x);}
	void process(int n){
		int cnt=0;
		printf("x        x*x\n");
		for(int i=1;i<=n;i++){
			if(!issort(i*i) || !isdiff(i*i)) continue;
			print(i); cnt++;
		}
		printf("×ÜÊýÎª: %d\n",cnt);
	}
}solve;
int main(){
	int n;
	scanf("%d",&n);
	solve.process(n);
	return 0;
}
