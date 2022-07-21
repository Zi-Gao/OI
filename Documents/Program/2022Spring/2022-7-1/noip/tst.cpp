#include <cstdio>
#include <bitset>
using namespace std;


long long abs(long long in){
	return in>=0?in:-in;
}

bitset<536870912> book;

int main(){
//	freopen("seq.in","r",stdin);
//	freopen("seq.out","w",stdout);
	
	long long a1,a2,t;
	
	scanf("%lld%lld",&a1,&a2);


	book[a1]=1;
	book[a2]=1;
	
	while(true){
		if(t==0){
			break;
		}

		t=abs(a1-a2);
		a1=a2;
		a2=t;
//		printf("%lld ",t);
		book[t]=1;
	}
	
	printf("%d",book.count());
	
	return 0;
}
