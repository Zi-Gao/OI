#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int a[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=1;i<=5;i++){
		int t;
		cin >> t;
		a[t]+=1;
	}
	for(int i=0;i<10;i++){
		for(int j=1;j<=a[i];j++){
			printf("%d ",i);
		}
	}
	return 0;
}
