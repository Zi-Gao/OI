#include <cstdio>
using namespace std;
int main(){
	int a;
	int b = 0;
	int i = 1;
	
	scanf("%d",&a);
	
	while(i<=a){
		if(i%10 == 7 | i % 7 ==0){
			printf("%d ",i);
			b++;
		}
		i++;
	}
	printf("%d",b);
	
	return 0;
}
