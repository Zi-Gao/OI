#include <cstdio>
#include <iostream>
using namespace std;
int power(int a,int n);

int main(){
	printf("%d",power(-2,-10));
	return 0;
}

int power(int a,int n){
	if(n==1){
		return a;
	}
	return a*power(a,n-1);
}
