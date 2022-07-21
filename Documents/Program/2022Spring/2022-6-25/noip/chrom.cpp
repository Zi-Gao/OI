/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
#define file
using namespace std;
inline int read();
bool isPrime(int in){
    int sqrt_max=sqrt(in);
    for(int i=3;i<=sqrt_max;i++){
        if(in%i==0){
            return false;
        }
    }
    return true;
}
int main(){
	#ifdef file
	freopen("chrom.in", "r", stdin);
	freopen("chrom.out", "w", stdout);
	#endif

    int T=read();
    int n;

    while(T--){
        n=read();
        if(n<=1){
            puts("-1");
        }else if(isPrime(n)){
            puts("1");
        }else if(n|1){
            puts("3");
        }else if(n>2){
            puts("2");
        }else{
            puts("1");
        }
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
