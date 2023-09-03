#include<cstdio>
#include<algorithm>
#include<ctime>
#define maxn 100
using namespace std;
class Circle{
public:	
	int num[maxn],Max[maxn],Min[maxn],sum_max,sum_min=500;
	Circle(){
		for(int i=1;i<=20;i++) num[i]=rand()%100;
		for(int i=21;i<=40;i++) num[i]=num[i-20];//通过倍长解决环的问题 
	}
	void Find_Max_Min(){
		for(int i=1;i<=20;i++){
			int nowsum=num[i]+num[i+1]+num[i+2]+num[i+3];
			if(nowsum>sum_max){
				sum_max=nowsum;
				Max[1]=num[i];
				Max[2]=num[i+1];
				Max[3]=num[i+2];
				Max[4]=num[i+3];
			}
			if(nowsum<sum_min){
				sum_min=nowsum;
				Min[1]=num[i];
				Min[2]=num[i+1];
				Min[3]=num[i+2];
				Min[4]=num[i+3];
			}
		}
	}
	void Show(){
		printf("整个数列是:\n");
		for(int i=1;i<=20;i++) printf("%d ",num[i]); 
		printf("\n\n最大的四个数是:%d %d %d %d\n",Max[1],Max[2],Max[3],Max[4]);
		printf("他们的和是:%d\n\n",sum_max);
		printf("最小的四个数是:%d %d %d %d\n",Min[1],Min[2],Min[3],Min[4]);
		printf("他们的和是:%d\n\n",sum_min);
	}
};
int main(){
	srand((unsigned)time(0));
	Circle cir;
	cir.Find_Max_Min();
	cir.Show();
	return 0;
}
