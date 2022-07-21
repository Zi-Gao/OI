/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
char FBT[1048576+10];
int main(){
	#ifdef file
	freopen("drop.in", "r", stdin);
	freopen("drop.out", "w", stdout);
	#endif
	
	int d=read();
	int l=read();
	int now;
	
	int max=(1<<d);
	
//	printf("%d",max);
	
	for(int i=0;i<l;i++){
		now=1;
		while(now<max)
			if(FBT[now]==0){
				FBT[now]=1;
				now=now<<1;
			}else{
				FBT[now]=0;
				now=(now<<1)+1;
			}
//		printf("%d\n",now>>1);
	}
	
	printf("%d",now>>1);

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
