#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;

signed main(){
	for(int i=1;i<=1000;i++){
		int x=i,ans=0;
		for(int j=1;j<i;j++){
			if(i%j==0) ans+=j;
		}
		if(ans==i) printf("%d\n",i);
	} 
	return 0;
}
