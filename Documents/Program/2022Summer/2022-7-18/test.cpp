/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
//using namespace std;
#define mx(a,b)\
if((a)>(b))\
a
//#define file
inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

//	for(int i=0;i<100000000;i++){
//		i++;
//		i--;
//	}
	
//	for(int i=0;i<100000000;++i){
//		i++;
//		i--;
//	}

//	for(register int i=0;i<100000000;i++){
//		i++;
//		i--;
//	}

//	register int i;
//	for(i=0;i<100000000;++i){
//		i++;
//		i--;
//	}

	int a;
	register int i;
	for(i=0;i<100000000;++i){
		a=std::max(a,i);
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
