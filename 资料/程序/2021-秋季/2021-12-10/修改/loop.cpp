#include <cstdio>
using namespace std;
int main(){
    freopen("loop.in","r",stdin);
	freopen("loop.out","w",stdout);
	
	long long int z=0,n;
	scanf("%lld",&n);
//	for (int a = 0; a <= n; a++){
//		for (int b = n; b >= 0; b--){
//			for (int c = -a; c < b; c++){
//				z++;
//			}	
//		}
//			
//	}
	printf("%lld",(n+1)*(n+1)*n);
		

	
    fclose(stdin);
	fclose(stdout); 
	return 0;
}
