/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
#define read(a) {int x=0;char f=1;char c=getchar();while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c&15);c=getchar();}a=x*f;}
using namespace std;
int main(){
	#ifdef file
	freopen("discuss.in", "r", stdin);
	freopen("discuss.out", "w", stdout);
	#endif
	
	
		
	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
