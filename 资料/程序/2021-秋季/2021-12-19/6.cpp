#include <cstdio>
#include <iostream>
using namespace std;
int digit(int n,int k);
int check(int n,int d);

int main(){
	printf("%d",check(8,11));
	return 0;
}
int power(int a,int n){
	if(n==1){
		return a;
	}
	return a*power(a,n-1);
}
int digit(int n,int k){
	if(k==1){
		return n%10;
	}
	return digit(n/10,k-1);
}
int check(int n,int d){
	for(int i=1;;i++){
		if(digit(d,i)==n){
			return 1;
		}
		if(digit(d,i)==0){
			return 0;
		}
	}
	
}
