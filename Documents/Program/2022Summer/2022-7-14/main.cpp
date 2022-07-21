#include <cstdio>
using namespace std;
inline int read();

int main(){
//	freopen("name.in","r",stdin);
//	freopen("name.out","w",stdout);

	

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
