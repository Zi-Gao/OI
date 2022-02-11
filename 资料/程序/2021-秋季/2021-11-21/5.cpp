#include <cstdio>
using namespace std;
//求水仙花数 
int main(){
	int i = 100;
	
	while(i < 1000){
		int a,b,c;
		a = i/100;
		b = (i/10)%10;
		c = i%10;
		if(i == (a*a*a+b*b*b+c*c*c)){
			printf("%d ",i);
		}
		i++;
	}
	
	return 0;
}
