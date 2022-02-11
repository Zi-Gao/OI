#include <cstdio>
using namespace std;
int main(){
    freopen("taxicost.in","r",stdin);
	freopen("taxicost.out","w",stdout);

	long long int in;
	scanf("%lld",&in);
	if(in <= 15100){//不用下车 
		if(in<=3000){
			printf("%lld %d",in,8);
		}else{//需要算>3000 
			printf("%lld %lld",in,(in-3000)/550+8);
		}
	}
	
	if(in > 15100 && in <= 18100){//3000下一次车 
		printf("%d %lld",3000,(in-6000)/550+16);
	}
	
	if(in > 18100 && in <= 30200){
//		printf("%d %d",15100,(in-6000)/550+16);
//		printf("\n");
		printf("%lld %lld",in-15100,(in-18100)/550+30+8);
	}
	
	if(in > 30200){
		printf("%lld %lld",15100,(in-30200)/370+44+16);
	}

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
