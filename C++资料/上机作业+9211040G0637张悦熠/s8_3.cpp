#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id,val;
}a[100];
bool cmp(node a,node b) {return a.val<b.val;}
int main(){
	a[1].val=2;
	a[2].val=5;
	a[3].val=78;
	a[4].val=4;
	a[5].val=6;
	a[6].val=3;
	a[7].val=89;
	a[8].val=12;
	a[9].val=15;
	a[10].val=34;
	for(int i=1;i<=10;i++) a[i].id=i;
	sort(a+1,a+1+10,cmp);
	printf("max=%d, maxindex=%d\n",a[10].val,a[10].id);
}
