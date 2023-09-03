#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;
int cnt; 
signed main(){
	for(int i=1;i<=599;i++){
		if(i%3) continue;
		int flag=0,x=i;
		while(x){
			if(x%10==5) flag=1;
			x/=10;
		}
		if(flag) printf("µÚ%d¸ö: %d\n",++cnt,i);
	}
	return 0;
}
