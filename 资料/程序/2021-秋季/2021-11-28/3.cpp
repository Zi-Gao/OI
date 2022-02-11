#include <cstdio>
using namespace std;
int main(){
	int a=1,b;
	while(a<=3){
		b=1;
		while(b<=5){
			printf("*");
			b=b+1; 
		}
		printf("\n");
		a+=1;
	}
	return 0;
}
