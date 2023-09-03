#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld %lld",&n,&k);
		if(k==1 && n!=1) printf("No\n");
		else if(k==1 && n==1) printf("Yes\n");
		else{
			if(k%2){
				if(n%k==0 && n!=k){
					printf("No\n");
					continue;
				}
				int a=n%k;
				int b=k-a;
				int q=n/k;
				int r1=n/2/q;
				int l1=ceil((n/2-a)*1.0/q);
				int l2=ceil(n/2*1.0/(q+1));
				int r2=(n/2+b)/(q+1);
				if(r1>=l1 && r2>=l2){
					if(r2>=r1 && r1>=l2 || r2>=l1 && l1>=l2 || r2>=r1 && l1>=l2 || r1>=r2 && l2>=l1) printf("Yes\n");
					else printf("No\n");
				}else printf("No\n");
			}else{
				printf("Yes\n");
			}
		}
	}
	return 0;
}
