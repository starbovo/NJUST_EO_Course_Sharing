#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn
using namespace std;
int a[10][10],cnt;
bool check(int x){
	if(x==1) return false;
	int temp=sqrt(x);
	for(int i=2;i<=temp;i++){
		if(x%i==0) return false;
	}
	return true;
}
void change(int &x){
	for(int i=x+1;;i++){
		if(check(i)){
			x=i; return ;
		}
	}
}
signed main(){
	int k=0;
	printf("变换之前的数组是:\n");
	for(int i=1;i<=4;i++,putchar('\n'))
		for(int j=1;j<=4;j++)
			a[i][j]=++k,printf("%d ",a[i][j]);
	for(int i=1;i<=4;i++)
		for(int j=i;j<=4;j++)
			if(check(a[i][j])) change(a[i][j]),cnt++;
	printf("\n变换之后的数组是:\n"); 
	for(int i=1;i<=4;i++,putchar('\n'))
		for(int j=1;j<=4;j++)
			printf("%d ",a[i][j]);
	printf("\n素数个数是:%d个",cnt);
	return 0;
}
