#include <cstdio>
using namespace std;
//求水仙花数2
int main(){
	int a,b,c; // 1<a<9, 0<b<9, 0<c<9
	
	a = 1;
	while(a <= 9){
		b=0;
		while(b <= 9){
			c = 0;
			while(c <= 9){
				if((a*100+b*10+c) == (a*a*a+b*b*b+c*c*c))
					printf("%d%d%d ",a,b,c);
				c++;
			}
			b++;
		}
		a++;
	}
	
	return 0;
}
