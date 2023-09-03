#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;

signed main(){
	int x,ans=0;
	scanf("%d",&x);
	while(x){
		ans+=x%10;
		x/=10;
	}
	printf("%d\n",ans);
	return 0;
}
