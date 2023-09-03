#include<iostream>
#define maxn 100000100
using namespace std;
int Max,n,prime[maxn],tot;
bool vis[maxn];
void getprime(int Max){
	vis[1]=true;
	for(int i=1;i<=Max;i++){
		if(!vis[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<=Max;j++){
			vis[prime[j]*i]=true;
			if(i%prime[j]==0) break;
		}
	}
}
signed main(){
	Max=200; 
	getprime(Max);
	for(int i=1;i<=tot;i++) printf("%d\n",prime[i]);
	return 0;
}

