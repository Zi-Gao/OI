/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
//#define file
using namespace std;
inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	double a,b,c,p;
	
	scanf("%lf %lf %lf",&a,&b,&c);
	
	p=(a+b+c)/2;
	
	printf("%.1lf",sqrt(p*(p-a)*(p-b)*(p-c)));

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
