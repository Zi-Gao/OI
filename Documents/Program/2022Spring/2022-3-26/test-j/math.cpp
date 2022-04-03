/***
 * @Author: Zi_Gao
<<<<<<< HEAD
=======
 * @Date: 2022-03-27 07:57:19
 * @LastEditTime: 2022-03-27 08:05:52
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
>>>>>>> 3b157d38ba867a706715fa80dd93fa5cd365725f
 * @Description: 
 */
#include <cstdio>
#define int long long
// #define file
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
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
	#endif

	int t=read();
	while(t){
		int x=read();
		int z=read();
		int max=z/x;
		int flag=true;
		

		for(int i=1;i<=x;++i){
			int y=max/i;
//			if(x==11){
//				printf("YYY%d ",gcd(x,y));
//			}
			if(y*gcd(x,y)==max){
				printf("%d\n",y);
				flag=false;
				break;
			}
		}
		if(flag){
			printf("-1\n");
		}
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
