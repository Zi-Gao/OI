/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();
char arr[20000][100000];
int main(){
	#ifdef file
	freopen("rain.in", "r", stdin);
	freopen("rain.out", "w", stdout);
	#endif

	int n=0,t;
	
	//read
	while(~scanf("%d",&t)){
//		for(int i=0)
//		n++;
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
