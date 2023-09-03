#include<iostream>
using namespace std;
int n;
int judge(int n){
	for(int i=2;i<n;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
signed main(){
	cin>>n;
	for(int i=2;i<=n/2;i++){
		if(judge(i)==1&&judge(n-i)==1)
			cout<<n<<"="<<i<<"+"<<n-i<<endl;
	}
	return 0;
}
