#include <cstdio>
using namespace std;
int main(){
    freopen("seqsum.in","r",stdin);
	freopen("seqsum.out","w",stdout);

	int n;
	long long int out=0;
	bool flag=false;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		if((i%4==1)||(i%4==0)||(i==1)){//´íÎó:i%4=[0,1,2,3] 
			out-=i;
		}else{
			out+=i;
		}
	}
	
	printf("%lld",out);

    fclose(stdin);
	fclose(stdout); 
	return 0;
}
