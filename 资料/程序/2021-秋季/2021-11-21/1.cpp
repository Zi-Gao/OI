#include <cstdio>
using namespace std;
int main(){
	int x;

	if(1>2)//if 
		printf("yes");
	else
		printf("no");
	
	printf("\n");
	
	if(1)//0为false，其余为true 
		printf("yes");
	else
		printf("no");

	printf("\n");

	if (x=0)//表达式可以返回值 
		printf("yes");
	else
		printf("no");
	printf("\n");
	printf("%d", (x == 0)); 

	return 0;
}
