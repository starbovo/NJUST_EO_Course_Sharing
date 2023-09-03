#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;
int c[100][100];
inline void build() {
	c[0][0]=1;
	c[1][0]=c[1][1]=1;
	for(int i=2; i<=10; i++) {
		c[i][0]=1;
		for(int j=1; j<=i; j++) {
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
int main(){
	build();
	printf("1\n");
	for(int i=2;i<=10;i++,putchar('\n')){
		printf("1 ");
		for(int j=1;j<=i;j++){
			printf("%d ",c[i][j]);
		}
	}
    return 0;
}
