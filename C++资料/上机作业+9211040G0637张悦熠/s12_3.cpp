#include<cstdio>
using namespace std;
int main(){
	int a[100],Max,Maxpos=1; Max=a[1]=a[0]=55;
	for(int i=2;i<=16;i++){
		a[i]=(a[i-1]*15+97)%256,a[0]+=a[i];
		if(Max<a[i]) Max=a[i],Maxpos=i;
	}
	printf("a数组元素为:\n");
	for(int i=1;i<=16;i++) printf("%d ",a[i]);
	printf("\n平均值=%.1lf\n最大值=%d\n",a[0]/16.0,Max);
	printf("删除%d后的数组元素:\n",Max);
	for(int i=1;i<=16;i++) if(i!=Maxpos) printf("%d ",a[i]);
    return 0;
}
