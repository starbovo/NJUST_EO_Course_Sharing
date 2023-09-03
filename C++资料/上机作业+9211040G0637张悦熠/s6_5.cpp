#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double f(double x){
	return x*x+3*x-4;
}
double f1(double x){
	return 2*x+3;
}
double solve(double x){
	double temp=x-f(x)/f1(x);
	if(fabs(f(temp))>=0.00001) return solve(temp);
	else return temp;
}
signed main(){
	double x=0;
	printf("%lf\n",solve(x));
	return 0;
}
