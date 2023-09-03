#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn
using namespace std;

signed main(){
	double x=0.75;
	double y[100];
	y[1]=x;
	int now=2;
	while(1){
		y[now]=2/3.0*y[now-1]+x/3/y[now-1]/y[now-1];
		if(fabs(y[now]-y[now-1])<=0.00001) break;
		now++;
	}
	cout<<y[now];
	return 0;
}
