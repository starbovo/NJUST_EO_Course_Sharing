#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;

signed main(){
	double ans=0,f[101],x; f[0]=1;
	int n;
	scanf("%d %lf",&n,&x);
	for(int i=1;i<=100;i++) f[i]=f[i-1]*i;
	double nowx=x;
	for(int i=1;i<=n;i++){
		int flag=(i%2==0?-1:1);
		ans+=flag*nowx/f[i*2-1];
		nowx=nowx*x*x;
	}
	printf("%lf",ans);
	return 0;
}
