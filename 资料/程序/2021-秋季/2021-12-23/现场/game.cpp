#include <cstdio>
using namespace std;
long long int game(int a,int b,int c);

int main(){
    freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int in;
	long long int out=0;
	scanf("%d",&in);
	for(int i=0;(in-i)>=(i-1);i++){
		out+=game(in-i,i,0)%1000007;
//		printf("%lld",game(in-i,i,0));
	}
	printf("%lld",out%1000007);

    fclose(stdin);
	fclose(stdout); 
	return 0;
}

long long int game(int a,int b,int c){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a+b-c;
	}
	if(a==1){
		return 1;
	}
//	if(a==2&&b==2){
//		return 3;
//	}
//	if(a == b + 1){
//		return 1;
//	}
//	if(a == b){
//		return 2;
//	}
//	if(a + 1 == b){
//		return 1;
//	}
	return game(a,b-1,1)+game(a-1,b,0);
}
