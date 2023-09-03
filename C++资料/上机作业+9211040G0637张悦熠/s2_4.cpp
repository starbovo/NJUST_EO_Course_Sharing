#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

signed main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double delta=b*b-4*a*c;
	if(delta<0) printf("ÎÞÊµ¸ù!"),exit(0);
	printf("%lf %lf\n",(-b+sqrt(delta))/2/a,(-b-sqrt(delta))/2/a);
	return 0;
}
