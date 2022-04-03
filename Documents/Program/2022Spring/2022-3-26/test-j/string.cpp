/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <deque>
#define int long long
#define file
using namespace std;
inline int read();
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

signed main(){
	#ifdef file
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	#endif

	int t=read();
	while(t){
		putchar('0');
		putchar('\n');
		--t;
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
