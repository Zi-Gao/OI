#include <cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	int a,b,k=1;
	scanf("%d %d",&a,&b);
	if(a == 1){
		a++;
	}
	for(int i=a;i<=b;i++){
//		int i=6;
		int t=1;
		for(int j=2;j<=i/2;j++){
			if(i%j==0){
				t+=j;
			}
		}
		if(i==t){
			if(k==0){
				printf("\n");
			}
			k*=0;
			printf("%d=1",i);
			for(int j=2;j<=i/2;j++){
				if(i%j==0){
					printf("+%d",j);
				}
			}
			
		}
	}
	if(k){
		printf("No");
	}
//	int test;
//	scanf("%d",&test);
//	printf("%d=1",test);
//	for(int i=2;i<=test/2;i++){
//		if(test%i==0){
//			printf("+%d",i);
//		}
//	}
//	for(int i=2;i<=test/2;i++){
//		if(test%i==0){
//			printf("+%d",i);
//		}
//	}
//	printf("+%d",test);
	

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
