#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=100000000;

inline int read();

inline int maxa(int a,int b){
	if(a>b)return a;
	return b;
}

int main(){
//	freopen("name.in","r",stdin);
//	freopen("name.out","w",stdout);
	
	int a=0;
	
	for(int i=0;i<MAX;i++) a=max(a,i);
	
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
