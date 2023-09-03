#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn
using namespace std;
int a[3][4]={{2,3,4,5},{12,13,14,15},{1,2,3,4}};
void findaverage(){
	int (*p)[4]=a,ans=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			ans+=*(*(p+i)+j);
		}
	}
	printf("ave%.1lf ",ans/12.0);
}
void findmax(){
	int (*p)[4]=a,Max=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			Max=max(Max,*(*(p+i)+j));
		}
	}
	printf("max=%d ",Max);
}
void findmin(){
	int (*p)[4]=a,Min=99999;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			Min=min(Min,*(*(p+i)+j));
		}
	}
	printf("min=%d ",Min);
}
int main(){
	findaverage();
	findmax();
	findmin();
	return 0;
}
