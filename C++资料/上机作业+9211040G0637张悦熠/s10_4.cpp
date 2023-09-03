#include<iostream>
using namespace std;
int a[100000],i,j,n,cnt=0;
signed main(){
	scanf("%d",&n);
	while(n){
		for(i=cnt;i>=0;i--){
			if(i==0) {a[i]=n;break;}
			if(n>a[i-1]){a[i]=n;break;}
			else a[i]=a[i-1];
		}
		scanf("%d",&n);
		cnt++;
	}
	for(i=0;i<cnt;i++) printf("%d ",a[i]);
	return 0;
}
