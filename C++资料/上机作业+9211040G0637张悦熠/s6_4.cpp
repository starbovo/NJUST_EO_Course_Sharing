#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double f(double x){
	return x*x+3*x-4;
}
signed main(){
	double x1,x2,x;
	scanf("%lf %lf",&x2,&x1); //要倒过来输入 
	double X2=x2,X1=x1; 
	do{
		x=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
		if(f(x)*f(x1)<0) x2=x;
		else x1=x;
	}while(fabs(f(x))>0.00001);
	if(!(x>=X1 && x<=X2)) printf("没有根"); 
	else printf("%lf",x);
	return 0;
}
