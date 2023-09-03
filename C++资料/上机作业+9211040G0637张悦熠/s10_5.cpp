#include<iostream>
using namespace std;
int a[]={5,26,98,77,1,27,30},b[10]={0},i;
signed main(){
	for(i=0;i<7;i++){
		while(a[i]){
			b[a[i]%10]++;
			a[i]/=10;
		}
	}
	cout<<"0-9依次出现";
	for(i=0;i<10;i++) cout<<b[i]<<" ";
	cout<<"次"<<endl;
	return 0;
}
