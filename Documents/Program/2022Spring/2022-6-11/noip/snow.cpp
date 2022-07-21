/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#define file
using namespace std;
inline int read();
int main(){
	#ifdef file
	freopen("snow.in", "r", stdin);
	freopen("snow.out", "w", stdout);
	#endif

	read();
	read();
	
	long long int x1,x2,y1,y2;
	long double cnt=0;
	
	while(~scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2)){
		cnt+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/10000;
	}

//	cnt=cnt*6/1000+0.5;
//	cnt*=6;
	
//	long long out=cnt*6/1000;
	
	int h=floor(cnt);
	
	int m=(cnt-h*1.0)*60.0+0.5;
	
	printf("%d:",h);
	
	if(m<10){
		putchar('0');
	}
	
	printf("%d",m);

//	printf("%lld:%lld",out/60,out%60);

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
