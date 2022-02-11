//奇偶分别处理并累加结果 
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	long long int n;	
	freopen("seqsum.in", "r", stdin);
	freopen("seqsum.out", "w", stdout); 
	scanf("%lld", &n);
	
	long long int s = 0, k1 = -1, k2 = 1;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			s = s + k1 * i;
			k1 = -k1;
		}			
		else{
			s = s + k2 * i;
			k2 = -k2;
		}	
	}
	printf("%lld", s);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
