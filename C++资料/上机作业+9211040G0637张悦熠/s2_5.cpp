#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;

signed main(){
	double a,b;
	char c;
	scanf("%lf%c%lf",&a,&c,&b);
	if(c=='+') printf("%lf\n",a+b);
	else if(c=='-') printf("%lf\n",a-b);
	else if(c=='*') printf("%lf\n",a*b);
	else if(c=='/') printf("%lf\n",a/b); 
	else printf("输入了错误的运算符!");
	return 0;
}
