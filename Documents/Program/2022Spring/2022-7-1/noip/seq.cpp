#include <cstdio>
using namespace std;


long long abs(long long in){
	return in>=0?in:-in;
}

//char dp[100000][100000]

int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	
	long long a1,a2,t,cnt=1;
	
	scanf("%lld%lld",&a1,&a2);
	
	if(a1>a2){
		t=a1;
		a1=a2;
		a2=t;
	}
	
	if(a1==a2){
		printf("2");
		return 0;
	}
	
	while(true){
	if(a1>a2){
		t=a1;
		a1=a2;
		a2=t;
	}
		if(a1==0){
			break;
		}
		cnt+=a2/abs(a1-a2);
		t=a2%abs(a1-a2);
		a2=abs(a1-a2);
		a1=t;
	}
	
	printf("%lld",cnt);
	
	return 0;
}
