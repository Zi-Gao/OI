#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
//#include <algorithm>
using namespace std;

inline int read();

inline unsigned long long ln(unsigned long long __n){
	return 63 - __builtin_clzll(__n);
}

int main(){
//	freopen("name.in","r",stdin);
//	freopen("name.out","w",stdout);
	
	printf("%d",ln(1024));
	
	return 0;
}

inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();
	while(c>='0'&&c<='0'){
		x=(x<<3)+(x<<1)+(c&15);
	}
	return x*f;
}
