#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int a=1,b,n=9,i=1;
	printf("*");
	while(a<=n){
		printf("%4d",a);
		a++;
	}
	printf("\n");
	a=1;
	while(a<=n){
		b=1;
		cout << a;
		while(b<=n){
			printf("%4d",a*b);
			b++;
			i++;
		}
		printf("\n");
		a++;
	}
	return 0;
}
